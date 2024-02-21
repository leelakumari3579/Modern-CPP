#include "ElectricVehicle.h"
std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs) {
    os << "_id: " << rhs._id
       << " _type: " << (int) rhs._type
       << " _price: " << rhs._price
       << " _seat_count: " << rhs._seat_count
       << " _engine_horsepower: " << rhs._engine_horsepower;
    return os;
}
ElectricVehicle::ElectricVehicle(int id, ElectricType type, float price, int seat_count, int engine_horsepower)
:_id(id),_type(type),_price(price),_seat_count(seat_count),_engine_horsepower(engine_horsepower)
{
}
