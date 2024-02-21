#ifndef EV2WHEELER_H
#define EV2WHEELER_H

#include"ElectricVehicle.h"
#include"ConnectedTechType.h"
#include <ostream>
class Ev2Wheeler:public ElectricVehicle
{
private:
    float _battery_capacity;
    ConnectedTechType _connectedTechType;
public:
    Ev2Wheeler()=delete;
    Ev2Wheeler(const Ev2Wheeler&)=delete;
    Ev2Wheeler(Ev2Wheeler&&)=delete;
    Ev2Wheeler& operator=(Ev2Wheeler&&)=delete;
    Ev2Wheeler& operator=(const Ev2Wheeler&)=delete;
    ~Ev2Wheeler()=default;

    Ev2Wheeler(VehicleType type,float price,int seatCount,int engineHorsePower,float batterCapacity,ConnectedTechType cTechType);
 
    float CalculateGst();
    float CalculateExchangeAmount();

    float batteryCapacity() const { return _battery_capacity; }
    ConnectedTechType connectedTechType() const { return _connectedTechType; }

    friend std::ostream &operator<<(std::ostream &os, const Ev2Wheeler &rhs);
};

#endif // EV2WHEELER_H
