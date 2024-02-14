#include <iostream>
#include <variant> //like union
#include <array>

using VType = std::variant<int, std::string>;
using Container = std::array<VType, 5>;

void Operation(const Container& data)
{
    for(const VType& V : data)
    {
        // Both operations will be done with these two lines
        // auto f1 = [](auto&& val) {std::cout<<val<<"\n";};
        // std::visit(f1,V);
        
        //different operations in each data types
        if(std::holds_alternative<int>(V))
        {
            int data = std::get<0>(V);
            std::cout<<data*data<<"\n";
        }
        else
        {
            std::string temp = std::get<1>(V);
            std::cout<<temp<<".........."<<temp.length()<<"\n";
        }
    }
}

int main()
{
    Container data;
    data[0] = 10;
    data[1] = 11;
    data[2] = "c++";
    data[3] = 13.9f;
    data[4] = "harsh";

    Operation(data);
}