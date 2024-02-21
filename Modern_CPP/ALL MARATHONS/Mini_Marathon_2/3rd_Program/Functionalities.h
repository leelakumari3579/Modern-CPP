#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include"EvCar.h"
#include"ICEngineCar.h"
#include<vector>
#include<memory>
#include<functional>
#include<array>

void CreateObjects(std::vector<std::shared_ptr<Car>>& vectorCar);

extern std::function<float(std::vector<std::shared_ptr<Car>>,CarType)> CarTypeAverageInsuranceCost;
extern std::function<std::array<int,2>(std::vector<std::shared_ptr<Car>>)> CountChildInstancesWithConditions;

#endif // FUNCTIONALITIES_H
