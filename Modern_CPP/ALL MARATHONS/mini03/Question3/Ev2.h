#ifndef EV2_H
#define EV2_H
#include "ElectricVehicle.h"
#include "ConnectedType.h"
#include <ostream>
class Ev2:public ElectricVehicle
{
private:
    float _battery_capacity;
    ConnectedType _connectedType;

public:
    Ev2()=delete;
    Ev2(const Ev2&)=delete;
    Ev2(Ev2&&)=delete;
    Ev2& operator=(const Ev2&)=delete;
    Ev2& operator=(Ev2&&)=delete;
    ~Ev2()=default;

    Ev2(int id, ElectricType type, float price, int seat_count, int engine_horsepower,float battery_capacity,ConnectedType connectedType);
    float batteryCapacity() const { return _battery_capacity; }
     float CalculateGst() override;
     float  CalculateExchangeAmount() override;

     friend std::ostream &operator<<(std::ostream &os, const Ev2 &rhs);
};


#endif // EV2_H
