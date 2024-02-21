#include "ElectronicVehicle.h"

std::ostream &operator<<(std::ostream &os, const ElectronicVehicle &rhs) {
    os << "_id: " << rhs._id
       << " _model: " << rhs._model
       << " _batterytype: " << static_cast<int>(rhs._batterytype)
       << " _batteryCapacity: " << rhs._batteryCapacity
       << " _motor: " << rhs._motor;
    return os;
}

ElectronicVehicle::ElectronicVehicle(std::string id, std::string model, BatteryType batteryType, float batteryCapacity, refMotor motor)
    :_id(id), _model(model), _batterytype(batteryType), _batteryCapacity(batteryCapacity), _motor(motor)
{
}

float ElectronicVehicle::EvaluateChargingRate()
{
    return 0.0f;
}

float ElectronicVehicle::operator+(ElectronicVehicle &e1)
{
    return 0.0f;
}
