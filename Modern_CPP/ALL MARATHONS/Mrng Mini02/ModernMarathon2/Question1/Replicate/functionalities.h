#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include<functional>

using fnType=std::function<int(std::vector<int>&)>;
using funContainer=std::vector<fnType>;

void MakeLambda(funContainer&);

extern int SumofSquare(std::vector<int>&);

extern int PrimeNumber(std::vector<int>&);

void PerformOpearations(funContainer,std::vector<int>&);

#endif // FUNCTIONALITIES_H
