#include "ThreadHandler.h"
#include <iostream>

void ThreadHandler::Operation()
{
    std::unique_lock<std::mutex> lk(_mt);
    _cv.wait(lk, [&](){
        return _isValAvailable;
    });
    int* data = new int[_N];
    std::cout << "Enter the values : ";
    for(int i=0;i<_N;i++) {
        std::cin >> data[i];
    }
    for(int i=0;i<_N;i++) {
        std::cout << "Square of Value : " << data[i] << " is " << data[i]*data[i] << "\n";
    }

}

bool ThreadHandler::InputCapture()
{
    std::cout << "Enter the value of N : ";
    std::cin >> _N;
    if(_N) {
        _isValAvailable = true;
        _cv.notify_one();
    }
    return false;
}
