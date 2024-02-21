#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "CreateCheck.h"
#include "EmptyContainer.h"
#include "IdNotFound.h"
#include "ElectricVehicle.h"
#include<memory>
#include<vector>

using ElectricVehiclePointer=std::shared_ptr<ElectricVehicle>;
using MotorContainer=std::vector<Motor>;
using ElectricVehicleContainer=std::vector<ElectricVehiclePointer>;

using FunType=std::function<bool(float)>;

void createElectricVehicles(MotorContainer& motors,ElectricVehicleContainer& Evehicles);

float maxTorqueOrmaxPowerBasedOnBatteryCapacity(ElectricVehicleContainer& Evehicles, std::string id);

void calculateBatteryDrain(ElectricVehicleContainer& Evehicles);

ElectricVehicleContainer FilterData(ElectricVehicleContainer& Evehicles,FunType);

void PerformOpeator(ElectricVehicleContainer& Evehicles);


#endif // FUNCTIONALITIES_H
