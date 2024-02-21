#include "Car.h"
#include<iostream>

Car::Car(float carPrice, std::string carModel, CarType carType, int carSeatCount)
:_carPrice(carPrice),_carType(carType),_carSeatCount(carSeatCount)
{
}
float Car::operator+(const Car & other)
{
    return _carPrice+other._carPrice;
}
std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "_carPrice: " << rhs._carPrice<<"\n"
       << " _carModel: " << rhs._carModel<<"\n"
       << " _carSeatCount: " << rhs._carSeatCount;

     if(rhs._carType==CarType::PRIVATE_CAR)
     {
        std::cout<<"CarType::PRIVATE_CAR"<<"\n";
     } 
     else if(rhs._carType==CarType::TOURIST_PERMIT_CAR)
     {
        std::cout<<"CarType::TOURIST_PERMIT_CAR"<<"\n";
     }   
    return os;
}
