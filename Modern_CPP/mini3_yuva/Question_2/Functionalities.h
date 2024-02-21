#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Developer.h"
#include"CodeTester.h"

#include<vector>
#include<memory>
#include<variant>
#include<optional>

using DeveloperPointer=std::shared_ptr<Developer>;
using CodeTesterPointer=std::shared_ptr<CodeTester>;

using Container=std::vector<std::variant<DeveloperPointer,CodeTesterPointer>>;

void CreateObjects(Container& data);
//returns the employee pointer in a container whose exp yr is above 6
std::optional<Container> EmployeeswithExperienceAbove6years(const Container& data);
//returns the average salary of CodeTesters
float AverageSalaryOfCodeTesters(const Container& data);
//returns the skill set of passed employee id
std::optional<std::vector<SkillSet>> SkillsetOfPassedId(const Container& data,std::string id);
//returns true or false if salary is above 60000 then true else false
bool IsSalaryAbove60000(const Container& data);
//returns the calculated bonus using member function of corresponding classes
std::optional<float> CalculateBonusOfEmployee(const Container& data,std::string id);

#endif // FUNCTIONALITIES_H
