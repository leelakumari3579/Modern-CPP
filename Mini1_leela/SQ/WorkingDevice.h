#ifndef WORKINGDEVICE_H
#define WORKINGDEVICE_H

#include <iostream>
#include "DeviceType.h"
#include "Device.h"

class WorkingDevice : public Device
{
private:
    float _sar_value;
    const DeviceType _type;
public:
    WorkingDevice() = default;                       //default constructor
    WorkingDevice(const WorkingDevice &) = delete;             // deleted copy constructor
    ~WorkingDevice() = default;                      // defaulted destructor
    WorkingDevice &operator=(const WorkingDevice &) = delete;  // deleted assignment operator overloading
    WorkingDevice &operator=(const WorkingDevice &&) = delete; // new concept! (move assignment)
    WorkingDevice(const WorkingDevice &&) = delete;  

    WorkingDevice(std::string id, std::string name, float price, float sarValue, const DeviceType dType);
    void FunctionDiscountPrice() override;

    float sarValue() const { return _sar_value; }
    void setSarValue(float sar_value) { _sar_value = sar_value; }

    DeviceType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const WorkingDevice &rhs);

};


#endif // WORKINGDEVICE_H
