#include "ThreadHandler.h"
// #include "Functionalities.h"
#include <iostream>
#include <algorithm>


void ThreadHandler::InputCapture(std::vector<int> &data)
{
    std::cout << "enter 5 elements: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> _n[i];
        data.emplace_back(_n[i]);
    }
    _flag = true;
    cv.notify_one();
}

void ThreadHandler::Operation()
{
    std::unique_lock<std::mutex> lk(mt);
    cv.wait(lk,[&](){return _flag;});
    std::for_each(
        _n.begin(),
        _n.end(),
        [](const int& val) {
            std::cout<<"Squares: "<<val*val;
        }
    );
}

std::ostream &operator<<(std::ostream &os, const ThreadHandler &rhs) {
    os << "Vector of integers: " << rhs._n;
    return os;
}
