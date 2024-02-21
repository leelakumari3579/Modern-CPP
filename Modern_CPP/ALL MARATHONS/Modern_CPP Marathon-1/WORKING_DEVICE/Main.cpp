#include<iostream>
#include"Functionalities.h"


int main()
{
    DeviceContainer deviceData;
    CreateObjects(deviceData);

    //find Tax Amount of particular Device SmartPointer
    std::cout<<"Tax Amount:"<<std::endl;
    try
    {
          FindTaxAmount(deviceData[0]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //Display SAR and Price of Device
    std::cout<<"Display SAR and Price of Device"<<std::endl;
    try 
    {
        Sar_ValueAndPriceOfDevice(deviceData[0]);
    }
    catch(const std::exception& e)
    {
        std::cerr<<e.what()<<"\n";
    }
    return 0;

}