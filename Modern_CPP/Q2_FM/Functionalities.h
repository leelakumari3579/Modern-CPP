#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<list>
#include<vector>
#include<memory>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<optional>
#include"ServiceRecord.h"
#include"Vehicle.h"
#include"EmptyContainerException.h"

using ServicePointer=std::shared_ptr<ServiceRecord>;
using VehiclePointer=std::shared_ptr<Vehicle>;
using VehicleContainer=std::vector<VehiclePointer>;

void CreateObjects(VehicleContainer& data);
std::optional<std::list<VehiclePointer>> FindLastNinstances(VehicleContainer& data,int n);
std::unordered_map<std::string,std::string> FindPairByVehicleId(VehicleContainer& data,std::list<std::string>& id);
std::unordered_map<std::string,ServicePointer> FindMaximumServiceChargeInstance(VehicleContainer& data);
float AverageChargesOfRegularType(VehicleContainer& data);
std::optional<std::string> FindVehicleIdByServiceId(VehicleContainer& data,std::string serviceid);


#endif // FUNCTIONALITIES_H
