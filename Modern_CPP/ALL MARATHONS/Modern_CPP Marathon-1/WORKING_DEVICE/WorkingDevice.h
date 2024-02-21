#ifndef WORKINGDEVICE_H
#define WORKINGDEVICE_H

#include<string>
#include <ostream>
#include"Device.h"
#include"DeviceType.h"

class WorkingDevice: public Device
{
    private:
        float _sar_value {1.0f};
        DeviceType _type;
    public:
        //constructors
        WorkingDevice()=default;
        WorkingDevice(const WorkingDevice&)=default;
        WorkingDevice& operator=(const WorkingDevice&)=delete;
        WorkingDevice(const WorkingDevice&&)=delete;
        WorkingDevice& operator=(const WorkingDevice&&)=delete;
        ~WorkingDevice()=default;

        //member function
        void FindDiscountPrice() override;
        WorkingDevice(std::string id,std::string name,float price,float sar_value,DeviceType deviceType);

        //getter and setters
        float sarValue() const { return _sar_value; }

        DeviceType type() const { return _type; }

        friend std::ostream &operator<<(std::ostream &os, const WorkingDevice &rhs);


         
};

#endif // WORKINGDEVICE_H
