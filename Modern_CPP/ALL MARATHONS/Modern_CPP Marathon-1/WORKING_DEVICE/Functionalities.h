#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Device.h"
#include"WorkingDevice.h"
#include<memory>
#include<vector>

using DevicePointer=std::shared_ptr<Device>;
using DeviceContainer=std::vector<DevicePointer>;

using WorkingDevicePointer=std::shared_ptr<WorkingDevice>;

void CreateObjects(DeviceContainer& deviceData);

//void CreateObjects(WorkingDeviceContainer& workingDeviceData);



// float FindTaxAmount(Device& d1);

// void Sar_ValueAndPriceOfDevice(Device& d);

// void IdAndNameOfDevice(Device& d);


void FindTaxAmount(DevicePointer& device);

void Sar_ValueAndPriceOfDevice(DevicePointer& device);

void IdAndNameOfDevice(DevicePointer& device);




#endif // FUNCTIONALITIES_H
