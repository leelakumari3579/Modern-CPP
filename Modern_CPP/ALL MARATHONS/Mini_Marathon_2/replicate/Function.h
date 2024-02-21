#include "Car.h"
#include "EvCar.h"
#include "ICEngineCar.h"

#include<vector>
#include<memory>
#include<array>
#include<functional>

void CreateObjects(std::vector<std::shared_ptr<Car>>& Carvector);

extern std::function<float(std::vector<std::shared_ptr<Car>>,CarType)> CarTypeAverageInsuranceCost;

extern std::function<std::array<int,2>(std::vector<std::shared_ptr<Car>>)> CountChildInstancesWithConditions;