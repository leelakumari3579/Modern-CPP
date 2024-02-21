#include "Functionalities.h"
#include <iostream>

void CreateObjects(Container &data)
{
    data.emplace_back(std::make_shared<CodeTester>("202", "leela", 4000000.0f, 1, SkillSet::INTEGRATION_TESTING));
    data.emplace_back(std::make_shared<Developer>("203", "nani", 450000.0f, 12, SkillSet::CODING));

    data.emplace_back(std::make_shared<CodeTester>("101", "mounika", 5000000.0f, 2, SkillSet::UNIT_TESTING));
    data.emplace_back(std::make_shared<Developer>("102", "manoj", 10000000.0f, 11, SkillSet::CODE_REVIEW));
}

std::optional<Container> ReturnEmployeePointerByExperienceAbove6(Container &data)
{
    Container result;
    for (std::variant<TesterPointer, DeveloperPointer> &ptr : data)
    {
        if (std::holds_alternative<TesterPointer>(ptr))
        {
            if (std::get<0>(ptr)->experienceYears() > 6)
                result.emplace_back(ptr);
        }
        else
        {
            if (std::get<1>(ptr)->experienceYears() > 6)
                result.emplace_back(ptr);
        }
    }
    return result;
}

float AverageSalaryOfCodeTesters(Container &data)
{
    float avg = 0.0f;
    float sum = 0;
    int count = 0;
    for (std::variant<TesterPointer, DeveloperPointer> &ptr : data)
    {
        if (std::holds_alternative<TesterPointer>(ptr))
        {
            sum = sum + std::get<0>(ptr)->salary();
            count++;
        }
    }
    avg = sum / count;
    return avg;
}

// float AverageSalaryOfCodeTesters(Container &data, std::function<float(float &)> &lambdafn)
// {
//      for(std::variant<TesterPointer,DeveloperPointer>& ptr : data)
//     {
//         if(std::holds_alternative<TesterPointer>(ptr))
//         {
//             lambdafn(std::get<0>(ptr)->salary());
//         }
//     }
// }

std::optional<SkillSet> ReturnSkillSetByEmployeeId(const Container &data, std::future<std::string> &id)
{
    std::string ans = id.get();
    for (const std::variant<TesterPointer, DeveloperPointer> &ptr : data)
    {
        if (std::holds_alternative<TesterPointer>(ptr))
        {
            if (std::get<0>(ptr)->id() == ans)
                // result = std::get<0>(ptr)->skill();
                return std::get<0>(ptr)->skill();
        }
        else
        {
            if (std::get<1>(ptr)->id() == ans)
                // result = std::get<1>(ptr)->skill();
                return std::get<0>(ptr)->skill();
        }
    }
    return std::nullopt;
}

bool ReturnBoolBySalaryAbove60k(Container &data)
{
    bool flag = false;
    for (std::variant<TesterPointer, DeveloperPointer> &ptr : data)
    {
        if (std::holds_alternative<TesterPointer>(ptr))
        {
            if (std::get<0>(ptr)->salary() > 60000)
                flag = true;
        }
        else
        {
            if (std::get<1>(ptr)->salary() > 60000)
                flag = true;
        }
    }
    return flag;
}

std::optional<float> EmployeeBonusFromMemberClass(Container &data, std::future<std::string> &id)
{
    std::string ans = id.get();
    for (std::variant<TesterPointer, DeveloperPointer> &ptr : data)
    {
        if (std::holds_alternative<TesterPointer>(ptr))
        {
            if (std::get<0>(ptr)->id() == ans)
                return std::get<0>(ptr)->CalculateBonus();
        }
        else
        {
            if (std::get<1>(ptr)->id() == ans)
                return std::get<1>(ptr)->CalculateBonus();
        }
    }
    return std::nullopt;
}

void NameById(Container &data, std::string id)
{
    for (std::variant<TesterPointer, DeveloperPointer> &ptr : data)
    {
        if (std::holds_alternative<TesterPointer>(ptr))
        {
            if (std::get<0>(ptr)->id() == id)
            {
                std::lock_guard<std::mutex> lg(std::mutex);
                std::cout << std::get<0>(ptr)->name();
            }
        }
        else
        {
            if (std::get<1>(ptr)->id() == id)
            {
                std::lock_guard<std::mutex> lg(std::mutex);
                std::cout << std::get<1>(ptr)->name();
            }
        }
    }
}

