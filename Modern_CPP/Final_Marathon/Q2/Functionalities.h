#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <vector>
#include <list>
#include <unordered_map>
#include "Vehicle.h"
#include "NoMatchingInstanceException.h"
#include "EmptyContainerException.h"

using VehiclePointer = std::shared_ptr<Vehicle>;
using VehicleContainer = std::vector<VehiclePointer>;
using ServiceRecordPointer = std::shared_ptr<ServiceRecord>;

void CreateObjects(VehicleContainer& data);
VehicleContainer ReturnListOfLastNinstances(VehicleContainer& data,int n);
std::unordered_map<std::string,std::string> ReturnDictionary(VehicleContainer& data,std::vector<std::string> ids);
std::unordered_map<std::string,ServiceRecordPointer> ReturnDictionaryOfLatestRecord(VehicleContainer& data);
float AvegrageChargesofServiceRecord(VehicleContainer& data);
std::string ReturnVehicleIdByServiceId(VehicleContainer& data,std::string serviceId);

#endif // FUNCTIONALITIES_H
