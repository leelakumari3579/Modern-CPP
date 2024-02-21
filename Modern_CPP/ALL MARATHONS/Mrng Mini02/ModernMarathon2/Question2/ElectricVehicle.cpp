#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(const std::string id,const std::string model, BatteryType batteryType, const float batteryCapacity,std::reference_wrapper<Motor> motor)
:_id(id),_model(model),_batteryType(batteryType),_batteryCapacity(batteryCapacity),_motor(motor)
{
}

float ElectricVehicle::operator+(ElectricVehicle &e)
{
    return this->motor().get()+e.motor().get();
    //return this->motor().get()+e.motor().get();
}
float ElectricVehicle::EvaulateChargingRate()
{
    if(_batteryType==BatteryType::LITHIUM_ION){
        return 0.1*_batteryCapacity;
    }else{
        return (0.1*(this->motor().get().maxTorque())+0.2*(this->motor().get().maxPower()))/100;
    }
}
std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs)
{
    os << "_id: " << rhs._id
       << " _model: " << rhs._model
       << " _batteryType: " ;
    switch (rhs._batteryType)
    {
    case BatteryType::LITHIUM_ION:
        os<<"BatteryType::LITHIUM_ION : 11";
        break;
    case BatteryType::NICKEL_METAL_HYDRIDE:
        os<<"BatteryType::NICKEL_METAL_HYDRIDE : 22";
        break;
    
    }
       os << " _motor: " << rhs._motor<<"\n";
    return os;
}
