#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <memory>
#include <variant>
#include <vector>


#include "EvCar.hpp"
#include "ICECar.hpp"
#include "CarType.hpp"

using EVPointer = std::shared_ptr<EvCar>;
using ICPointer = std::shared_ptr<ICECar>;
using Holder = std::variant<EVPointer, ICPointer>;
using Container = std::vector<Holder>;

void CreateObjects(Container& data);

Container GetFirstNBasedOnType(Container& data, CarType cType, int N);

bool CheckICForTankCapacityAbove30(Container& data);

void CountEvCars(Container& data);

ChassisType FindChassisTypeOnId(Container& data, int id);

void PrintBatteryCapacity(Container &data);

void DisplayNthData(Container& data, int N);

#endif // FUNCTIONALITIES_HPP
