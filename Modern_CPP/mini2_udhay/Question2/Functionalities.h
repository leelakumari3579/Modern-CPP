#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<memory>
#include"ElectricVehicle.h"
#include"Motor.h"
#include<vector>
#include"EmptyContainerException.h"
#include"ValidDataNotFoundException.h"
#include"NoInstanceFoundException.h"
#include<functional>
#include<variant>

using ElectricVehiclePointer = std::shared_ptr<ElectricVehicle>;
using Container = std::vector<ElectricVehiclePointer>;

using ContainerMotor = std::vector<Motor>;

void CreateObjects(Container&,ContainerMotor&);

std::variant<float,unsigned int> AcceptsIdReturnsTorqueOrPower(Container&,std::string id);   // Returns Respective Torque or Power

void DisplaysBatteryDrain(Container&);    //DISPLAYS BATTER DRAIN OF EVERY INSTANCE.......

Container FilterData(Container&,std::function<int(ElectricVehiclePointer&)>);

// Filter Data that Filter as per condition

void PerformOperator(Container& data);


#endif // FUNCTIONALITIES_H
