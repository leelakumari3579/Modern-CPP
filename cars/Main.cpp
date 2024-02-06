#include"Functionlities.h"
#include<iostream>
void magic(const Car &c1)
{
    std::cout<<c1.price()<<std::endl;
}

int main()
{
    Car c1("1001",890000.0f,VehicleType::SEDAN);
    magic(c1);

    // const std::string s1 = "ha1435";
    // magic(s1);  //string s1 --->Car(std::string id) --->car object -->magic(object)

    /*
    if there is only 1 unknown parameter in a constructor(unknown)
    */

    int *ptr = (int*)malloc(4);
    container data;  //empty container

    CreateObjects(data);  //by reference to CreateObjects

    AveragePrice(data);

    FindPriceById(data, "v101ef");
    free(ptr);
}