#include "Car.h"

Car::Car(std::string id):_id(id), _type(VehicleType::HATCHBACK), _price(0.0f)
{
}

Car::Car(std::string id, VehicleType type):Car(id)
{
    _type = type;
    _price = 0.0f;
}

Car::Car(std::string id, float price, VehicleType type):Car(id,type)
{
    _price = price;
}



//delegated constructors or constructor delegation
