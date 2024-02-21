#include <iostream>
#include "Functionalities.h"

int main()
{
    DevicePointerContainer deviceData;

    CreateObjects(deviceData);
    FindTaxAmount(deviceData[0]);
    PrintSarvaluePrice(deviceData[0]);
    PrintIdName(deviceData[0]);
}