#ifndef CODETESTER_H
#define CODETESTER_H
#include<iostream>
#include<vector>
#include "SkillSet.h"
using skills=std::vector<SkillSet>;
class CodeTester
{
    private:
    const std::string _id;
    const  std::string _name;
    float _salary;
    int _experience_years;
    skills _skill;
    public:
        CodeTester()=delete;
        CodeTester(const CodeTester&)=delete;
        CodeTester(CodeTester&&)=delete;
        CodeTester& operator=(const CodeTester&)=delete;
        CodeTester& operator=(CodeTester&&)=delete;
        ~CodeTester()=default;
        
        CodeTester(const std::string id,const  std::string name,float salary,int experience_years,skills skill);


        std::string id() const { return _id; }
        std::string name() const { return _name; }
        float salary() const { return _salary; }
        int experienceYears() const { return _experience_years; }
        skills skill() const { return _skill; }

        float CalculateBonus();

        friend std::ostream &operator<<(std::ostream &os, const CodeTester &rhs);
};

#endif // CODETESTER_H
