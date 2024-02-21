#include "Car.h"

Car::Car(std::string id, float price, ChassisType chassisType, PermitType permitType)
:_id(id),_price(price),_chassisType(chassisType),_permitType(permitType)
{
}

float Car::calculateDiscount(PermitType ptype)
{
    if(_permitType==PermitType::TOURIST)
    {
        return 0.1 * _price;
    }
    return 1.5 * _price;
}


float Car::operator+(const Car &c)
{
  return this->_price+c.price();

}

std::ostream &operator<<(std::ostream &os, const Car &c) {
    os << "Car _id: " << c._id
       << " Car _price: " << c._price
       << " _chassisType: " <<static_cast<int>(c._chassisType)
       << " _permitType: " << static_cast<int>(c._permitType);
    return os;
}

