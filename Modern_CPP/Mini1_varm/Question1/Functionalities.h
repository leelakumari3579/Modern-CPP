#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include<memory>
#include<vector>
#include "Car.h"
#include "NoCarsAvaialble.h"
#include "NOCarFoundExeception.h"

using CarPointer =std::shared_ptr<Car>;
using CarContainer= std::vector<CarPointer>;

/* functions */

void CreateObjects(CarContainer &data);

Car FindNthCar(const CarContainer &data,int index);

void DisplayCarById(const CarContainer &data,std::string carId);

float findAverage_price(const CarContainer&data,PermitType ptype);

#endif // FUNCTIONALITIES_H
