#include "Developer.hpp"

Developer::Developer(int id, std::string name, float salary, int experiance, DeveloperDepartment department)
    :Employee(id, name, salary),_experiance(experiance),_department(department)
{
}

float Developer::CalculateTax()
{
    return 0.3f * eSalary();
}

std::ostream &operator<<(std::ostream &os, const Developer &rhs) {
    os << static_cast<const Employee &>(rhs)
       << " _experiance: " << rhs._experiance
       << " _department: " << static_cast<int>(rhs._department);
    return os;
}
