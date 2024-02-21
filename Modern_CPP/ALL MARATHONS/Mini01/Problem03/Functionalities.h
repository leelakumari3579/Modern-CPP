#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <vector>
#include "TouristVehicle.h"
#include "Permit.h"

using TouristVehiclePointer = std::shared_ptr<TouristVehicle>;
using TouristVehicleContainer = std::vector<TouristVehiclePointer>;


void CreateObjects(TouristVehicleContainer& tVData);

std::vector<TouristVehicle> GetPermitInstancesBasedOnConditions(TouristVehicleContainer& tVData, int N);

float AverageBookingChargeByType(TouristVehicleContainer& tVData, VehicleType vType);

std::string FindSerialNumberByTVMAXBookingCharge(TouristVehicleContainer& tVData);

std::vector<TouristVehiclePointer> GetFirstNTV(TouristVehicleContainer& tVData, int N);

#endif // FUNCTIONALITIES_H
