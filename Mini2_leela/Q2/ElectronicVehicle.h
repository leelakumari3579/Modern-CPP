#ifndef ELECTRONICVEHICLE_H
#define ELECTRONICVEHICLE_H
#include <string>
#include <functional>
#include <ostream>
#include "BatteryType.h"
#include "Motor.h"

using refMotor = std::reference_wrapper<Motor>;

class ElectronicVehicle
{
private:
    const std::string _id {"102b"};
    std::string _model {"xyz"};
    BatteryType _batterytype {BatteryType::LITHIUM_ION};
    float _batteryCapacity {0.0f};
    refMotor _motor;
public:
    ElectronicVehicle() = default;
    ElectronicVehicle(const ElectronicVehicle &) = default;
    ElectronicVehicle &operator=(const ElectronicVehicle &) = delete;
    ElectronicVehicle &operator=(ElectronicVehicle &&) = delete;
    ElectronicVehicle(ElectronicVehicle &&) = delete;
    ~ElectronicVehicle() = default;

    ElectronicVehicle(const std::string id, std::string model, BatteryType batteryType, float batteryCapacity, refMotor motor);
    float EvaluateChargingRate();
    float operator+(ElectronicVehicle &e1);
    

    std::string id() const { return _id; }

    std::string model() const { return _model; }
    void setModel(const std::string &model) { _model = model; }

    BatteryType batterytype() const { return _batterytype; }
    void setBatterytype(const BatteryType &batterytype) { _batterytype = batterytype; }

    float batteryCapacity() const { return _batteryCapacity; }
    void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }

    refMotor motor() const { return _motor; }
    void setMotor(const refMotor &motor) { _motor = motor; }

    friend std::ostream &operator<<(std::ostream &os, const ElectronicVehicle &rhs);
};



#endif // ELECTRONICVEHICLE_H
