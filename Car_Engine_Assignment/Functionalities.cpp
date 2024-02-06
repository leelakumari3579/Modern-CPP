#include <iostream>
#include <limits>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundExecption.h"
#include "NoMatchingInstanceException.h"

void CreateObjects(CarPointerContainer &carData, EngineContainer &engineData)
{
    engineData.emplace_back(
        Engine("E101", EngineType::ICT, 400, 111));
    engineData.emplace_back(
        Engine("E102", EngineType::HYBRID, 300, 112));

    auto itr = engineData.begin(); //write only after all engines are emplaced
    // first ENGINE OBJECTS aften that CAR OBJECTS

    carData.emplace_back(
        std::make_shared<Car>("c101", "Honda", CarType::SEDAN, *itr++/*engineData[0]*/, 1100000));
    carData.emplace_back(
        std::make_shared<Car>("c102", "BMW", CarType::SUV, *itr++/*engineData[1]*/, 895000.0f));

    /*
    carData.emplace_back(
        std::make_shared<Car>(
            "00000",
            "BMW",
            CarType::SUV,
            std::make_shared<Engine>(
                "00000",
                EngineType::HYBRID,
                3000,
                80),
            700000.0f));

    carData.emplace_back(
        std::make_shared<Car>(
            "12345",
            "Hyundi",
            CarType::SEDAN,
            std::make_shared<Engine>(
                "54321",
                EngineType::HYBRID,
                5000,
                78),
            500000.0f));
    */
}


// void CreateObjects(CarPointerContainer &carData, EngineContainer &engineData)
// {
//     // user input
//     std::string engineId {""};
//     int engineType {0};
//     int hoursepower {0};
//     int torque {0};
//     std::string carId {""};
//     std::string carBrand {""};
//     int carType {0};
//     float carPrice {0.0f};
//     for(int i=0;i<2;i++)
//     {
//         std::cin>>engineId;
//         std::cin>>engineType;
//         std::cin>>hoursepower;
//         std::cin>>torque;
//         engineData.emplace_back(engineId, static_cast<EngineType>(engineType),hoursepower,torque);
//     }

//     auto itr = engineData.begin(); //write only after engine data completed
//     for(int i=0;i<2;i++)
//     {
//         std::cin>>carId;
//         std::cin>>carBrand;
//         std::cin>>carType;
//         std::cin>>carPrice;
//         carData.emplace_back(
//             std::make_shared<Car>(carId,carBrand,static_cast<CarType>(carType),*itr++,carPrice));
//     }
// }



/*
    case1 : find a match and return
    case2 : data is empty
    case3 : no matching ID
*/

int FindHoursepowerByCarId(CarPointerContainer &carData, std::string carId)
{
    // case2: empty data?
    if (carData.empty())
    {
        throw EmptyContainerException("your data is empty!");
    }

    // case1: matching Id
    for (CarPointer &ptr : carData)
    {
        if (ptr->carId() == carId)
            return ptr->carEngine().get().engineHorsepower();
    }

    // case3: no matching Id
    throw IdNotFoundException("Id does not exist!");
}

/*
    case1: empty input
    case2: at least one car with above 80 torque
    case3: no car above 80 torque exists!
*/

std::vector<Car> FindAbove80TorqueCars(CarPointerContainer &carData)
{
    // case1: empty data
    if (carData.empty())
    {
        throw EmptyContainerException("your data is empty!");
    }

    // case2: matching data
    std::vector<Car> result;
    for (CarPointer &ptr : carData)
    {
        if (ptr->carEngine().get().engineTorque() >= 80)
        {
            result.emplace_back(*ptr);
        }
    }

    // case3: no matched data found
    if (result.empty())
    {
        throw NoMatchingInstanceException("container has no matching cars!");
    }
    return result;
}

// std::vector<Engine> FindEngineDetilsByCarType(CarPointerContainer & carData, CarType cType)
// {
//     std::vector<Engine> result;
//     for(CarPointer& ptr : carData)
//     {
//         if(ptr->carType() == cType)
//         {
//             result.emplace_back(*ptr);
//         }
//     }
//     return result;
// }

float AverageHoursepower(CarPointerContainer & carData)
{
    float sum=0;
    int count=0;
    for(CarPointer& ptr : carData)
    {
        if(ptr->carEngine().get().engineType() == EngineType::ICT && ptr->carPrice()>1000000)
        {
            sum += ptr->carEngine().get().engineHorsepower();
            count++;
        }
    }
    return (float)sum/count;
}

std::string FindLowPriceByCarId(CarPointerContainer& carData)
{
    float min = __LONG_MAX__;
    std::string result;
    for(CarPointer& ptr : carData)
    {
        if(ptr->carPrice() < min)
        {
            min = ptr->carPrice();
            result = ptr->carId();
        }
    }
    return result;
}

float TwoCarInstancesCombinedPrice(CarPointer& car1, CarPointer& car2)
{
    return car1.get()->carPrice() + car2.get()->carPrice();
}