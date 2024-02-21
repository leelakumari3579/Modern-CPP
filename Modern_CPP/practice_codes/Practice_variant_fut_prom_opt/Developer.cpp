#include "Developer.h"

Developer::Developer(std::string id, std::string name, float salary, int expYears,SkillSet skill)
    : _id(id), _name(name), _salary(salary), _experience_years(expYears), _skill(skill)
{
}

float Developer::CalculateBonus()
{
    if (_experience_years <= 5)
    {
        return _salary * 10 / 100;
    }
    return _salary * 20 / 100;
}
std::ostream &operator<<(std::ostream &os, const Developer &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _experience_years: " << rhs._experience_years
       << " _skill: ";
       switch (rhs._skill)
        {
        case SkillSet::CODING:
            os << "Coding";
            break;
        case SkillSet::INTEGRATION_TESTING:
            os << "Integration_Testing";
            break;
        case SkillSet::UNIT_TESTING:
            os << "Unit Testing";
            break;
        case SkillSet::CODE_REVIEW:
            os << "Code review";
            break;
        };
    return os;
}
