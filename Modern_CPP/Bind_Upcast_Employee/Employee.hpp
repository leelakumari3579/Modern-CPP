#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <string>
#include <iostream>

class Employee
{
private:
    int _eId;
    std::string _eName;
    float _eSalary;
public:
    Employee() = delete;
    Employee(const Employee&) = default;  //copy constructor
    Employee& operator=(const Employee&) = delete;
    Employee(Employee&&) = delete; //moving constructor
    Employee& operator=(Employee&&) = delete;
    virtual ~Employee() {std::cout<<"employee distructor"<<std::endl;}

    Employee(int id, std::string name, float salary);

    virtual float CalculateTax() = 0;

    int eId() const { return _eId; }
    std::string eName() const { return _eName; }
    float eSalary() const { return _eSalary; }
    void setESalary(float eSalary) { _eSalary = eSalary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};


#endif // EMPLOYEE_HPP
