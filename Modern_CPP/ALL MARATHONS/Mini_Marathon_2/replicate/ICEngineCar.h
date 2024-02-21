#ifndef ICENGINECAR_H
#define ICENGINECAR_H

#include "FuelType.h"
#include"Car.h"
#include <ostream>

class ICEngineCar: public Car
{
private:
    float _fuelCapacity;
    FuelType _fType;
    
public:
    ICEngineCar() =delete;
    ICEngineCar(const ICEngineCar&)=default;
    ICEngineCar(ICEngineCar&&)=delete;
    ICEngineCar& operator=(const ICEngineCar&)=delete;
    ICEngineCar& operator=(ICEngineCar&&)=delete;
    ~ICEngineCar() =default;

    ICEngineCar(float carPrice,std::string carModel,CarType cType,int carSeatCount,float fuelCapacity,FuelType fType);

    float CalculateInsuranceCost() override;

    float CalculateServicingCost();

    float fuelCapacity() const { return _fuelCapacity; }
    void setFuelCapacity(float fuelCapacity) { _fuelCapacity = fuelCapacity; }

    FuelType fType() const { return _fType; }
    void setFType(const FuelType &fType) { _fType = fType; }

    friend std::ostream &operator<<(std::ostream &os, const ICEngineCar &rhs);
};


#endif // ICENGINECAR_H
