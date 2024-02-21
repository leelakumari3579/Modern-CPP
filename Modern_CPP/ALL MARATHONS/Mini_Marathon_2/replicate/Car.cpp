#include "Car.h"
#include<iostream>

Car::Car(float carPrice, std::string carModel, CarType cType,int carSeatCount)
:_carPrice{carPrice},_carModel{carModel},_cType{cType},_carSeatCount{carSeatCount}
{
}


std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_carPrice: " << rhs._carPrice
       << " _carModel: " << rhs._carModel
       << " _cType: ";
       if(rhs._cType ==CarType::PRIVATE_CAR){
        std::cout<<"CarType::PRIVATE_CAR\n";
       }
       else if(rhs._cType ==CarType::PRIVATE_CAR){
        std::cout<<"CarType::PRIVATE_CAR\n";
       }
      os << " _carSeatCount: " << rhs._carSeatCount;
    return os;
}


