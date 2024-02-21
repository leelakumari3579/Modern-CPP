#include <iostream>

template <typename... T>
auto subtract(T... n1)
{
    return (... - n1); // associative
}

int main()
{
    //((10 - 20) - 30)
    int ans = subtract<int>(10, 20, 30);
    std::cout << ans << "\n";
}