#include "Employee.hpp"
#include "HR.hpp"
#include "Developer.hpp"
#include <vector>
int main()
{
    Employee *ptr1 = new HR(101,"harsh",7800000.0f,10,HRSpecialization::TAG);
    Employee *ptr2 = new Developer(720,"nani",800000.0f, 5, DeveloperDepartment::WEB_DEVELOPER);
    std::vector<Employee*> data {ptr1,ptr2};
    /*
        ptr is of type Employee
        object is actual HR
        function is marked as virtual
        COMPILER go to BOTH LHS and RHS and FINDS THE MOST DERIVED VERSION!
    */

   for(Employee *ptr : data)
        std::cout<<"tax for Employee "<<ptr->eName()<<" is "<<ptr->CalculateTax()<<std::endl;

    //ptr1->CalculateTax();

    for(Employee *ptr : data)
        delete ptr; //Employee* ptr only calls ~Employee() destructor
}

//MRO - method resolution order ()