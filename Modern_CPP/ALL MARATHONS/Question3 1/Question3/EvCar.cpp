#include "EvCar.h"

EvCar::EvCar(float battery_capacity, ChargingType chargingType,ElectricVehicleType type,float price, int seat_count, int engine_horsepower)
:ElectricVehicle(type,price,seat_count,engine_horsepower),_battery_capacity{battery_capacity},_chargingType{chargingType}
{
}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << static_cast<const ElectricVehicle &>(rhs)
       << " _battery_capacity: " << rhs._battery_capacity<<std::endl;
     //  << " _chargingType: " << rhs._chargingType;
     std::string charge;
        switch(rhs._chargingType)
        {
            case ChargingType::AC:
                charge="AC";
                break;
            case ChargingType::DC_FAST_CHARGE:
                charge = "DC_FAST_CHARGE";
                break;
            case ChargingType::BOTH:
                charge = "BOTH";
                break;
        }
    return os;
}

float EvCar::CalculateGst()
{
   float result = 0.0f;

    result = 0.5f*price();

    return result;

}

float EvCar::CalculateExchangeAmount()
{
    float result=0.0f;

    if(type()== ElectricVehicleType::REGULAR)
    {
        result = 0.6*price();
    }
    else if(type()==ElectricVehicleType::TRANSPORT)
    {
        if((_chargingType==ChargingType::AC)||(_chargingType==ChargingType::DC_FAST_CHARGE))
        {
            result = 0.75*price();
        }
        else{
            result = 0.75*price();
        }
    }

    return result;    

}
