#include <iostream>
#include <memory>
#include <vector>
#include "Automobile.h"

using AutomobilePointer = std::shared_ptr<Automobile>;
using AutomobileContainer = std::array<AutomobilePointer,3>;

void CreateObjects(AutomobileContainer& data);
float GreenPassCostById(AutomobileContainer& data, std::string id);
float AveragePrice(AutomobileContainer& data);
PrivilegeCategory DisplayFindPrivilegeType(AutomobileContainer& data);