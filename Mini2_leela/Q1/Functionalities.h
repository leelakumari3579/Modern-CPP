#include <iostream>
#include <vector>
#include <functional>
#include "NoMatchingInstanceException.h"
#include "EmptyContainerException.h"

using FunctionType = std::function<int(std::vector<int>& data)>;
using FunctionContainer = std::vector<FunctionType>;
using DataContainer = std::vector<int>;

void PerformOperation(FunctionContainer& functionData, DataContainer& data);
void MakeLambdaFunctions(FunctionContainer& functionData);

extern FunctionType SumOfOddNumbersDivisibleBy3;
extern FunctionType LowestEvenNumber;
extern FunctionType MaxFromFirst3Numbers;