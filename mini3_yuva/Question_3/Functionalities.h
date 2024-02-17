#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"ElectricVehicle.h"
#include"Ev2Wheeler.h"
#include"EvCar.h"

#include<vector>
#include<memory>
#include<future>
#include<optional>

using EVehiclePointer=std::shared_ptr<ElectricVehicle>;
using EVContainer=std::vector<EVehiclePointer>;

// using Ev2WheelerPointer = std::shared_ptr<Ev2Wheeler>;
// using EvCarPointer = std::shared_ptr<EvCar>;

// Ev2WheelerPointer Ev2WheelerFullPtr = std::dynamic_pointer_cast<Ev2Wheeler>(EVehiclePointer);

void CreateObjects(EVContainer& data);
void DisplayAttributesOfGivenId(EVContainer& data,std::future<int>& ft);
std::optional<float> AveragePriceOfAllEvCars(EVContainer& data);
std::optional< EVContainer> InstancesOfPriceAboveThresholdValue(EVContainer& data,float price);
float CalculetSumOfGST(EVContainer& data);
float CalculateTotalExchangeAmount(EVContainer& data);



#endif // FUNCTIONALITIES_H
