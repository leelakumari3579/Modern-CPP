#include "WorkingDevice.h"

WorkingDevice::WorkingDevice(std::string id, std::string name, float price, float sar_value, DeviceType type)
:Device(id,name,price),_sar_value(sar_value),_type(type)
{
}

void WorkingDevice::FindDiscountPrice()
{
    if(_type==DeviceType::MOBILE || _type==DeviceType::WORKSTATION){
        std::cout<<"The Discount price is :"<<price()*0.1<<std::endl;
    }else{
        std::cout<<"The Discount price is :"<<price()*0.2<<std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const WorkingDevice &rhs) {
    os << static_cast<const Device &>(rhs)
       << " _sar_value: " << rhs._sar_value
       << " _type: " ;
    switch (rhs._type)
    {
    case DeviceType::ACCESSORY:
        os<<"DeviceType::ACCESSORY";
        break;
    case DeviceType::MOBILE:
        os<<"DeviceType::MOBILE";
        break;
    case DeviceType::WORKSTATION:
        os<<"DeviceType::WORKSTATION";
        break;
    }
    os<<"\n";
    return os;
}
