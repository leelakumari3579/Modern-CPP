#include <iostream>
#include "Functionalities.h"

int main()
{
    ElectronicVehiclePointerContainer eVehicleData;
    MotorContainer motorData;
    CreateObjects(eVehicleData, motorData);

    try
    {
        int result1 = ReturnMotorTorqueById(eVehicleData, "c102");
        std::cout << "Max Torque of c102 is " << result1 <<"\n";
    }
    catch (EmptyContainerException &e1)
    {
        std::cout << e1.what() << '\n';
    }
    catch (IdNotFoundException &e2)
    {
        std::cout << e2.what() << '\n';
    }

    try
    {
        float result2 = CalculateBatteryDrain(eVehicleData);
        std::cout << "Result of battery drain is " << result2 << "\n";
    }
    catch (EmptyContainerException &e1)
    {
        std::cout << e1.what() << '\n';
    }
    catch (NoMatchingInstanceException &e2)
    {
        std::cout << e2.what() << '\n';
    }

    std::cout<<"motor value of first and last value "
        <<OperatorAddForMotorValues(eVehicleData[0],eVehicleData[3]);
    
}

