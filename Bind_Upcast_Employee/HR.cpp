#include "HR.hpp"

std::ostream &operator<<(std::ostream &os, const HR &rhs) {
    os << static_cast<const Employee &>(rhs)
       << " _teamSize: " << rhs._teamSize
       << " _hrSpecialization: " << static_cast<int>( rhs._hrSpecialization );
    return os;
}
//dynamic_cast only work while you are using virtual function
//without virtual function we cannot use dynamic_cast

HR::HR(int id, std::string name, float salary, int size, HRSpecialization specialization)
    :Employee(id, name, salary),_teamSize(size), _hrSpecialization(specialization)
{
}

float HR::CalculateTax()
{
    return 0.2f * eSalary();
}
