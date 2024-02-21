#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <functional>
#include <unordered_map>
#include "TouristVehicleType.h"
#include "TouristVehicle.h"

using TouristPointer = std::shared_ptr<TouristVehicle>;
using MapContainer = std::unordered_map<std::string,TouristPointer>;
// using MapPointer = std::pair<std::string,TouristPointer>;
using TouristContainer = std::vector<TouristPointer>;

// void CreateObjects(TouristContainer& data);
// void LambdaFun(TouristContainer& data,std::function<bool(TouristPointer&,std::string)>fn,std::string id);
// extern std::function<TouristContainer(TouristContainer&,int)> GetNInstancesByCondition;
// extern std::function<float(TouristContainer&,VehicleType)> GetAverageBookingChanrge;

void CreateObjects(TouristContainer& data, MapContainer& mapData); //mapping elemets from container to mapData
TouristContainer GetNInstancesByCondition(MapContainer& mapData,int n);
float GetAverageBookingChanrge(MapContainer& mapData, VehicleType vt);


void createobj(MapContainer& map); //without using vector container


#endif // FUNCTIONALITIES_H