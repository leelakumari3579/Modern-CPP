#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <memory>
#include <functional>
#include <vector>
#include "TouristVehicle.hpp"

using TouristVehiclePointer = std::shared_ptr<TouristVehicle>;
using TVContainer = std::vector<TouristVehiclePointer>;

// void CreateObjects(TVContainer& data);
extern std::function<void(std::reference_wrapper<TVContainer>)> LCreateObjects;

// std::vector<TouristVehicle> GetNInstancesByCondition(TVContainer& data, int N);
extern std::function<std::vector<TouristVehicle>(TVContainer&, int)> LGetNInstancesByCondition;

// float GetAverageBookingCharge(TVContainer& data, VehicleType vType);
extern std::function<float(TVContainer&, VehicleType)> LGetAverageBookingCharge;

// std::string GetSerialNumber(TVContainer& data);
extern std::function<std::string(TVContainer&)>  LGetSerialNumber;

// std::vector<TouristVehiclePointer>  GetFirstNInstances(TVContainer& data, int N);
extern std::function<std::vector<TouristVehiclePointer>(TVContainer&, int)> LGetFirstNInstances;

#endif // FUNCTIONALITIES_HPP
