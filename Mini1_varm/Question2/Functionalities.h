#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "WorkingDevice.h"
#include "memory"
#include<vector>

using DevicePointer =std::shared_ptr<Device>;

using WorkingDevicePointer=std::shared_ptr<WorkingDevice>;

using DeviceContainer =std::vector<DevicePointer>;

void CreateObjects(DeviceContainer &devices);

void FindTaxAmount(DevicePointer& device);

void DisplaySarAndPrice(DevicePointer& device);

void DisplayIdName(DevicePointer& device);

// void Display()

#endif // FUNCTIONALITIES_H
