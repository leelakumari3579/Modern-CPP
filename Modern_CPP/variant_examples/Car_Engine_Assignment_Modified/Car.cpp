#include "Car.h"

Car::Car(std::string carId, std::string carBrand, CarType carType, RefType carEngine, float carPrice)
    : _carId(carId),_carBrand(carBrand),_carType(carType),_carEngine(carEngine),_carPrice(carPrice)
{
}

std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    // TODO: insert return statement here
    os << "_carId: " << rhs._carId
       << "_carBrand: " << rhs._carBrand
       << "_carType: " << static_cast<int>(rhs._carType)
       << "carPrice: " << rhs._carPrice
       << "_carEngine: " << rhs._carEngine.get();
    return os;
}