#include "Functionalities.h"
#include <iostream>

void AcceptData(ThreadContainer &data)
{
    std::vector<int> n{0, 0, 0, 0};
    int num{0};
    std::cout << "enter 5 elements: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> num;
        n.emplace_back(num);
    }
    data.emplace_back(n);
}