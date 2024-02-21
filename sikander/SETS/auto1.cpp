#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
template <class T>
T Tgreater(T a, T b)
{
    return a > b ;
}
//g++ auto1.cpp -fconcepts
auto isgreater(auto a, auto  b)
{                                   //a=11;
    auto  x=10;
    cout << x <<endl;
    x++;
    cout << x <<endl;
    return a>b ;
}
int main()
{
    
    int a=10;
    double b=21.3;
    cout << isgreater(a,b) << endl;
    cout << isgreater(a,b) << endl;
    cout << isgreater(a,b) << endl;
    return 0;
}