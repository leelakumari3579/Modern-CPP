#include "Room.h"

Room::Room(float area, float price, RoomType roomtype)
:_area(area),_price(price),_roomtype(roomtype)
{
}
float Room::CalculateTaxAmount()
{
    if(_roomtype==RoomType::DELUXE || _roomtype==RoomType::MAPLE){
        return 0.1*_price;
    }
       return.15*_price;
    
}
std::ostream &operator<<(std::ostream &os, const Room &rhs)
{
    os << "_area: " << rhs._area
       << " _price: " << rhs._price
       << " _roomtype: " ;
       switch (rhs.roomtype())
       {
       case RoomType::DELUXE:
        std::cout<<"RoomType::DELUXE"<<std::endl;
        break;
       case RoomType::LUXURY:
            std::cout<<"RoomType::LUXURY"<<std::endl;
            break;
        case RoomType::MAPLE:
        std::cout<<"RoomType::MAPLE"<<std::endl;
        break;
       }
       os<<"\n";
    return os;
}
