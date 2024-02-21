#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<functional>
#include<vector>
#include"EmptyContainerException.h"
#include"InSufficientDataException.h"

using FunType = std::function<int(std::vector<int>&)>;  // 

using Container = std::vector<FunType>;     //container That takes the functions

void FillingVector(std::vector<int>&);

void MakeLambda(Container&);            // having all the lambda functions

void Operation(Container&,std::vector<int>&);  // main Operation

#endif // FUNCTIONALITIES_H
