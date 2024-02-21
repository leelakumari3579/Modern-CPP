#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include<functional>
#include<vector>
using DataContainer=std::vector<int>;
using fnType=std::function<int(DataContainer&)>;

extern fnType oddSumDivBy3;
extern fnType lowestEven;
extern fnType FindMaxAmongThree;

void PerformOperation(DataContainer& data,fnType func);

#endif // FUNCTIONALITIES_H
