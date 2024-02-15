#include <memory>
#include <stdexcept>
#include "Functionalities.h"

void CreateObjects(DevicePointerContainer &deviceData)
{
    deviceData.emplace_back(
        std::make_shared<WorkingDevice>("v101", "Laptop", 57000.0f, 1.0f, DeviceType::ACCESSORY));
    deviceData.emplace_back(
        std::make_shared<WorkingDevice>("s102", "mobile", 20000.0f, 1.3f, DeviceType::MOBILE));
    deviceData.emplace_back(
        std::make_shared<WorkingDevice>("t103", "AC", 40000.0f, 1.5f, DeviceType::WORKSTATION));
    deviceData.emplace_back(
        std::make_shared<WorkingDevice>("e104", "Laptop", 70000.0f, 2.0f, DeviceType::ACCESSORY));
}

void FindTaxAmount(DevicePointer &deviceData)
{
    WorkingDevicePointer workDevicePtr = std::dynamic_pointer_cast<WorkingDevice>(deviceData);

    if(workDevicePtr == nullptr)
        throw std::runtime_error("Empty data received");

    // for (DevicePointer &ptr : workDevicePtr)
    // {
        float tax = 0;
        if (workDevicePtr->sarValue() >= 1.0 && workDevicePtr->sarValue() <= 1.5)
        {
            if (workDevicePtr->type() == DeviceType::MOBILE)
            {
                tax = workDevicePtr->price() * 0.18f;
                std::cout << "MOBILE tax amount of sarValue between 1.0 and 1.5 is: " << workDevicePtr->price() + tax << std::endl;
            }
            else if (workDevicePtr->type() == DeviceType::WORKSTATION || workDevicePtr->type() == DeviceType::ACCESSORY)
            {
                tax = workDevicePtr->price() * 0.12f;
                std::cout << "WORKSTATION and ACCESSORY tax amount of sarValue between 1.0 and 1.5 is: " << workDevicePtr->price() + tax << std::endl;
            }
        }
        else if(workDevicePtr->sarValue() >= 1.5 && workDevicePtr->sarValue() <= 2.0)
        {
            tax = workDevicePtr->price() * 2.8f;
            std::cout << "Tax amount of sarValue between 1.5 and 2.0 is: " << workDevicePtr->price() + tax << std::endl;
        }
    //}
}

void PrintSarvaluePrice(DevicePointer &deviceData)
{
    WorkingDevicePointer workDevicePtr = std::dynamic_pointer_cast<WorkingDevice>(deviceData);

    if(workDevicePtr == nullptr)
        throw std::runtime_error("Empty data received");

    // for(DevicePointer &ptr : workDevicePtr)
    // {
        std::cout<<"Device SarValue: "<<workDevicePtr->sarValue()<<std::endl;
        std::cout<<"Device Price: "<<workDevicePtr->price()<<std::endl;
    //}
}

void PrintIdName(DevicePointer &deviceData)
{
    WorkingDevicePointer workDevicePtr = std::dynamic_pointer_cast<WorkingDevice>(deviceData);
    
    if(workDevicePtr == nullptr)
        throw std::runtime_error("Empty data received");
    // for(DevicePointer &ptr : deviceData)
    // {
        if(workDevicePtr->type() == DeviceType::MOBILE)
        {
            std::cout<<"Device Id: "<<workDevicePtr->id()<<std::endl;
        }
        else if(workDevicePtr->type() == DeviceType::WORKSTATION || workDevicePtr->type() == DeviceType::ACCESSORY)
        {
            std::cout<<"Device Name: "<<workDevicePtr->name()<<std::endl;
        }
    // }    
}
