#include "EvCar.h"
std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << static_cast<const ElectricVehicle &>(rhs)
       << " _battery_capacity: " << rhs._battery_capacity
       << " _chargingType: " <<static_cast<int>(rhs._chargingType);
    return os;
}
EvCar::EvCar(VehicleType type, float price, int seatCount, int engineHorsePower, float batterCapacity, ChargingType chargingType)
:ElectricVehicle(type,price,seatCount,engineHorsePower),_battery_capacity(batterCapacity),_chargingType(chargingType)
{
}

float EvCar::CalculateGst()
{
    return price()*5/100;
}

float EvCar::CalculateExchangeAmount()
{
    if(type()==VehicleType::REGULAR)
    {
        return price()*60/100;
    }
    if(type()==VehicleType::TRANSPORT && (_chargingType==ChargingType::AC ||_chargingType==ChargingType::DC_FAST_CHARGE))
    {
        return price()*60/100;
    }
    return price()*75/100;
    
}
