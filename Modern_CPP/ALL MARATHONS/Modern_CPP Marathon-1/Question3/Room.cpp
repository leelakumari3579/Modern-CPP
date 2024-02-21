#include "Room.h"

Room::Room(float area, float price, RoomType roomtype)
:_area(area),_price(price),_roomtype(roomtype)
{}
std::ostream &operator<<(std::ostream &os, const Room &rhs) {
    os << "_area: " << rhs._area
       << " _price: " << rhs._price
       << " _roomType: ";
    switch (rhs.roomtype())
       {
       case RoomType::DELUXE:
        os<<"RoomType::DELUXE"<<std::endl;
        break;
       case RoomType::LUXURY:
            os<<"RoomType::LUXURY"<<std::endl;
            break;
        case RoomType::MAPLE:
        os<<"RoomType::MAPLE"<<std::endl;
        break;
       }
       os<<"\n";
    return os;
}

float Room::calculateTaxAmount()
{
    if(_roomtype==RoomType::DELUXE || _roomtype==RoomType::MAPLE){
        return 0.1*_price;
    }
       return.15*_price;
}