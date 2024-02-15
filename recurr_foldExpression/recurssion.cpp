#include <iostream>

// fn(x,y,z)     =     x + fn(y,z)     =      x + y + fn(z)       =       x + y + z

//variadic templates
template <typename T>
T add(T n1)
{
    return n1;
}

/*
    accept first argument of some type T
    accept atleast one or more parameters after that where the type is args(could be different than three)
*/
template <typename T, typename... Args> // ...(elipsis operator)
T add(T n1, Args... args)
{
    // from whatever user send, separate first parameter
    // recurssively call add on the remaining on 
    return n1 + add(args...);// this line only works when + operator is overloaded fpor type T
}

int main()
{
    int ans = add<int>(10, 20);
    std::cout << ans << "\n";
}