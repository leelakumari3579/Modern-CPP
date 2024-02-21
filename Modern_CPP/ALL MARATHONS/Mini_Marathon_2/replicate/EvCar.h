#ifndef EVCAR_H
#define EVCAR_H

#include "Car.h"
#include <ostream>

class EvCar : public Car
{
private:
    float _batteryCapacity;

public:
    EvCar()=delete;
    EvCar(const EvCar&)=delete;
    EvCar(const EvCar&&)=delete;
    EvCar& operator=(const EvCar&)=delete;
    EvCar& operator=(EvCar&&) =delete;
    ~EvCar()=default;

    //para with car

    EvCar(float carPrice,std::string carModel,CarType carType,int carSeatCount,int batteryCapacity);

    float batteryCapacity() const { return _batteryCapacity; }
    void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }

    //override
    float CalculateInsuranceCost() override;

    //special

    float CalculateFastCahrgingCost();

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);


};




#endif // EVCAR_H
