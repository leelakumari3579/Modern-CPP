#include<iostream>
#include"Functionalities.h"
#include"Car.h"

int main()
{
    Container carData;
    CreateObjects(carData);
    std::cout<<" Car Instance with Matching Id"<<std::endl;
    try
    {
        // Vector res=SearchCarById(carData,"c101");
        // for(Car& c:res)
        // {
        //     std::cout<<c;
        // }
        SearchCarById(carData,"c101");
    }
    
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout<<"\n Car at Nth Instance"<<std::endl;
    try
    {
        Car res=InstanceAtPositionN(carData,1);
        // for(Car& c:res)
        // {
        //     std::cout<<c;
        // }
        std::cout<<res<<std::endl;
    }
    
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout<<"Average Price of all Instances:"<<std::endl;
    float average=AveragePriceofInstances(carData,PermitType::PRIVATE);
    std::cout<<average<<std::endl;

    
    
}