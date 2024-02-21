#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <memory>
#include <variant>
#include <optional>
#include <functional>
#include "CodeTester.h"
#include "Developer.h"
#include <future>

using TesterPointer = std::shared_ptr<CodeTester>;
using DeveloperPointer = std::shared_ptr<Developer>;
using Container = std::vector<std::variant<TesterPointer, DeveloperPointer>>;

void CreateObjects(Container &data);
std::optional<Container> ReturnEmployeePointerByExperienceAbove6(Container &data);
float AverageSalaryOfCodeTesters(Container &data);
// float AverageSalaryOfCodeTesters(Container &data, std::function<float(float&)>& lambdafn);
std::optional<SkillSet> ReturnSkillSetByEmployeeId(const Container &data, std::future<std::string> &id);
bool ReturnBoolBySalaryAbove60k(Container &data);
std::optional<float> EmployeeBonusFromMemberClass(Container &data, std::future<std::string> &id);
void NameById(Container &data, std::string id);

#endif // FUNCTIONALITIES_H
