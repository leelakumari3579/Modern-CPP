#include"Functionalities.h"
#include<memory>
#include"WorkingDevice.h"

void CreateObjects(DeviceContainer& deviceData)
{
    deviceData.emplace_back(
    std::make_shared<WorkingDevice>
    (
        "D101",
        "TV",
        45000.0f,
           1.0f,
           DeviceType::ACCESSORY
        )
    
    );

    deviceData.emplace_back(
    std::make_shared<WorkingDevice>
    (
        "D102",
        "WASHING MACHINE",
        95000.0f,
           1.5f,
           DeviceType::ACCESSORY
        )
    
    );

    deviceData.emplace_back(
    std::make_shared<WorkingDevice>
    (
        "D103",
        "VIVO",
        35000.0f,
           1.8f,
           DeviceType::MOBILE
        )
    );

    deviceData.emplace_back(
    std::make_shared<Device>
    (
        "D104",
        "DELL",
        90000.0f,
           1.3f,
           DeviceType::WORKSTATION
        )
    
    );

}

void FindTaxAmount(DevicePointer& device)
{
    if(std::dynamic_pointer_cast<WorkingDevice>(device)==nullptr){
        throw std::runtime_error("No type of Working Device");
    }

    WorkingDevicePointer workDevice=std::dynamic_pointer_cast<WorkingDevice>(device);

    if(workDevice->sarValue()<=1.0 && workDevice->sarValue()>=1.5)
    {
        if(workDevice->type()==DeviceType::MOBILE){
            std::cout<<"The Tax Price is:"<<0.18*workDevice->price()<<std::endl;
        }
        else if(workDevice->type()==DeviceType::ACCESSORY || workDevice->type()==DeviceType::WORKSTATION)
        {
            std::cout<<"The Ta Price is:"<<0.12*workDevice->price()<<std::endl;
        }
        else
        {
            std::cout<<"The Ta price is:"<<0.28*workDevice->price()<<std::endl;
        }
    }
}

void Sar_ValueAndPriceOfDevice(DevicePointer &device)
{
    WorkingDevicePointer workDevice=std::dynamic_pointer_cast<WorkingDevice>(device);
    if(workDevice==nullptr)
    {
        throw std::runtime_error("No type of Working Device");
    }
    std::cout<<"The Sar Value is"<<workDevice->sarValue()<<std::endl;
    std::cout<<"The price of device is:"<<workDevice->price()<<std::endl;
}

void IdAndNameOfDevice(DevicePointer &device)
{
    WorkingDevicePointer workDevice=std::dynamic_pointer_cast<WorkingDevice>(device);
    if(workDevice==nullptr)
    {
        throw std::runtime_error("No type of working Device");
    }
    if(workDevice->type()==DeviceType::MOBILE)
    {
        std::cout<<"The Id of the Car is:"<<workDevice->id()<<std::endl;
    }
    else 
    {
        std::cout<<"The name of the Car is:"<<workDevice->name()<<std::endl;
    }
}
