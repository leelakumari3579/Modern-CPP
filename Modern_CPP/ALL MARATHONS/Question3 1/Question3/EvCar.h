#ifndef EVCAR_H
#define EVCAR_H
#include"ElectricVehicle.h"
#include"ChargingType.h"
#include <ostream>

class EvCar : public ElectricVehicle
{
private:

    float _battery_capacity;
    ChargingType _chargingType;

public:

    EvCar(float battery_capacity,ChargingType chargingType,ElectricVehicleType type,float price,int seat_count,int engine_horsepower);

    EvCar() =delete;
    EvCar(const EvCar&)=delete;
    EvCar(EvCar&&)=delete;
    EvCar& operator=(const EvCar&)=delete;
    EvCar& operator=(EvCar&&)=delete;
    ~EvCar()=default;

    float batteryCapacity() const { return _battery_capacity; }
    void setBatteryCapacity(float battery_capacity) { _battery_capacity = battery_capacity; }

    ChargingType chargingType() const { return _chargingType; }
    void setChargingType(const ChargingType &chargingType) { _chargingType = chargingType; }

    float CalculateGst(); 

    float CalculateExchangeAmount(); 

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
    

};

#endif // EVCAR_H
