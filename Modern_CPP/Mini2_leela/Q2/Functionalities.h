#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <memory>
#include <functional>
#include <vector>
#include "ElectronicVehicle.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "NoMatchingInstanceException.h"

using ElectronicVehiclePointer = std::shared_ptr<ElectronicVehicle>;
using ElectronicVehiclePointerContainer = std::vector<ElectronicVehiclePointer>;
using MotorContainer = std::vector<Motor>;
using LambdaExpression = std::function<ElectronicVehiclePointerContainer(ElectronicVehiclePointer)>;

void CreateObjects(ElectronicVehiclePointerContainer &eVehicleData, MotorContainer &motorData);
int ReturnMotorTorqueById(ElectronicVehiclePointerContainer &eVehicleData, std::string id);
float CalculateBatteryDrain(ElectronicVehiclePointerContainer &eVehicleData);
std::vector<ElectronicVehicle> FilterData(ElectronicVehiclePointerContainer &eVehicleData, LambdaExpression &lambda);
Motor OperatorAddForMotorValues(ElectronicVehiclePointer& ev1, ElectronicVehiclePointer& ev2);

#endif // FUNCTIONALITIES_H
