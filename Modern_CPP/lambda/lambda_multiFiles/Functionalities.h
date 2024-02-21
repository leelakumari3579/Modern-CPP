#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

using FnType = std::function<int(std::vector<int> &data)>;
using FnContainer = std::vector<FnType>;
using DataContainer = std::vector<int>;

void Operation(FnContainer &fns, DataContainer &data);
void MakeLambda(FnContainer &fns);

extern FnType f1; // extern ---> declared here but initialized in some where
extern FnType f2;
extern FnType f3;