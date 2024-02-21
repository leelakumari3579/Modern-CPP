#include "ICEngineCar.h"
ICEngineCar:: ICEngineCar(float carPrice,std::string carModel,CarType cType,int carSeatCount,float fuelCapacity,FuelType fType)
:Car(carPrice,carModel,cType,carSeatCount)
{
  _fuelCapacity=fuelCapacity;
  _fType=fType;
}

std::ostream &operator<<(std::ostream &os, const ICEngineCar &rhs) {
    os << static_cast<const Car &>(rhs)
       << " _fuelCapacity: " << rhs._fuelCapacity
       << " _fType: " <<static_cast<int>( rhs._fType);
    return os;
}

float ICEngineCar::CalculateInsuranceCost()
{
    if(_fType==FuelType::PETROL)
    {
        return 1000*_fuelCapacity;
    }
    else if(_fType==FuelType::DIESEL)
    {
        return 1500*_fuelCapacity;
    }
    return 12*_fuelCapacity;
}

float ICEngineCar::CalculateServicingCost()
{
    if(_fType==FuelType::PETROL)
    {
        return 100*_fuelCapacity;
    }
    else if(_fType==FuelType::DIESEL)
    {
        return 150*_fuelCapacity;
    }
    else if(_fType==FuelType::CNG && _carSeatCount<6)
    {
        return 100*_fuelCapacity;
    }
    else if(_fType==FuelType::CNG && _carSeatCount>5)
    {
        return 120*_fuelCapacity;
    }
    throw std::runtime_error("No condition satisfies\n");
}
