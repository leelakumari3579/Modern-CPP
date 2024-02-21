#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

// SOR(separation of responsibilities), SOLID, RULE Of Zero, RULE Of Three and RULE Of Five

#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include <vector>
#include <memory>

using VehiclePointer = std::shared_ptr<Vehicle>;
using DataContainer = std::vector<VehiclePointer>;

void createObjects(DataContainer &data);
float CalculateTotalRegistrationTax(const DataContainer &data);

#endif // FUNCTIONALITIES_H