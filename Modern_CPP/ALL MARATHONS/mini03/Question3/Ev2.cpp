#include "Ev2.h"



std::ostream &operator<<(std::ostream &os, const Ev2 &rhs) {
    os << static_cast<const ElectricVehicle &>(rhs)
       << " _battery_capacity: " << rhs._battery_capacity
       << " _connectedType: " << (int)rhs._connectedType;
    return os;
}

Ev2::Ev2(int id, ElectricType type, float price, int seat_count, int engine_horsepower, float battery_capacity, ConnectedType connectedType)
:ElectricVehicle(id,type,price,seat_count,engine_horsepower),_battery_capacity(battery_capacity),_connectedType(connectedType)
{
}

float Ev2::CalculateGst()
{
    return 0.0f;
}

float Ev2::CalculateExchangeAmount()
{
    return 0.0f;
}
