#ifndef ICENGINECAR_H
#define ICENGINECAR_H

#include"Car.h"
#include"FuelType.h"
class ICEngineCar: public Car
{
private:
    float _fuelCapacity;
    FuelType _fuelType;
public:
    ICEngineCar()=delete;
    ICEngineCar(const ICEngineCar&)=default;
    ICEngineCar(ICEngineCar&&)=delete;
    ICEngineCar& operator=(const ICEngineCar&)=delete;
    ICEngineCar& operator=(ICEngineCar&&)=delete;
    ~ICEngineCar()=default;

    ICEngineCar(float carPrice,std::string carModel,CarType carType,int carSeatCount,float fuelCapacity,FuelType fuelType);

    float CalculateInsuranceCost() override;

    float CalculateServicingCost();

    float fuelCapacity() const { return _fuelCapacity; }
    void setFuelCapacity(float fuelCapacity) { _fuelCapacity = fuelCapacity; }

    FuelType fuelType() const { return _fuelType; }
    void setFuelType(const FuelType &fuelType) { _fuelType = fuelType; }
};

#endif // ICENGINECAR_H
