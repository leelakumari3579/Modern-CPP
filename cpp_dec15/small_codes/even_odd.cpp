#include<iostream>
bool isEven(int n)
{
    return (n%2==0);
}
int main()
{
    int n;
    std::cout<<"enter n value "<<std::endl;
    std::cin>>n;
    if(isEven(n)==true)
        std::cout<<"even"<<std::endl;
    else
        std::cout<<"odd";
    return 0;
}