#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(std::string id, std::string model, BatteryType batteryType, float batteryCapacity,ReferenceWrapper motor)
:_id{id},_model{model},_batteryType{batteryType},_batteryCapacity{batteryCapacity},_motor{motor}
{
}
std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs) {

os<<"--------------------------------------------------------------"<<std::endl;
    os << "_id: " << rhs._id<<std::endl;
    os << " _model: " << rhs._model<<std::endl;
      // << " _batteryType: " << rhs._batteryType
            std::string battery;
            switch(rhs._batteryType)
            {
                case BatteryType::LITHIUM_ION:
                    battery="LITHIUM ION";
                    break;
                
                case BatteryType::NICKEL_METAL_HYDRIDE:
                    battery="NICKEL_METAL_HYDRIDE";
                    break;
            }
    
    os<<" batteryType: "<<battery<<std::endl;
    os<< " _batteryCapacity: " << rhs._batteryCapacity<<std::endl;
    os<<"-----------------------Motor Details------------------"<<std::endl;
    os<<rhs._motor.get()<<std::endl;

os<<"--------------------------------------------------------------"<<std::endl;
    return os;
}
