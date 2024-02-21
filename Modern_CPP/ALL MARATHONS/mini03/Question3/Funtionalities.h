#ifndef FUNTIONALITIES_H
#define FUNTIONALITIES_H

#include "EvCar.h"
#include "Ev2.h"
#include "memory"
#include "vector"
using ElectricVehiclePtr=std::shared_ptr<ElectricVehicle>;

using EvCarPtr=std::shared_ptr<EvCar>;

using Ev2Ptr=std::shared_ptr<Ev2>;

using container=std::vector<ElectricVehiclePtr>;

void create(container &data);

void display(container &data,int id);



#endif // FUNTIONALITIES_H
