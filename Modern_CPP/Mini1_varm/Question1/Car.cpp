#include "Car.h"
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _chasisType: ";
    switch (rhs._chasisType)
    {
    case ChasisType::EV:
        os<<"ChasisType::EV";
        break;
    case ChasisType::ICE:
        os<<"ChasisType::ICE";
        break;
    }
    switch (rhs._permitType)
    {
    case PermitType::PRIVATE:
        os<<"PermitType::PRIVATE";
        break;
    case PermitType::TOURIST:
        os<<"PermitType::TOURIST";
        break;
    }
    os<<"\n";
    return os;
}

Car::Car(std::string id, float price, ChasisType chasisType, PermitType permitType)
:_id(id),_price(price),_chasisType(chasisType),_permitType(permitType)
{
}
/*Based on Permit Type*/
float Car::calculateCarDiscount()
{   
    if(_permitType==PermitType::PRIVATE){
        return 0.15*_price;
    }
    return 0.1*_price; // Tourist
}
/* Car opertaor +*/
float Car::operator+(const Car &car)
{
    return this->_price+car.price();
   
}
