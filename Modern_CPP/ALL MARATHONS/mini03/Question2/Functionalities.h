#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Developer.h"
#include "CodeTester.h"
#include<variant>
#include<optional>
#include<memory>
#include "EmptyContainer.h"
#include "NoCodeTester.h"
using DeveloperPointer=std::shared_ptr<Developer>;
using CodeTesterPointer=std::shared_ptr<CodeTester>;
using EmployeePointer=std::variant<DeveloperPointer,CodeTesterPointer>;
using Container=std::vector<EmployeePointer>;

void createObjects(Container &data);

Container EmployeeAbove6yrsExper(Container &data);
float findAvgSalaryCodeTester(Container& data);
std::optional<skills> FindSkills(Container& data,std::string id);
bool isSalaryGreaterThan60000(Container& data);
std::optional<float> GetBonus(Container& data,std::string id);

#endif // FUNCTIONALITIES_H
