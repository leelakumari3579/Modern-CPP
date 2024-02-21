#include "ICEngineCar.h"
#include"NoMatchInstanceException.h"

ICEngineCar::ICEngineCar(float carPrice, std::string carModel, CarType carType, int carSeatCount, float fuelCapacity, FuelType fuelType)
:Car(carPrice,carModel,carType,carSeatCount),_fuelCapacity(fuelCapacity),_fuelType(fuelType)
{
}

float ICEngineCar::CalculateInsuranceCost()
{
    if(_fuelType==FuelType::PETROL)
    {
        return 1000*_fuelCapacity;
    }
    else if(_fuelType==FuelType::DIESEL)
    {
        return 1500*_fuelCapacity;
    }
    return 12*_fuelCapacity;
}

float ICEngineCar::CalculateServicingCost()
{
    if(_fuelType==FuelType::PETROL)
    {
        return 100*_fuelCapacity;
    }
    else if(_fuelType==FuelType::DIESEL)
    {
        return 150*_fuelCapacity;
    }
    else if(_fuelType==FuelType::CNG && _carSeatCount<6)
    {
        return 100*_fuelCapacity;
    }
    else if(_fuelType==FuelType::CNG && _carSeatCount>5)
    {
        return 120*_fuelCapacity;
    }
    throw NoMatchInstanceException("No condition satisfies\n");
}
