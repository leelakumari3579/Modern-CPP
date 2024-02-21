#ifndef WORKINGDEVICE_H
#define WORKINGDEVICE_H
#include "Device.h"
#include "DeviceType.h"
#include <ostream>
class WorkingDevice: public Device
{
private:
    const float _sar_value {1.0f};// {1.0 to 2.0}
    const DeviceType _type;
public:
    WorkingDevice()=delete;
    WorkingDevice(const WorkingDevice&)=delete;
    WorkingDevice(WorkingDevice&&)=delete;
    WorkingDevice& operator=(const WorkingDevice&)=delete;
    WorkingDevice& operator=(WorkingDevice&&)=delete;
    ~WorkingDevice()=default;

    /*getters*/
    float sarValue() const { return _sar_value; }
    DeviceType type() const { return _type; }
    
    /* Parametric*/
    WorkingDevice(std::string id,std::string name,float price,float sar_value,DeviceType type);
   
    /*Overidden  */
    void FindDiscountPrice() override;

    friend std::ostream &operator<<(std::ostream &os, const WorkingDevice &rhs);

};

#endif // WORKINGDEVICE_H
