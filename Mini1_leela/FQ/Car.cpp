#include "Car.h"

Car::Car(std::string id, float price, ChassisType chassisType, PermitType permitType)
    :_id(id), _price(price), _chassisType(chassisType), _permitType(permitType)
{
}

float Car::CalculateDiscount()
{ 
    float ans=0.0f;
    if(permitType() == PermitType::TOURIST)
    {
        ans= _price * 0.1f;
    }
    else if(permitType() == PermitType::PRIVATE)
    {
        ans= _price * 0.15f;
    }
    return ans;
}

float Car::operator+(Car &car1)
{
    // TODO: insert return statement here
    float totalPrice = _price;
    totalPrice = this->_price+car1._price;
    return totalPrice;
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _chassisType: " << static_cast<int>(rhs._chassisType)
       << " _permitType: " << static_cast<int>(rhs._permitType);
    return os;
}