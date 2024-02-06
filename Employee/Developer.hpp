#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP
#include "Employee.hpp"
#include "DeveloperDepartment.hpp"
#include <iostream>

class Developer : public Employee
{
private:
    int _experiance;
    DeveloperDepartment _department;
public:
    Developer() = delete;
    Developer(const Developer&) = default;  //copy constructor
    Developer& operator=(const Developer&) = delete;
    Developer(Developer&&) = delete; //moving constructor
    Developer& operator=(Developer&&) = delete;
    ~Developer(){std::cout<<"developer distructor"<<std::endl;}

    Developer(int id, std::string name, float salary,int experiance, DeveloperDepartment department);

    float CalculateTax() override;

    int experiance() const { return _experiance; }
    void setExperiance(int experiance) { _experiance = experiance; }

    DeveloperDepartment department() const { return _department; }
    void setDepartment(const DeveloperDepartment &department) { _department = department; }
};




#endif // DEVELOPER_HPP
