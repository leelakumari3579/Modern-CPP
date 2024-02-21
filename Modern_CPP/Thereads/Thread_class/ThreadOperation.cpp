#include <iostream>
#include "ThreadOperation.h"

inline std::ostream &operator<<(std::ostream &os, const ThreadOperation &rhs) {
    os << " _value: " << rhs._value;
    return os;
}

void ThreadOperation::Square()
{
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"Square: "<<_value*_value<<"\n";
}

void ThreadOperation::Cube()
{
    //std::lock_guard<std::mutex> lg(mt);
    std::unique_lock<std::mutex> lk(mt);
    cv.wait(lk,[&](){return _cube_val_avilable;});
    std::cout<<"Cube: "<<_value*_value *_value<<"\n";
}

void ThreadOperation::Produce_value_for_cube()
{
    std::cout<<"enter the value: ";
    std::cin>>_value;
    _cube_val_avilable = true;
    cv.notify_one();
}
