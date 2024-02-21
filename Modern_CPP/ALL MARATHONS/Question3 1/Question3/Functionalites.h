#ifndef FUNCTIONALITES_H
#define FUNCTIONALITES_H
#include<vector>
#include"ElectricVehicle.h"
#include<memory>
#include"EvCar.h"
#include"Ev2Wheeler.h"
#include<future>
#include"EmptyContainerException.h"
#include<optional>

using ElectricVehiclePointer =  std::shared_ptr<ElectricVehicle>;

using Container  = std::vector<ElectricVehiclePointer>;

using EvCarPointer = std::shared_ptr<EvCar>;

using Ev2WheelerPointer = std::shared_ptr<Ev2Wheeler>;


void CreateObjects(Container&);

void DisplayAllAttributes(Container&,std::future<int>& ft);

void AveragePriceOfAllEvCars(Container&);

std::optional<Container> ReturnInstancesOfSmartPointer(Container&,float threshold);

void SumOfTotalGst(Container&);

void SumOfExchangeAmountOfEv2Wheeler(Container&);

#endif // FUNCTIONALITES_H
