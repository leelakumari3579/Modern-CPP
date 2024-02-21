#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H
#include "Motor.h"
#include "BatteryType.h"
#include<functional>
#include <ostream>
class ElectricVehicle
{
private:
   const std::string _id;
   const std::string _model;
   const BatteryType _batteryType;
   const float _batteryCapacity;
   const std::reference_wrapper<Motor> _motor;

public:
    ElectricVehicle()=delete;
    ElectricVehicle(const  ElectricVehicle&)=default;
    ElectricVehicle( ElectricVehicle&&)=default;
    ElectricVehicle& operator=(const  ElectricVehicle&)=delete;
    ElectricVehicle& operator=( ElectricVehicle&&)=delete;
   ~ ElectricVehicle()=default;

   std::string id() const { return _id; }
   std::string model() const { return _model; }
   BatteryType batteryType() const { return _batteryType; }
   std::reference_wrapper<Motor> motor() const { return _motor; }

   ElectricVehicle(const std::string _id,const std::string _model,BatteryType _batteryType,const float _batteryCapacity,std::reference_wrapper<Motor> _motor);
    
   float operator +(ElectricVehicle& e);

   float batteryCapacity() const { return _batteryCapacity; }

   float EvaulateChargingRate();
   friend std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs);

};


#endif // ELECTRICVEHICLE_H
