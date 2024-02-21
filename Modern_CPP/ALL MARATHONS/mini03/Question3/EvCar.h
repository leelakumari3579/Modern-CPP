#ifndef EVCAR_H
#define EVCAR_H
#include "ElectricVehicle.h"
#include "ChargingType.h"
#include <ostream>
class EvCar:public ElectricVehicle
{
private:
    float _battery_capacity;
    ChargingType _chargingType;

public:
    EvCar()=default;
    EvCar(const EvCar&)=delete;
    EvCar(EvCar&&)=delete;
    EvCar& operator=(const EvCar&)=delete;
    EvCar& operator=(EvCar&&)=delete;
    ~EvCar()=default;

    EvCar(int id, ElectricType type, float price, int seat_count, int engine_horsepower,float battery_capacity,ChargingType chargingType);
    float batteryCapacity() const { return _battery_capacity; }
     float CalculateGst() override;
     float  CalculateExchangeAmount() override;

     friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_H
