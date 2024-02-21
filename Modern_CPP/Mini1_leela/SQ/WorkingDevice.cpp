#include "WorkingDevice.h"

WorkingDevice::WorkingDevice(std::string id, std::string name, float price, float sarValue, const DeviceType dType)
    :Device(id,name, price), _sar_value(sarValue),_type(dType)
{
}

void WorkingDevice::FunctionDiscountPrice()
{
     if(_type == DeviceType::MOBILE || _type == DeviceType::WORKSTATION)
    {
        std::cout<<"Dicount price of MOBILE or WORKSTATION is: "<<price() * 0.1f<<std::endl;
    }
    else if(_type == DeviceType::ACCESSORY)
    {
        std::cout<<"Dicount price of ACCESSORY is: "<<price() * 0.2f<<std::endl;
    }
}


std::ostream &operator<<(std::ostream &os, const WorkingDevice &rhs) {
    os << static_cast<const Device &>(rhs)
       << " _sar_value: " << rhs._sar_value
       << " _type: " << static_cast<int>(rhs._type);
    return os;
}
