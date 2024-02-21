#ifndef EVCAR_H
#define EVCAR_H

#include"ElectricVehicle.h"
#include"ChargingType.h"
#include <ostream>

class EvCar:public ElectricVehicle
{
private:
    float _battery_capacity;
    ChargingType _chargingType;
public:
    EvCar()=delete;
    EvCar(const EvCar&)=delete;
    EvCar(EvCar&&)=delete;
    EvCar& operator=(EvCar&&)=delete;
    EvCar& operator=(const EvCar&)=delete;
    ~EvCar()=default;

    EvCar(VehicleType type,float price,int seatCount,int engineHorsePower,float batterCapacity,ChargingType chargingType);
 
    float CalculateGst();
    float CalculateExchangeAmount();

    float batteryCapacity() const { return _battery_capacity; }
    ChargingType chargingType() const { return _chargingType; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
    

};

#endif // EVCAR_H
