#include <iostream>

template <typename... Args>
auto add(Args... args)
{
    return (args + ...);
}

int main()
{
    int ans = add<int>(10, 20);
    std::cout << ans << "\n";
}