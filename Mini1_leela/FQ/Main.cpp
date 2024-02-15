#include <iostream>
#include "Functionalities.h"

int main()
{
    CarPointerContainer carData;

    CreateObjects(carData);

    try
    {
        std::vector<Car> res = FindInstanceByN(carData,2);  
        for(Car& ele : res)
        {
            std::cout<<"Car instances based on given data: "<<ele<<std::endl;
        }  
    }
    catch(const char* msg)
    {
        std::cout << msg << '\n';
    }

    try
    {
        std::vector<Car> res = FindAttributesById(carData,"v101ef");  
        for(Car& ele : res)
        {
            std::cout<<"Car instances based on given carId: "<<ele<<std::endl;
        }  
    }
    catch(const char* msg)
    {
        std::cout << msg << '\n';
    }

    try
    {
        float res = FindAveragePrice(carData,PermitType::PRIVATE);  
            std::cout<<"Average price bsed on permit type and chassis type: "<<res<<std::endl; 
    }
    catch(const char* msg)
    {
        std::cout <<msg << '\n';
    }
}