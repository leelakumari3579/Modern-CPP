#include <iostream>
#include "ThreadOperation.h"

inline std::ostream &operator<<(std::ostream &os, const ThreadOperation &rhs) {
    os << " _value: " << rhs._value;
    return os;
}

void ThreadOperation::Square()
{
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<_value*_value<<"\n";
}

void ThreadOperation::Cube()
{
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<_value*_value *_value<<"\n";
}