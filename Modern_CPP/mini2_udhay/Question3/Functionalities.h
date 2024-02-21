#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<memory>
#include"Flight.h"
#include"Plane.h"
#include<list>
#include"EmptyContainerException.h"

using FlightPointer = std::shared_ptr<Flight>;

using Container = std::list<FlightPointer>;

using PlanePointer = std::shared_ptr<Plane>;

using ContainerPlane = std::list<PlanePointer>;

using FunContainer = std::list<std::function<void(std::list<FlightPointer>&)>>;

void CreateObjects(Container&,ContainerPlane&); // Aggregation Concept

void MakeLambdaq3(FunContainer&);

void Operation(Container&,FunContainer&);

#endif // FUNCTIONALITIES_H
