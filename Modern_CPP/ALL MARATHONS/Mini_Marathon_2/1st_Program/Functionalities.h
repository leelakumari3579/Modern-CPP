
#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <functional>
#include <string>

void PerformOperation(std::vector<std::function<std::string(std::vector<std::string>)>> &fns,
                      std::vector<std::string> &data);

extern std::function<std::string(std::vector<std::string>)> MinimumLength;
extern std::function<std::string(std::vector<std::string>)> OnlyConsonants;
extern std::function<std::string(std::vector<std::string>)> SecondPosition;

void MakeLambda(std::vector<std::function<std::string(std::vector<std::string>)>> &fns);

#endif // FUNCTIONALITIES_H
