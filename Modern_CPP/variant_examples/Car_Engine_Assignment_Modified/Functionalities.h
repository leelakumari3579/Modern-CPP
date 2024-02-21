#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <string>
#include <vector>
#include <memory>
// #include <optional>
#include "Car.h"
#include "Engine.h"

using CarPointer = std::shared_ptr<Car>;
using CarPointerContainer = std::vector<CarPointer>;
using EngineContainer = std::vector<Engine>;

void CreateObjects(CarPointerContainer& carData,EngineContainer& engineData);
int FindHoursepowerByCarId(CarPointerContainer& carData, std::string carId);
std::optional<std::vector<Car>> FindAbove80TorqueCars(CarPointerContainer& carData); //std::optional--> may or maynot return 
// std::vector<Engine> FindEngineDetilsByCarType(CarPointerContainer& carData, CarType cType);
float AverageHoursepower(CarPointerContainer& carData);
std::string FindLowPriceByCarId(CarPointerContainer& carData);
float TwoCarInstancesCombinedPrice(CarPointer& car1,CarPointer& car2);

#endif // FUNCTIONALITIES_H
