#include"Functionalities.h"
#include<iostream>
#include<memory>
#include<stdexcept>
#include"Car.h"
       

void CreateObjects(Container &carData)
{
    carData.emplace_back(
        std::make_shared<Car>("c101",890000.0f,ChassisType::EV,PermitType::PRIVATE)
    );

    carData.emplace_back(
        std::make_shared<Car>("c101",890000.0f,ChassisType::EV,PermitType::PRIVATE)
    );

    carData.emplace_back(
        std::make_shared<Car>("c101",890000.0f,ChassisType::EV,PermitType::PRIVATE)
    );
}

Car InstanceAtPositionN(Container &carData, int n)
{

    if(carData.empty())
    {
        throw std::runtime_error("Car Data is Empty");
    }
    // Vector result;
    // for(CarPointer& car:carData)
    // {
    //      result.emplace_back(*carData[n]);
    // }
    // return result;
    
    return *carData[n];

}
    


void SearchCarById(Container &carData, std::string id)
{
    if(carData.empty())
    {
        throw std::runtime_error("Car Data is Empty");
    }
    
    //Vector result;
    for(CarPointer& car:carData)
    {
        if(car->id()!=id)
        {
            throw std::runtime_error("Car Id is not matching");
        }
        //result.emplace_back(*car);
        std::cout<<*car<<std::endl;
    }
}   

float AveragePriceofInstances(Container &carData, PermitType ptype)
{
    if(carData.empty())
    {
        throw std::runtime_error("Car Data is Empty");
    }
    
    float avg=0.0f;
    for(CarPointer& car:carData)
    {
        if(car->chassisType()!=ChassisType::EV  && car->permitType()!=ptype)
        {
            throw std::runtime_error("CarType and PermitType are not matching with given");
        }

        else{
            avg=avg+car->price();
        }
        avg=avg/carData.size();  
    }
    return avg;
    
    
}
