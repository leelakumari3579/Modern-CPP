#include "Functionalities.h"
#include"DataEmptyException.h"

void CreateObjects(Container &data)
{
    data.emplace_back(std::make_shared<Developer>(
        "101",
        "Yuva",
        30000,
        2,
        std::vector<SkillSet>{SkillSet::CODING,SkillSet::CODE_REVIEW}
    ));
    data.emplace_back(std::make_shared<Developer>(
        "102",
        "Meha",
        80000,
        5,
        std::vector<SkillSet>{SkillSet::CODING,SkillSet::CODE_REVIEW}
    ));
    data.emplace_back(std::make_shared<CodeTester>(
        "103",
        "Sri Rama Jayam",
        100000,
        8,
        std::vector<SkillSet>{SkillSet::INTEGRATION_TESTING,SkillSet::UNIT_TESTING}
    ));
    data.emplace_back(std::make_shared<CodeTester>(
        "104",
        "Sashvin",
        100000,
        10,
        std::vector<SkillSet>{SkillSet::UNIT_TESTING}
    ));
}

std::optional<Container> EmployeeswithExperienceAbove6years(const Container &data)
{
    Container result;
    //Empty data
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty!!");
    }
    for(const std::variant<DeveloperPointer,CodeTesterPointer> &ptr:data)
    {
        if(std::holds_alternative<DeveloperPointer>(ptr))
        {
            if(std::get<0>(ptr)->experienceYears()>6)
            {
                result.emplace_back(ptr);
            }
        }
        else
        {
            if(std::get<1>(ptr)->experienceYears()>6)
            {
                result.emplace_back(ptr);
            }
        }
    }
    //if none of the employees exp is above 6
    if(result.empty())
    {
        return std::nullopt;
    }
    return result;
}

float AverageSalaryOfCodeTesters(const Container &data)
{
    //Checks Data emptyness
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty!!");
    }
    int total=0;
    int count=0;
    for(const std::variant<DeveloperPointer,CodeTesterPointer> &ptr:data)
    {
        if(std::holds_alternative<CodeTesterPointer>(ptr))
        {
            total+=std::get<1>(ptr)->salary();
            count++;
        }
    }
    return total/count;
}

std::optional<std::vector<SkillSet>> SkillsetOfPassedId(const Container &data, std::string id)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty!!");
    }
    for(const std::variant<DeveloperPointer,CodeTesterPointer> &ptr:data)
    {
        if(std::holds_alternative<DeveloperPointer>(ptr))
        {
            if(std::get<0>(ptr)->id()==id)
            {
                return  std::get<0>(ptr)->skill();
            }
        }
        if(std::holds_alternative<CodeTesterPointer>(ptr))
        {
            if(std::get<1>(ptr)->id()==id)
            {
                return  std::get<1>(ptr)->skill();
            }
        }
    }
    //if employee Id is not in data
    return std::nullopt;
}

bool IsSalaryAbove60000(const Container &data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty!!");
    }
    for(const std::variant<DeveloperPointer,CodeTesterPointer> &ptr:data)
    {
        if(std::holds_alternative<DeveloperPointer>(ptr))
        {
            return (std::get<0>(ptr)->salary()>60000);
        }
        if(std::holds_alternative<CodeTesterPointer>(ptr))
        {
            return (std::get<1>(ptr)->salary()>60000);
        }
    }
    //if employee salary is not above 60000
    return false;
}

std::optional<float> CalculateBonusOfEmployee(const Container &data, std::string id)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is empty!!");
    }
    for(const std::variant<DeveloperPointer,CodeTesterPointer> &ptr:data)
    {
        if(std::holds_alternative<DeveloperPointer>(ptr))
        {
            if(std::get<0>(ptr)->id()==id)
            {
                return std::get<0>(ptr)->CalculateBonus();
            }
        }
        if(std::holds_alternative<CodeTesterPointer>(ptr))
        {
            if(std::get<1>(ptr)->id()==id)
            {
                return std::get<1>(ptr)->CalculateBonus();
            }
        }
    }
    return std::nullopt;
}
