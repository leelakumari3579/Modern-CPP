#ifndef EV2WHEELER_H
#define EV2WHEELER_H
#include"ElectricVehicle.h"
#include"ConnectedTechType.h"
#include <ostream>

class Ev2Wheeler : public ElectricVehicle
{
private:

    float _battery_capacity;
    ConnectedTechType _connectedTechType;

public:

    Ev2Wheeler(float battery_capacity,ConnectedTechType connectedTechType,ElectricVehicleType type,float price,int seat_count,int engine_horsepower);

    Ev2Wheeler() =delete;
    Ev2Wheeler(const Ev2Wheeler&)=delete;
    Ev2Wheeler(Ev2Wheeler&&)=delete;
    Ev2Wheeler& operator=(const Ev2Wheeler&)=delete;
    Ev2Wheeler& operator=(Ev2Wheeler&&)=delete;
    ~Ev2Wheeler()=default;

    float batteryCapacity() const { return _battery_capacity; }
    void setBatteryCapacity(float battery_capacity) { _battery_capacity = battery_capacity; }

    ConnectedTechType connectedTechType() const { return _connectedTechType; }
    void setConnectedTechType(const ConnectedTechType &connectedTechType) { _connectedTechType = connectedTechType; }  

    float CalculateGst();

    float CalculateExchangeAmount();

    friend std::ostream &operator<<(std::ostream &os, const Ev2Wheeler &rhs);

};


#endif // EV2WHEELER_H
