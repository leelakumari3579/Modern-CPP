#include "EvCar.h"

EvCar::EvCar(float carPrice, std::string carModel, CarType carType, int carSeatCount, float batteryCapacity)
:Car(carPrice,carModel,carType,carSeatCount),_batteryCapacity(batteryCapacity)
{
}
float EvCar::CalculateInsuranceCost()
{
    if(_carType==CarType::PRIVATE_CAR)
    {
        return 0.2*_carPrice;
    }
    return 0.1*_carPrice;
}
float EvCar::CalculateFastChargingCost()
{
    if(_carType==CarType::PRIVATE_CAR)
    {
        return 0.4*_carPrice;
    }
    return 0.2*_carPrice;
}
std::ostream &operator<<(std::ostream &os, const EvCar &rhs)
{
    os << static_cast<const Car &>(rhs)
       << " _batteryCapacity: " << rhs._batteryCapacity;
    return os;
}
