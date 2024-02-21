#include "Ev2Wheeler.h"

Ev2Wheeler::Ev2Wheeler(float battery_capacity, ConnectedTechType connectedTechType, ElectricVehicleType type, float price, int seat_count, int engine_horsepower)
:ElectricVehicle(type,price,seat_count,engine_horsepower),_battery_capacity{battery_capacity},_connectedTechType{connectedTechType}
{
}

std::ostream &operator<<(std::ostream &os, const Ev2Wheeler &rhs) {
    os << static_cast<const ElectricVehicle &>(rhs)<<std::endl;
    os << " _battery_capacity: " << rhs._battery_capacity<<std::endl;
     //  << " _connectedTechType: " << rhs._connectedTechType;
     std::string connectedstr;
     switch(rhs._connectedTechType)
     {
        case ConnectedTechType::DIGITAL:
            connectedstr = "DIGITAL";
            break;
        case ConnectedTechType::NAVIGATION_ONLY:
            connectedstr = "NAVIGATIONA_ONLY";
            break;
        case ConnectedTechType::SMART:
            connectedstr = "SMART";
            break;

     }
    os<<" _connectedTechType: "<<connectedstr<<std::endl;
    return os;
}

float Ev2Wheeler::CalculateGst()
{
    float result = 0.0f;

    result = 0.1*price();

    return result;
}

float Ev2Wheeler::CalculateExchangeAmount()
{
    float result = 0.0f;

    result  = 0.32*price();

    return result;
}
