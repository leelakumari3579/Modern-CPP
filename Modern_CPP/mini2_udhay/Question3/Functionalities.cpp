#include"Functionalities.h"
#include<iostream>

void CreateObjects(Container& data,ContainerPlane& dataPlane)
{
    PlanePointer pp1 = std::make_shared<Plane>("123",PlaneType::JUMBO,56);
    PlanePointer pp2 = std::make_shared<Plane>("456",PlaneType::LUXURY,60);

    dataPlane.emplace_back(pp1);
    dataPlane.emplace_back(pp2);

        auto itr = dataPlane.begin();

    FlightPointer fp1 = std::make_shared<Flight>(123,34000.0f,std::ref(*itr++));
    FlightPointer fp2 = std::make_shared<Flight>(321,40000.0f,std::ref(*itr++));

    data.emplace_back(fp1);
    data.emplace_back(fp2);

}

void MakeLambdaq3(FunContainer& data)
{

    std::function<void(std::list<FlightPointer>&)> fn1 = [](std::list<FlightPointer>& l)->void{

        if(l.empty())
        {
            throw EmptyContainerException("Data is Empty!!!");
        }

         auto itr = l.begin();

        FlightPointer f = *itr;

        std::string planetype; 

            switch(f->plane().get()->type())
            {
                case PlaneType::JUMBO:
                    planetype="JUMBO";
                    break;
                case PlaneType::LUXURY:
                    planetype="LUXURY";
                    break;
            }

        std::cout<<"The Plance Type is "<<planetype<<std::endl;

    };

    std::function<void(std::list<FlightPointer>&)> fn2 = [](std::list<FlightPointer>& l)->void{

        if(l.empty())
        {
            throw EmptyContainerException("Data is Empty!!!");
        }
        int count=0;
        float sum =  0.0f;

        for(FlightPointer& fptr : l)
        {
            if(fptr->ticketPrice()>400)
            {
                count++;
                sum = sum+fptr->plane().get()->capacity();
            }
        }
        float res = (float)sum/count;
        std::cout<<"the Average Capacity of a Plane is "<<res<<std::endl;

    };

     std::function<void(std::list<FlightPointer>&)> fn3 = [](std::list<FlightPointer>& l)->void{

                if(l.empty())
                {
                    throw EmptyContainerException("Data is Empty!!!");
                }
            
            auto itr = l.begin();
            FlightPointer fptr = *itr;
            int lowduration = fptr->durationMinutes();
            for(FlightPointer& fp : l)
            {
                if(lowduration>fp->durationMinutes())
                {
                    lowduration = fp->durationMinutes();
                }
            }

            for(FlightPointer& fp : l)
            {
                if(lowduration==fp->durationMinutes())
                {
                    std::cout<<*fp<<std::endl;
                    break;
                }
            }

     };

     data.push_back(fn1);
     data.push_back(fn2);
     data.push_back(fn3);

}

void Operation(Container& VecFpointer,FunContainer& VecFun)
{
        if(VecFpointer.empty()||VecFun.empty())
        {
            throw EmptyContainerException("Data is Empty!!!");
        }

        for(auto fn : VecFun)
        {   
            try{
        std::cout<<"------------------------------------"<<std::endl;
            fn(VecFpointer);
        std::cout<<"------------------------------------"<<std::endl;
            }
            catch(EmptyContainerException& empt)
            {
                std::cout<<empt.what()<<std::endl;
            }
        }

}