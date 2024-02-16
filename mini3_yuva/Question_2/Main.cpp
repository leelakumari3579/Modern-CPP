#include "Functionalities.h"
#include "DataEmptyException.h"

#include <future>
#include <iostream>

int main()
{
    Container employees;
    std::future<void> createObjects = std::async(std::launch::async, CreateObjects, std::ref(employees));
    createObjects.get();
    try
    {
        // returns the employee pointer in a container whose exp yr is above 6
        std::future<std::optional<Container>> containerInstances = std::async(std::launch::async, EmployeeswithExperienceAbove6years, std::ref(employees));
        if (std::optional<Container> result = containerInstances.get(); result.has_value())
        {
            for (std::variant<DeveloperPointer, CodeTesterPointer> &ptr : result.value())
            {
                if (std::holds_alternative<DeveloperPointer>(ptr))
                {
                    std::cout << *(std::get<0>(ptr)) << "\n";
                }
                else
                {
                    std::cout << *(std::get<1>(ptr)) << "\n";
                }
            } 
        }
        std::cout << "\n";

        // returns the average salary of CodeTesters
        std::future<float> average = std::async(std::launch::async, AverageSalaryOfCodeTesters, std::ref(employees));
        std::cout << "Average salary of Code Testers=" << average.get() << "\n";
        std::cout << "\n";

        // returns the skill set of passed employee id
        std::future<std::optional<std::vector<SkillSet>>> skill = std::async(std::launch::async, SkillsetOfPassedId, std::ref(employees), "101");
        if (std::optional<std::vector<SkillSet>> result = skill.get(); result.has_value())
        {
            std::cout << "Skill set of passed employee Id :";
            for (SkillSet& skill : result.value())
            { 
                    switch (skill)
                    {
                    case SkillSet::CODING:
                        std::cout << "Coding";
                        break;
                    case SkillSet::INTEGRATION_TESTING:
                        std::cout << "Integration_Testing";
                        break;
                    case SkillSet::UNIT_TESTING:
                        std::cout << "Unit Testing";
                        break;
                    case SkillSet::CODE_REVIEW:
                        std::cout << "Code review";
                        break;
                    };
                    std::cout<<" , ";
            }
            std::cout<<"\n";
        }
        else
        {
            std::cout << "No matching Id found!!\n";
        }
        std::cout << "\n";

        // returns true or false if salary is above 60000 then true else false
        std::future<bool> salaryAbove60000 = std::async(std::launch::async, IsSalaryAbove60000, std::ref(employees));
        std::cout << "Is Salary above 60000:" << salaryAbove60000.get() << "\n";
        std::cout << "\n";

        // returns the calculated bonus using member function of corresponding classes
        std::future<std::optional<float>> bonus = std::async(std::launch::async, CalculateBonusOfEmployee, std::ref(employees), "101");
        if (std::optional<float> result = bonus.get(); result.has_value())
        {
            std::cout << "Bonus of passed employee Id =" << result.value() << "\n";
        }
        else
        {
            std::cout << "No matching Id found!!\n";
        }
        std::cout << "\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }
}