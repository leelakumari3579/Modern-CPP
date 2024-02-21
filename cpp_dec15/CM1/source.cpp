#include<iostream>
#include"header.h"
#include<cstring>

Inventory::Inventory(std::string, int, int)
{
}

Inventory::Inventory()
{
}

void Inventory::purchase()
{
    std::cout<<"enter product description";
    std::cin>>description_of_product;
    std::cout<<"enter product code";
    std::cin>>balancestrock;
    std::cout<<"enter product balance stock";
    std::cin>>productcode;
    
}

void Inventory::sale(int)
{

}

void Inventory::search(int pcode)
{
    if( productcode == pcode ){
        
    }
}
