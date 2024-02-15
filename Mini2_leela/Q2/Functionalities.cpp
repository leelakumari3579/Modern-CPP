#include "Functionalities.h"

void CreateObjects(ElectronicVehiclePointerContainer &eVehicleData, MotorContainer &motorData)
{
    motorData.emplace_back(
        Motor(73.0f, 500.0f, 300));
    motorData.emplace_back(
        Motor(40.0f, 540.0f, 112));
    motorData.emplace_back(
        Motor(58.0f, 480.0f, 480));
    motorData.emplace_back(
        Motor(89.0f, 700.0f, 230));

    auto itr = motorData.begin();

    eVehicleData.emplace_back(
        std::make_shared<ElectronicVehicle>("c101", "Honda", BatteryType::LITHIUM_ION, 25.0f, *itr++));
    eVehicleData.emplace_back(
        std::make_shared<ElectronicVehicle>("c102", "BMW", BatteryType::NICKEL_METAL_HYDRIDE, 59.0f, *itr++));
    eVehicleData.emplace_back(
        std::make_shared<ElectronicVehicle>("c103", "Honda", BatteryType::LITHIUM_ION, 48.0f, *itr++));
    eVehicleData.emplace_back(
        std::make_shared<ElectronicVehicle>("c104", "Hyundi", BatteryType::NICKEL_METAL_HYDRIDE, 30.0f, *itr++));
}

int ReturnMotorTorqueById(ElectronicVehiclePointerContainer &eVehicleData, std::string id)
{
    if(eVehicleData.empty())
        throw EmptyContainerException("Container is empty!!");
    for (ElectronicVehiclePointer &ptr : eVehicleData)
    {
        if (ptr->id() == id)
        {
            if (ptr->batteryCapacity() > 30.3f)
            {
                return ptr->motor().get().maxTorque();
            }
        }
    }
    throw IdNotFoundException("Given id not found in Container!");
}

float CalculateBatteryDrain(ElectronicVehiclePointerContainer &eVehicleData)
{
    if(eVehicleData.empty())
        throw EmptyContainerException("Container is empty!!");
    float dischargeVal = 0.0f;
    for (ElectronicVehiclePointer &ptr : eVehicleData)
    {
        if (ptr->batterytype() == BatteryType::LITHIUM_ION)
        {
            dischargeVal = ptr->batteryCapacity() * 0.1f;
        }
        else
        {
            dischargeVal = 0.1 * ptr->motor().get().maxTorque() + 0.2 * ptr->motor().get().maxPower();
        }
    }
    if(dischargeVal == 0.0f)
        throw NoMatchingInstanceException("No matching data found!");
    return dischargeVal;
}

// std::vector<ElectronicVehicle> FilterData(ElectronicVehiclePointerContainer &eVehicleData, LambdaExpression &lambda)
// {
//     std::vector<ElectronicVehicle> result;
//     auto lambda = [](ElectronicVehiclePointerContainer &eVehicleData)->std::vector<ElectronicVehicle>  {
//         for(ElectronicVehiclePointer &ptr : eVehicleData)
//         {
//             return *ptr;
//         }
//     };
//     result.emplace_back(lambda);
// }

Motor OperatorAddForMotorValues(ElectronicVehiclePointer &ev1, ElectronicVehiclePointer &ev2)
{
    return ev1->motor().get()+ev2->motor().get();
}
