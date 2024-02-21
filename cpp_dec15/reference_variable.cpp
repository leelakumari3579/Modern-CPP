#include<iostream>
void fun(int &a) //pass by reference
{
    a=100;  //reference refers to exiting block of memory
    std::cout<<a<<std::endl;
}
//void fun(int m) //pass by value
void fun(int *m) //pass by address
{

}
int main()
{
    int y=20;
    fun(y);
    //fun(10); -->reference must be non constant
    std::cout<<y<<std::endl;

    int a=10,b=20;
    int &r=a;
    std::cout<<a<<std::endl; //10
    std::cout<<b<<std::endl; //20
    std::cout<<r<<std::endl; //10
    r=b; //ssame as a=b;
    std::cout<<a<<std::endl; //20
    std::cout<<b<<std::endl; //20
    std::cout<<r<<std::endl; //20
}
// pointers are flexible
// references are rigid