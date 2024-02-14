#include <iostream>

// VARIANT TEMPLATES

/*
    If user passes N parameters of type T into the function,
    it is equal to one parameter <operator> fn(N-1)
*/

// + one operand -->return the same value
//e.g: +10 = 10

template<typename T>
T add(T n1)
{
    return n1;
}

template<typename T, typename... Args>
T add(T n1, Args... args)
{
    n1 + add(args...);
}