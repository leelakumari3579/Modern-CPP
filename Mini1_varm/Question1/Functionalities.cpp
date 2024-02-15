#include "Functionalities.h"

void CreateObjects(CarContainer &CarData)
{
    /* In question , no mention of user input*/
    CarData.emplace_back(std::make_shared<Car>("Car1",200000,ChasisType::EV,PermitType::PRIVATE));
    CarData.emplace_back(std::make_shared<Car>("Car2",30000.0f,ChasisType::ICE,PermitType::PRIVATE));
    CarData.emplace_back(std::make_shared<Car>("Car3",400000.0f,ChasisType::EV,PermitType::TOURIST));
}

Car FindNthCar(const CarContainer &CarData, int index)
{   
    if(CarData.empty()){
        throw NoCarAvailable("Sorry There are no cars Available !!!");
    }
    if(index<0){
        throw NoCarAvailable("Sorry You entered Negative Index of Cars Not Available");
    }
    if(CarData.size()<=index){
        throw NOCarFoundExeception("The car is Not found for your given Index!!!!");
    }

    return *CarData[index];
}

void DisplayCarById(const CarContainer &CarData, std::string carId)
{
    if(CarData.empty()){
        throw NoCarAvailable("Sorry There are no cars Available !!!");
    }
    bool isFound=false;   
    for(auto& car:CarData){
        if(carId==car->id()) {
            isFound=true;
            std::cout<<*car<<std::endl;
            break;
        }
    }
    if(!isFound){
        throw NOCarFoundExeception("The car is Not found for your given CarID  !!!!");
    }
}

float findAverage_price(const CarContainer &CarData, PermitType ptype)
{
    if(CarData.empty()){
        throw NoCarAvailable("Sorry There are no cars Available !!!");
    }
    float avg=0.0f;
    int freq=0;
    for(auto& car:CarData){
        if(car->chasisType()==ChasisType::EV && ptype==car->permitType()){
            avg+=car->price();
            freq++;
        }
    }
    if(freq==0){
        throw NOCarFoundExeception("The car is Not found for your given PemitType !!!!");
    }
    return avg/freq;
}
