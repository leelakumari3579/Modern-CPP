// #include <vector>

// int main()
// {
//     std::vector<int> data {10,20,30};
// }

#include <memory>
#include "Employee.hpp"
#include "HR.hpp"
#include "Developer.hpp"

int main()
{
    std::shared_ptr<Employee> ptr = std::make_shared<HR>(202,"leela",900000.0f,3,HRSpecialization::RECRUITMENT);

    //HR has a getter called hrTeamSize()  --> for this we use dynamic pointer cast (upcast)

    std::shared_ptr<HR> fullPtr = std::dynamic_pointer_cast<HR>(ptr);
    fullPtr->teamSize(); //works
}