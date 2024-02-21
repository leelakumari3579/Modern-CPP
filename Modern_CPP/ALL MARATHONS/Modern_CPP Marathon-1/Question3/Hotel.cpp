 #include "Hotel.h"

Hotel::Hotel(std::string name, const unsigned int location_code, RoomPointer room, CategoryType category)
:_name(name),_location_code(location_code),_room(room),_category(category)
{
}
std::ostream &operator<<(std::ostream &os, const Hotel &rhs) {
    os << "_name: " << rhs._name
       << " _location_code: " << rhs._location_code
       << " _room: " << rhs._room
       << " _category: ";
       switch(rhs._category)
       {
            case CategoryType::MOTEL:
               os<<"CategoryType::MOTEL"<<std::endl;
               break;
            case CategoryType::PREMIUM:
                os<<"CategoryType::PREMIUM"<<std::endl;
                break;
            case CategoryType::STAY:
                os<<"CategoryType::STAY"<<std::endl;
                break;
       }
       os<<"\n";
    return os;
}
