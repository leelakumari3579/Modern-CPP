#include "Functionalities.h"
#include<numeric>
#include<algorithm>

void createObjects(Container &data)
{
    data.push_back(std::make_shared<Developer>("1","Varma",60001,7,skills {SkillSet::CODE_REVIEW,SkillSet::CODING_UNIT}));
    data.push_back(std::make_shared<CodeTester>("2","Mallika",50001,4,skills {SkillSet::INTEGRATION_TESTING,SkillSet::CODING_UNIT,SkillSet::TESTING_CODE}));
    data.push_back(std::make_shared<Developer>("3","Bhagya",70001,3,skills {SkillSet::CODE_REVIEW,SkillSet::CODING_UNIT}));

}

Container EmployeeAbove6yrsExper(Container &data)
{   
    if(data.empty()) throw EmptyContainer("NO elements in the container");
     Container result;
    std::for_each(data.begin(),data.end(),[&](const EmployeePointer& obj){
            if(std::holds_alternative<DeveloperPointer>(obj)){
                if(std::get<DeveloperPointer>(obj)->experienceYears()>6){
                    result.push_back(obj);
                }
            }else{
                 if(std::get<CodeTesterPointer>(obj)->experienceYears()>6){
                    result.push_back(obj);
                }
            }
    });
    return result;
}

float findAvgSalaryCodeTester(Container &data)
{   
    if(data.empty()) throw EmptyContainer("NO elements in the container");
    float ans=0.0;
    int freq=0;
     std::for_each(data.begin(),data.end(),[&](const EmployeePointer& obj){
            if(std::holds_alternative<CodeTesterPointer>(obj)){
               ans+=std::get<CodeTesterPointer>(obj)->salary();
               freq++;
            }
    }); 
    if(freq==0)  {
        throw NoCodeTester("No Code Testwer");
    }
    return ans/freq;
}

std::optional<skills> FindSkills(Container &data, std::string id)
{   
    if(data.empty()) throw EmptyContainer("NO elements in the container");
     skills result;
    for(const EmployeePointer& obj:data){
            if(std::holds_alternative<DeveloperPointer>(obj)){
                if(std::get<DeveloperPointer>(obj)->id()==id){
                    for(const auto& val:std::get<DeveloperPointer>(obj)->skill()){
                        result.push_back(val);
                    }   break;

                }
            }else{
                 if(std::get<CodeTesterPointer>(obj)->id()==id){
                     for(const auto& val:std::get<CodeTesterPointer>(obj)->skill()){
                        result.push_back(val);
                    }
                    break;
                }
            }
    };
    if(result.empty())
    return std::nullopt;
    return result;
}

bool isSalaryGreaterThan60000(Container &data)
{   
    if(data.empty()) throw EmptyContainer("NO elements in the container");
    return std::any_of(data.begin(),data.end(),[&](const EmployeePointer& obj){
             if(std::holds_alternative<DeveloperPointer>(obj)){
                if(std::get<DeveloperPointer>(obj)->salary()>60000){
                    return true;
                }
            }else{
                 if(std::get<CodeTesterPointer>(obj)->salary()>60000){
                    return true;
                }
            }
            return false;
    });
}

std::optional<float> GetBonus(Container &data, std::string id)
{   
    if(data.empty()) throw EmptyContainer("NO elements in the container");
    for(const EmployeePointer& obj:data){
            if(std::holds_alternative<DeveloperPointer>(obj)){
                if(std::get<DeveloperPointer>(obj)->id()==id){
                    return std::get<DeveloperPointer>(obj)->CalculateBonus();
                }
            }else{
                 if(std::get<CodeTesterPointer>(obj)->id()==id){
                    return std::get<CodeTesterPointer>(obj)->CalculateBonus();
                }
            }
    };
    return std::nullopt;

}
