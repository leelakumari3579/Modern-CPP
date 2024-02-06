#include <iostream>
#include <array>
//c++17 feature -->structure binding
//work in only fixed sized --->array / tuple / pair
int main()
{
    auto [age, experiance] = std::array<int, 2>{23, 1}; //same data types in array metion size
    std::cout << age << "\n";
    auto [a,b] = std::pair<int, std::string> {120,"leela"}; //mention data types in pair
} 