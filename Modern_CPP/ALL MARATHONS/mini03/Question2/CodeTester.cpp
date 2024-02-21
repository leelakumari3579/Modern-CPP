#include "CodeTester.h"

CodeTester::CodeTester(const std::string id, const std::string name, float salary, int experience_years, skills skill)
:_id(id),_name(name),_salary(salary),_experience_years(experience_years),_skill(skill)
{
}

float CodeTester::CalculateBonus()
{
     if(_experience_years<=5){
        return 0.5*_salary;
    }
    return 0.1*_salary;
}
std::ostream &operator<<(std::ostream &os, const CodeTester &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _experience_years: " << rhs._experience_years
       << " _skills are like : ";
    for(auto& skl:rhs._skill){
        switch (skl)
        {
        case SkillSet::CODE_REVIEW:
           os<<" CODE_REVIEW "<<" ";
            break;
        case SkillSet::CODING_UNIT:
            /* code */
            os<<"CODING_UNIT "<<" ";
            break;
        case SkillSet::INTEGRATION_TESTING:
            os<<" INTEGRATION_TESTING "<<" ";
            /* code */
            break;
        case SkillSet::TESTING_CODE:
            os<<" TESTING_CODE "<<" ";
            break;
        }
    }
    os<<"\n";
    return os;
}
