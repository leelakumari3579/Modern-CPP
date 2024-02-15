#include "Ev2Wheeler.h"
std::ostream &operator<<(std::ostream &os, const Ev2Wheeler &rhs) {
    os << static_cast<const ElectricVehicle &>(rhs)
       << " _battery_capacity: " << rhs._battery_capacity
       << " _connectedTechType: " <<static_cast<int>( rhs._connectedTechType);
    return os;
}
Ev2Wheeler::Ev2Wheeler(VehicleType type, float price, int seatCount, int engineHorsePower, float batterCapacity, ConnectedTechType cTechType)
:ElectricVehicle(type,price,seatCount,engineHorsePower),_battery_capacity(batterCapacity),_connectedTechType(cTechType)
{
}

float Ev2Wheeler::CalculateGst()
{
    return price()*10/100;
}

float Ev2Wheeler::CalculateExchangeAmount()
{
    return price()*32/100;
}
