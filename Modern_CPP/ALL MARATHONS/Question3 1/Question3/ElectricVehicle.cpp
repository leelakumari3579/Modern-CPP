#include "ElectricVehicle.h"


ElectricVehicle::ElectricVehicle(ElectricVehicleType type,float price, int seat_count, int engine_horsepower)
:_id{_counter++},_type{type},_price{price},_seat_count{seat_count},_engine_horsepower{engine_horsepower}
{

}
std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs) {
    os << "_id: " << rhs._id<<std::endl;
  
   std::string typev;
    switch(rhs._type)
    {
        case ElectricVehicleType::REGULAR:
            typev = "REGULAR";
            break;
        case ElectricVehicleType::TRANSPORT:
            typev = "TRANSPORT";
            break;
    }
    os << " _electricVehicleType: " <<typev<<std::endl;
    os << " _price: " << rhs._price<<std::endl;
    os << " _seat_count: " << rhs._seat_count<<std::endl;
    os << " _engine_horsepower: " << rhs._engine_horsepower<<std::endl;
    return os;
}
