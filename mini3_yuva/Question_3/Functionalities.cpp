#include "Functionalities.h"
#include "DataEmptyException.h"
#include <iostream>

void CreateObjects(EVContainer &data)
{
    data.emplace_back(std::make_shared<EvCar>(
        VehicleType::REGULAR,
        300000,
        50,
        80,
        67,
        ChargingType::AC));
    data.emplace_back(std::make_shared<EvCar>(
        VehicleType::TRANSPORT,
        899000,
        90,
        45,
        90,
        ChargingType::DC_FAST_CHARGE));
    data.emplace_back(std::make_shared<Ev2Wheeler>(
        VehicleType::TRANSPORT,
        199000,
        90,
        45,
        90,
        ConnectedTechType::DIGITAL));
    data.emplace_back(std::make_shared<Ev2Wheeler>(
        VehicleType::REGULAR,
        788800,
        90,
        80,
        90,
        ConnectedTechType::NAVIGATION_ONLY));
}

void DisplayAttributesOfGivenId(EVContainer &data, std::future<int> &ft)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    int ID = ft.get();
    for (EVehiclePointer &ptr : data)
    {
        if (ptr->id() == ID)
        {
            std::cout << *ptr << "\n";
        }
    }
}

std::optional<float> AveragePriceOfAllEvCars(EVContainer &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    int total = 0;
    int count = 0;
    for (EVehiclePointer &ptr : data)
    {
        if (dynamic_cast<EvCar *>(ptr.get()))
        {
            if (ptr->engineHorsepower()<600)
            {
                total += ptr->price();
                count++;
            }
        }
    }

    // for (EVehiclePointer &ptr : data)
    // {
    //     if (std::dynamic_pointer_cast<EvCar>(ptr)->engineHorsepower() < 600)
    //     {
    //         total += std::dynamic_pointer_cast<EvCar>(ptr)->price();
    //         count++;
    //     }
    // }

    if (count == 0)
    {
        return std::nullopt;
    }
    return total / count;
}

std::optional<EVContainer> InstancesOfPriceAboveThresholdValue(EVContainer &data, float price)
{
    EVContainer result;
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    for (EVehiclePointer &ptr : data)
    {
        if (ptr->price() > price)
        {
            result.push_back(ptr);
        }
    }
    if (result.empty())
    {
        return std::nullopt;
    }
    return result;
}

float CalculetSumOfGST(EVContainer &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    int total = 0;
    for (EVehiclePointer &ptr : data)
    {
        total += ptr->CalculateGst();
    }
    return total;
}

float CalculateTotalExchangeAmount(EVContainer &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    int total = 0;
    for (EVehiclePointer &ptr : data)
    {
        if (dynamic_cast<Ev2Wheeler *>(ptr.get()))
        {
            total += ptr->CalculateExchangeAmount();
        }
    }
    return total;
}
