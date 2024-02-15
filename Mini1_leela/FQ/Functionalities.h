#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <vector>
#include "Car.h"


using CarPointer = std::shared_ptr<Car>;
using CarPointerContainer = std::vector<CarPointer>;

void CreateObjects(CarPointerContainer& carData);
std::vector<Car> FindInstanceByN(CarPointerContainer& carData,int n);
std::vector<Car> FindAttributesById(CarPointerContainer& carData, std::string id);
float FindAveragePrice(CarPointerContainer& carData,PermitType permitType);

#endif // FUNCTIONALITIES_H
