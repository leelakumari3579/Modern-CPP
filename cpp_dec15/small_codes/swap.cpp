#include<iostream>
int swap(int &a,int &b)
{
    int temp=0;
    temp=a;
    a=b;
    b=temp;
    return a,b;
}
int main()
{
    int a,b;
    std::cout<<"enter a value "<<std::endl;
    std::cin>>a;
    std::cout<<"enter b value "<<std::endl;
    std::cin>>b;
    std::cout<<"before swap: "<<a<<" and "<<b<<std::endl;
    swap(a,b);
    std::cout<<"after swap: "<<a<<" and "<<b;
}