#include "ElectricVehicle.h"
std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs) {
    os << "_id: " << rhs._id
       << " _type: " <<static_cast<int>(rhs._type)
       << " _price: " << rhs._price
       << " _seat_count: " << rhs._seat_count
       << " _engine_horsepower: " << rhs._engine_horsepower;
    return os;
}

int ElectricVehicle::counter=1000;

ElectricVehicle::ElectricVehicle(VehicleType type, float price, int seatCount, int engineHorsePower)
:_id(counter++),_type(type),_price(price),_seat_count(seatCount),_engine_horsepower(engineHorsePower)
{
}
