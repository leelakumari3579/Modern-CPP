#include "Developer.hpp"

Developer::Developer(int id, std::string name, float salary, int experiance, DeveloperDepartment department)
    :Employee(id, name, salary),_experiance(experiance),_department(department)
{
}

float Developer::CalculateTax()
{
    return 0.3f * eSalary();
}
