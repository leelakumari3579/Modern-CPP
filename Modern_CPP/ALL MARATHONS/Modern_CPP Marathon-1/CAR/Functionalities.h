#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Car.h"
#include<memory>
#include<vector>


using CarPointer=std::shared_ptr<Car>;
using Container=std::vector<CarPointer>;

//using Vector=std::vector<Car>;

void CreateObjects(Container& carData);
Car InstanceAtPositionN(Container& carData, int n);
void SearchCarById(Container& carData, std::string id);
float AveragePriceofInstances(Container& carData,PermitType ptype);


#endif // FUNCTIONALITIES_H
