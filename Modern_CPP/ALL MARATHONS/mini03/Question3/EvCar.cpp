#include "EvCar.h"

EvCar::EvCar(int id, ElectricType type, float price, int seat_count, int engine_horsepower,float battery_capacity, ChargingType chargingType)
:ElectricVehicle(id,type,price,seat_count,engine_horsepower),_battery_capacity(battery_capacity),_chargingType(chargingType)
{

}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << static_cast<const ElectricVehicle &>(rhs)
       << " _battery_capacity: " << rhs._battery_capacity
       << " _chargingType: " << (int)rhs._chargingType;
    return os;
}

float EvCar::CalculateGst()
{
    return 0.0f;
}

float EvCar::CalculateExchangeAmount()
{
    return 0.0f;
}
