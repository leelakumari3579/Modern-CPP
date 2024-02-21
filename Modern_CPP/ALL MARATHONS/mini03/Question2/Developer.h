#ifndef DEVELOPER_H
#define DEVELOPER_H
#include<iostream>
#include<vector>
#include "SkillSet.h"
using skills=std::vector<SkillSet>;
class Developer
{
private:
   const std::string _id;
   const  std::string _name;
   float _salary;
   int _experience_years;
   skills _skill;
public:
    Developer()=delete;
    Developer(const Developer&)=delete;
    Developer(Developer&&)=delete;
    Developer& operator=(const Developer&)=delete;
    Developer& operator=(Developer&&)=delete;
    ~Developer()=default;

    Developer(const std::string id,const  std::string name,float salary,int experience_years,skills skill);

    std::string id() const { return _id; }
    std::string name() const { return _name; }
    float salary() const { return _salary; }
    int experienceYears() const { return _experience_years; }
    skills skill() const { return _skill; }

    float CalculateBonus();

    friend std::ostream &operator<<(std::ostream &os, const Developer &rhs);

};

#endif // DEVELOPER_H
