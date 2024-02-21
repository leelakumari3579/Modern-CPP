#include <iostream>
#include <future>
#include <thread>
#include "Functionalities.h"

int main()
{
    Container data;
    std::future<void> createobj = std::async(std::launch::async, CreateObjects, std::ref(data));
    createobj.get();

    std::future<std::optional<Container>> result = std::async(std::launch::async, ReturnEmployeePointerByExperienceAbove6, std::ref(data));
    std::optional<Container> ans = result.get();
    if (ans.has_value())
    {
        for (std::variant<TesterPointer, DeveloperPointer> &ptr : ans.value())
        {
            if (std::holds_alternative<TesterPointer>(ptr))
            {
                std::cout <<*(std::get<0>(ptr))<<"\n";
            }
            else
            {
                std::cout<<*(std::get<1>(ptr))<<"\n";
            }
        }
    }

    std::future<float> average = std::async(std::launch::async,AverageSalaryOfCodeTesters,std::ref(data));
    std::cout<<"Average salary: "<<average.get()<<"\n";

    std::promise<std::string> pr;
    std::future<std::string> ft = pr.get_future();
    std::future<std::optional<SkillSet>> skill = std::async(std::launch::async,ReturnSkillSetByEmployeeId,std::ref(data),std::ref(ft));
    std::string id;
    std::cout<<"enter the value: ";
    std::cin>>id;
    pr.set_value(id);

    if(std::optional<SkillSet> reskill=skill.get();reskill.has_value())
    {
        std::cout<<"the skillset is: "<<"\n";
        switch (reskill.value())
        {
        case SkillSet::CODE_REVIEW:
            std::cout<<"Code Review"<<"\n";
            break;
        case SkillSet::CODING:
            std::cout<<"Coding"<<"\n";
            break;
        case SkillSet::UNIT_TESTING:
            std::cout<<"Unit Testing"<<"\n";
            break;
        case SkillSet::INTEGRATION_TESTING:
            std::cout<<"Integration Testing"<<"\n";
            break;
        default:
            break;
        }
    }

    std::future<bool> resalary = std::async(std::launch::async,ReturnBoolBySalaryAbove60k,std::ref(data));
    std::cout<<"salary above 60k is: "<<resalary.get()<<"\n";

    std::promise<std::string> pr2;
    std::future<std::string> ft2 = pr2.get_future();
    std::future<std::optional<float>> bonus = std::async(std::launch::async,EmployeeBonusFromMemberClass,std::ref(data),std::ref(ft2));
    std::string id2;
    std::cout<<"enter the value: ";
    std::cin>>id2;
    pr2.set_value(id2);

    if(std::optional<float> resbonus = bonus.get(); resbonus.has_value())
    {
        std::cout<<"Bonus: "<<resbonus.value()<<"\n";
    }
    else
    {
        std::cout<<"no matching id found!! \n";
    }

    std::thread th(NameById,std::ref(data),"202");
    if(th.joinable())
        th.join();
}