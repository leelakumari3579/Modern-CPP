#include <variant>
#include <array>
#include <iostream>

int main()
{
    std::variant<int, float> v1; // upgraded verstion of union

    v1 = 10;
    std::visit([](auto &&val) { std::cout <<val<< "\n"; }, v1);

    v1 = 10.21f;

    std::array<std::variant<int, float>, 3> data{10,10.3f,23};

    for (std::variant<int, float> &v : data)
    {
        std::visit([](auto &&val) { std::cout <<val<< "\n"; }, v);
    }
}