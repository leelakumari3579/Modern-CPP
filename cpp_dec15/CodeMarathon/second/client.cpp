#include <iostream>
#include <cstring>
#include"header.h"

int main()
{
    int n;
    std::cout<<"enter n value "<<std::endl;
    std::cin>>n;
    Bike *b1=new Bike[n];
    for(int i=0;i<n;i++)
    {
        std::cout<<"enter vehicle details "<<std::endl;
        b1[i].accept();
    }
    int ChNum;
    std::cout<<"enter chassis number "<<std::endl;
    std::cin>>ChNum;
    for(int i=0;i<n;i++)
    {
        b1[i].ByChassisNumber(ChNum);
    }
    for(int i=0;i<n;i++)
    {
        std::cout<<"count of same category "<<b1[i].GetByCategory(SUV,n,b1[i])<<std::endl;
    }
    for(int i=0;i<n;i++)
    {
        std::cout<<"average price of vehicles "<<b1[i].avgPrice(SUV)<<std::endl;
    }
    Car *c1=new Car[n];
    delete []b1;
    delete []c1;
}