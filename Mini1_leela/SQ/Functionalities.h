#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <vector>
#include "WorkingDevice.h"

using DevicePointer = std::shared_ptr<Device>;
using DevicePointerContainer = std::vector<DevicePointer>;
using WorkingDevicePointer = std::shared_ptr<WorkingDevice>;

void CreateObjects(DevicePointerContainer& deviceData);
void FindTaxAmount(DevicePointer& deviceData);
void PrintSarvaluePrice(DevicePointer& deviceData);
void PrintIdName(DevicePointer& deviceData);

#endif // FUNCTIONALITIES_H


