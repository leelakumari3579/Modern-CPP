#include <iostream>
#include <variant>
#include <vector>
#include <memory>

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

using EPointer = std::shared_ptr<Employee>;
using BPointer = std::shared_ptr<BusinessOwner>;

int main()
{
    std::vector<std::variant<EPointer, BPointer>> data(4);
    data[0] = std::make_shared<BusinessOwner>();
    data[1] = std::make_shared<Employee>();

    for(auto&& val : data)
    {
        std::visit([](auto&& val){val->Display();}, val);
    }
}
