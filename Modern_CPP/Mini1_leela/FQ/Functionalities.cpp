#include <stdexcept>
#include "Functionalities.h"

void CreateObjects(CarPointerContainer &carData)
{
    carData.emplace_back(
        std::make_shared<Car>(
            "v101ef",
            780000.0f,
            ChassisType::EV,
            PermitType::PRIVATE
        )
    );
    carData.emplace_back(
        std::make_shared<Car>(
            "x102ef",
            890000.0f,
            ChassisType::ICE,
            PermitType::PRIVATE
        )
    );
    carData.emplace_back(
        std::make_shared<Car>(
            "s103ef",
            900000.0f,
            ChassisType::EV,
            PermitType::TOURIST
        )
    );
}

std::vector<Car> FindInstanceByN(CarPointerContainer& carData, int n)
{
    if(carData.empty())
        throw "Your data not found!";
    std::vector<Car> result;
    int count = 0;
    for(CarPointer& ptr : carData)
    {
        if(count == n)
        {
            for(CarPointer& ptr : carData)
            {
                result.emplace_back(*ptr);
            }
            break;
        }
        count++;
    }
    if(result.empty())
        throw "There is no Id same as User given Id";
    return result;
}

std::vector<Car> FindAttributesById(CarPointerContainer &carData, std::string id)
{
    if(carData.empty())
        throw "Your data not found!";
    std::vector<Car> result;
    for(CarPointer& ptr : carData)
    {
        if(ptr->id() == id)
        {
            result.emplace_back(*ptr);
        }
    }
    if(result.empty())
        throw "There is no Id same as User given Id";
    return result;
}

float FindAveragePrice(CarPointerContainer &carData, PermitType permitType)
{
    if(carData.empty())
        throw "Your data not found!";
    float sum = 0;
    int count = 0;
    for(CarPointer& ptr : carData)
    {
        if(ptr->chassisType() == ChassisType::EV && ptr->permitType() == permitType)
        {
            sum += ptr->price();
            count++;
        }
    }
    return (float)sum/count;
}

