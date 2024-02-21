#include <iostream>
#include "header.h"
#include <cstring>

int main()
{
    int n;
    std::cout << "press 1 to add inventory objects to stocks " << std::endl;
    std::cout << "press 2 to sale products from balance stock " << std::endl;
    std::cout << "press 3 to search products from balance stock " << std::endl;
    std::cout << "press 4 to exit " << std::endl;
    std::cin >> n;
    Inventory *inv = new Inventory[n];
    switch(n)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            inv[i].purchase();
        }
        break;
    case 2:
        int noofsp;
        for (int i = 0; i < n; i++)
        {

            std::cout << "enter no of sale products:" << std::endl;
            std::cin >> noofsp;
            inv[i].sale(noofsp);
        }
        break;
    case 3:
        // std::string c;
        // std::cout << "enter the name to search:" << std::endl;
        // std::cin >> c;
        // int m=inv[i].search(c);
        
        break;
    case 4:
        break;
    }
    delete []inv;
}