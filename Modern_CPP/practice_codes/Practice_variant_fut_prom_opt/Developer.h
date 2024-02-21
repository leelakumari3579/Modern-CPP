#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <string>
#include <ostream>
#include "SkillSet.h"
#include <vector>

class Developer
{
private:
    std::string _id{""};
    std::string _name{""};
    float _salary{0.0f};
    int _experience_years{0};
    SkillSet _skill{SkillSet::CODING};

public:
    Developer() = delete;
    Developer(const Developer &) = delete;
    Developer(Developer &&) = delete;
    Developer &operator=(Developer &&) = delete;
    Developer &operator=(const Developer &) = delete;
    ~Developer() = default;

    Developer(std::string id, std::string name, float salary, int expYears, SkillSet skill);
    // member functions
    float CalculateBonus();
    // getter and setter functions
    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }
    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }
    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }
    int experienceYears() const { return _experience_years; }
    void setExperienceYears(int experience_years) { _experience_years = experience_years; }

    SkillSet skill() const { return _skill; }
    void setSkill(const SkillSet &skill) { _skill = skill; }

    friend std::ostream &operator<<(std::ostream &os, const Developer &rhs);
};

#endif // DEVELOPER_H