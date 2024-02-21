#include "Functionalities.h"

void CreateObjects(DeviceContainer &devices)
{
    devices.emplace_back(std::make_shared<WorkingDevice>("D1","wasin",90909,1.2,DeviceType::ACCESSORY));
    devices.emplace_back(std::make_shared<WorkingDevice>("D2","PrintingMachine",1238989,1.7,DeviceType::ACCESSORY));
    devices.emplace_back(std::make_shared<WorkingDevice>("D3","Purifer",910222,1.9,DeviceType::ACCESSORY));
    devices.emplace_back(std::make_shared<WorkingDevice>("D4","Cleaner",91233,1.3,DeviceType::ACCESSORY));
}

void FindTaxAmount(DevicePointer &device)
{   
    if(std::dynamic_pointer_cast<WorkingDevice>(device)==nullptr){
        throw std::runtime_error("No type of Working Device");
    }
    WorkingDevicePointer workDevice=std::dynamic_pointer_cast<WorkingDevice>(device);
    /* Type casting the Device Pointer to Working Device*/
    if(workDevice->sarValue()<=1.0 && workDevice->sarValue()>=1.5){
        if(workDevice->type()==DeviceType::MOBILE){
            std::cout<<"The Tax Price is: "<<0.18*workDevice->price()<<std::endl;
        }
        else if(workDevice->type()==DeviceType::ACCESSORY || workDevice->type()==DeviceType::WORKSTATION){
            std::cout<<"The Tax Price is: "<<0.12*workDevice->price()<<std::endl;
        }
    }
    else{
        std::cout<<"The Tax Price is: "<<0.28*workDevice->price()<<std::endl;
    }
}

void DisplaySarAndPrice(DevicePointer &device)
{   
    WorkingDevicePointer workDevice=std::dynamic_pointer_cast<WorkingDevice>(device);
    if(workDevice==nullptr){
        throw std::runtime_error("No type of Working Device");
    }
    std::cout<<"The Sar Value is :"<<workDevice->sarValue()<<std::endl;
    std::cout<<"The Price of device is :"<<workDevice->price()<<std::endl;
}

void DisplayIdName(DevicePointer &device)
{
    WorkingDevicePointer workDevice=std::dynamic_pointer_cast<WorkingDevice>(device);
     if(workDevice==nullptr){
        throw std::runtime_error("No type of Working Device");
    }
    if(workDevice->type()==DeviceType::MOBILE){
         std::cout<<"The Id of the Car is :"<<workDevice->id()<<std::endl;
       
    }else{
         std::cout<<"The name of Car is :"<<workDevice->name()<<std::endl;
    }
}
