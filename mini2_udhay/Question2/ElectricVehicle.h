#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H
#include<string>
#include"BatteryType.h"
#include<functional>
#include <ostream>
#include"Motor.h"

using ReferenceWrapper = std::reference_wrapper<Motor>;

class ElectricVehicle
{
private:
    std::string _id;
    std::string _model;
    BatteryType _batteryType;
    float _batteryCapacity;
    ReferenceWrapper _motor;

public:

    ElectricVehicle(std::string id,std::string model,BatteryType batteryType,float batteryCapacity,ReferenceWrapper motor);

    ElectricVehicle() =delete;
    ElectricVehicle(const ElectricVehicle&)=delete;
    ElectricVehicle(ElectricVehicle&&)=delete;
    ElectricVehicle& operator=(const ElectricVehicle&)=delete;
    ElectricVehicle& operator=(ElectricVehicle&&)=delete;
    ~ElectricVehicle()=default;

    std::string id() const { return _id; }

    std::string model() const { return _model; }
    void setModel(const std::string &model) { _model = model; }

    BatteryType batteryType() const { return _batteryType; }
    void setBatteryType(const BatteryType &batteryType) { _batteryType = batteryType; }

    float batteryCapacity() const { return _batteryCapacity; }
    void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }

    ReferenceWrapper motor() const { return _motor; }
    void setMotor(const ReferenceWrapper &motor) { _motor = motor; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs);

    
    float operator+(ElectricVehicle& v)
    {
        return this->motor().get()+v.motor().get();
    }


};

#endif // ELECTRICVEHICLE_H
