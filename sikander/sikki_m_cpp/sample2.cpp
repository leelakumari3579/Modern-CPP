#include<iostream>
#define TEMPLATE

#ifdef TEMPLATE
template <typename T>
T mymax(const T &a,const T &b)
{
    T large=a > b ? a:b;
    return large;
}
#else
int mymax(const int &a,const int &b)
{
    int large = a>b ? a:b;
    return large;
}
#endif
int main()
{
   std::cout << mymax(5,10);
   return 0;
}