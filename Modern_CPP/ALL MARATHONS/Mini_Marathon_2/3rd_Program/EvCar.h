#ifndef EVCAR_H
#define EVCAR_H

#include"Car.h"
#include <ostream>
class EvCar:public Car
{
private:
    float _batteryCapacity;
public:
    EvCar()=delete;
    EvCar(const EvCar&)=default;
    EvCar(EvCar&&)=delete;
    EvCar& operator=(const EvCar&)=delete;
    EvCar& operator=(EvCar&&)=delete;
    ~EvCar()=default;

    EvCar(float carPrice,std::string carModel,CarType carType,int carSeatCount,float batteryCapacity);

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);

    float CalculateInsuranceCost() override;

    float CalculateFastChargingCost();

    float batteryCapacity() const { return _batteryCapacity; }
    void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }

    

    
};

#endif // EVCAR_H
