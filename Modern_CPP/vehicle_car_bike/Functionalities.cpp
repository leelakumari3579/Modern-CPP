#include "Functionalities.h"

void createObjects(DataContainer &data)
{
    data.emplace_back(
        std::make_shared<Car>(CarType::SEDAN, "v101", 890000.0f, VehicleType::COMMERCIAL)
    );
    data.emplace_back(
        std::make_shared<Car>(CarType::SUV, "s101", 1890000.0f, VehicleType::COMMERCIAL)
    );
    data.emplace_back(
        std::make_shared<Car>(CarType::SEDAN, "h101", 590000.0f, VehicleType::PRIVATE)
    );
}

float CalculateTotalRegistrationTax(const DataContainer &data)
{
    if(data.empty())
        throw std::runtime_error("Empty data received");
    float total = 0.0f;
    for(const VehiclePointer& ptr : data)
        total = total + ptr->CalculateRegistrationTax();
    return total;
}
