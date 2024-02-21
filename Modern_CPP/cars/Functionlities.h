#ifndef FUNCTIONLITIES_H
#define FUNCTIONLITIES_H

//new concept
#include<memory>
#include"Car.h"
#include<vector>

using Pointer = std::shared_ptr<Car>;
using container = std::vector<Pointer>;

void CreateObjects(container& data);
float AveragePrice(container& data);
float FindPriceById(container& data, std::string id);

/*
(client)
main.cpp  create objects  ---> Average Function  ---> last function 
data ---> (filled with pointers)  ---> input (by reference)
*/
#endif // FUNCTIONLITIES_H
