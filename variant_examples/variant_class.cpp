#include <iostream>
#include <variant>
#include <vector>

class Employee
{
private:
    /* data */
public:
    Employee() = default;
    ~Employee() {std::cout<<"Object1 destroyed\n";}
    void Display(){std::cout<<"Employee siuuu!\n";}
};

class BusinessOwner
{
private:
    /* data */
public:
    BusinessOwner() = default;
    ~BusinessOwner() {std::cout<<"Object2 destroyed\n";}
    void Display(){std::cout<<"BusinessOwner siuuu!\n";}
};

int main()
{
    std::vector<std::variant<Employee, BusinessOwner>> data(2);
    data[0] = Employee();
    data[1] = BusinessOwner();

    // std::visit([](auto&& val){val.Display();});
    for(auto&& val : data)
    {
        std::visit([](auto&& val){val.Display();}, val);
    }
}
