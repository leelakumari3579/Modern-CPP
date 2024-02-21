#include"Functionalites.h"
#include<iostream>
#include<mutex>
std::mutex mt;
void CreateObjects(Container& data)
{

    Ev2WheelerPointer sp1 = std::make_shared<Ev2Wheeler>(50.0f,ConnectedTechType::DIGITAL,ElectricVehicleType::REGULAR,66000.0f,6,77);

    Ev2WheelerPointer sp2 = std::make_shared<Ev2Wheeler>(60.0f,ConnectedTechType::SMART,ElectricVehicleType::TRANSPORT,76000.0f,8,78);

    Ev2WheelerPointer sp3 = std::make_shared<Ev2Wheeler>(70.0f,ConnectedTechType::NAVIGATION_ONLY,ElectricVehicleType::REGULAR,86000.0f,9,89);

    EvCarPointer sp4 = std::make_shared<EvCar>(33.0f,ChargingType::AC,ElectricVehicleType::TRANSPORT,55000.0f,8,4);

    EvCarPointer sp5 = std::make_shared<EvCar>(33.0f,ChargingType::AC,ElectricVehicleType::TRANSPORT,55000.0f,8,4);

    data.emplace_back(sp1);
    data.emplace_back(sp2);
    data.emplace_back(sp3);
    data.emplace_back(sp4);
    data.emplace_back(sp5);

}

void DisplayAllAttributes(Container& data, std::future<int> &ft)
{       
    if(data.empty())
    {
        throw EmptyContainerException("Data is Empty!!!");
    }

    std::cout<<"This line is loaded before giving parameter\n"<<std::endl;  

    int id = ft.get();
    for(ElectricVehiclePointer evptr : data)
    {
        Ev2WheelerPointer ev2ptr = std::dynamic_pointer_cast<Ev2Wheeler>(evptr);
        if(ev2ptr!=nullptr)
        {
            if(ev2ptr->id() == id)
            {
                std::lock_guard<std::mutex>lk(mt);
                std::cout<<*ev2ptr<<std::endl;
            }
        }
        else{
            EvCarPointer evcarptr = std::dynamic_pointer_cast<EvCar>(evptr);
            if(evcarptr->id()==id)
            {
                 std::lock_guard<std::mutex>lk(mt);
                std::cout<<*evcarptr<<std::endl;
            }
        }
    }

}

void AveragePriceOfAllEvCars(Container& data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is Empty!!!");
    }
    int count=0;
    float sum=0.0f;

    for(ElectricVehiclePointer evptr : data)
    {
        EvCarPointer evcarptr = std::dynamic_pointer_cast<EvCar>(evptr);

        if(evcarptr!=nullptr)
        {
            if(evcarptr->engineHorsepower()<600)
            {
                count++;
                sum = sum + evcarptr->price();
            }
        }

    }

    float avg = (float)sum/count;
     std::lock_guard<std::mutex>lk(mt);
    std::cout<<"The Average of All Instances of EvCars are"<<avg<<std::endl;

}

std::optional<Container> ReturnInstancesOfSmartPointer(Container& data, float threshold)
{       
     if(data.empty())
    {
        throw EmptyContainerException("Data is Empty!!!");
    }

    Container Instances;

        for(ElectricVehiclePointer evptr: data )
        {
            if(evptr->price()>threshold)
            {
                Instances.emplace_back(evptr);
            }
        }

        if(Instances.empty())
        {
            return std::nullopt;
        }

    return Instances;

}


void SumOfTotalGst(Container& data){

     if(data.empty())
    {
        throw EmptyContainerException("Data is Empty!!!");
    }

    float sum=0.0f;

     for(ElectricVehiclePointer evptr : data)
    {
        Ev2WheelerPointer ev2ptr = std::dynamic_pointer_cast<Ev2Wheeler>(evptr);
        if(ev2ptr!=nullptr)
        {
            sum = sum+ev2ptr->CalculateGst();
        }
        else{
            EvCarPointer evcarptr = std::dynamic_pointer_cast<EvCar>(evptr);

            sum = sum+evcarptr->CalculateGst();
            
        }
    }
     std::lock_guard<std::mutex>lk(mt);
    std::cout<<"The Sum of Total Gst is "<<sum<<std::endl;

}

void SumOfExchangeAmountOfEv2Wheeler(Container& data){

      if(data.empty())
    {
        throw EmptyContainerException("Data is Empty!!!");
    }

    float sum=0.0f;

    for(ElectricVehiclePointer evptr : data)
    {
        Ev2WheelerPointer ev2ptr = std::dynamic_pointer_cast<Ev2Wheeler>(evptr);
        if(ev2ptr!=nullptr)
        {
            sum = sum+ev2ptr->CalculateExchangeAmount();
        }
    }
     std::lock_guard<std::mutex>lk(mt);
    std::cout<<"The Sum of CalculateExchangeAmount fun from Ev2Wheeler is "<<sum<<std::endl;
}