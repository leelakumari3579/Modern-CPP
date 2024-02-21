#include "Functionalities.h"
#include <iostream>
#include "NegativeValueException.h"
#include "LimitValueException.h"
#include"ContainerEmptyException.h"
#include"NoMatchInstanceException.h"


void CreateObjects(std::vector<std::shared_ptr<Car>> &vectorCar)
{
    float carPrice;
    std::string carModel;
    int carType;
    int carSeatCount;
    float batteryCapacity;
    float fuelCapacity;
    int fuelType;

    for (int i = 0; i < 2; i++)
    {
        CarType carTypeEnum;
        std::cin >> carPrice;
        std::cin >> carModel;
        std::cin >> carType;
        std::cin >> carSeatCount;
        std::cin >> batteryCapacity;

        if (carSeatCount < 0 || carType < 0 || batteryCapacity < 0)
        {
            throw NegativeValueException("No Negative value for int type\n");
        }

        if (batteryCapacity > 80)
        {
            throw LimitValueException("Input criteria not matched\n");
        }

        if (carType == 11)
        {
            carTypeEnum = CarType::PRIVATE_CAR;
        }
        else if (carType == 22)
        {
            carTypeEnum = CarType::TOURIST_PERMIT_CAR;
        }
        vectorCar.emplace_back(
            std::make_shared<EvCar>(carPrice, carModel, carTypeEnum, carSeatCount, batteryCapacity));
    }

    for (int i = 0; i < 3; i++)
    {
        CarType carTypeEnum;
        FuelType fuelTypeEnum;
        std::cin >> carPrice;
        std::cin >> carModel;
        std::cin >> carType;
        std::cin >> carSeatCount;
        std::cin >> fuelCapacity;
        std::cin >> fuelType;

        if (carSeatCount < 0 && carType < 0 && fuelType < 0)
        {
            throw NegativeValueException("No Negative value for int type\n");
        }
        if (carSeatCount > 8 && (fuelCapacity >= 30.0f && fuelCapacity <= 50.0f))
        {
            throw LimitValueException("Input criteria not matched\n");
        }

        if (carType == 11)
        {
            carTypeEnum = CarType::PRIVATE_CAR;
        }
        else if (carType == 22)
        {
            carTypeEnum = CarType::TOURIST_PERMIT_CAR;
        }

        if (fuelType == 1)
        {
            fuelTypeEnum = FuelType::DIESEL;
        }
        else if (fuelType == 2)
        {
            fuelTypeEnum = FuelType::PETROL;
        }
        else if (fuelType == 3)
        {
            fuelTypeEnum = FuelType::CNG;
        }
        vectorCar.emplace_back(
            std::make_shared<ICEngineCar>(carPrice, carModel, carTypeEnum, carSeatCount, fuelCapacity, fuelTypeEnum));
    }
}

std::function<float(std::vector<std::shared_ptr<Car>>,CarType)> CarTypeAverageInsuranceCost=
[](const std::vector<std::shared_ptr<Car>>& vectorCar,CarType carType)
{
    if (vectorCar.empty())
    {
        throw ContainerEmptyException("Vector is empty\n");
    }
    float sum=0.0f;
    int count=0;
    for (std::shared_ptr<Car> car : vectorCar)
    {

        if(car->carType()==carType)
        {
            sum+=car->CalculateInsuranceCost();
            count++;
        }
    }
    if(count==0)
    {
        throw NoMatchInstanceException("NoMatchInstanceException\n");
    }
    
    return sum/count;
};

std::function<std::array<int,2>(std::vector<std::shared_ptr<Car>>)> CountChildInstancesWithConditions=
[](const std::vector<std::shared_ptr<Car>>& vectorCar)
{
    if (vectorCar.empty())
    {
        throw ContainerEmptyException("Vector is empty\n");
    }
    int countICE=0;
    int countEV=0;
    std::array<int,2> result;
    for (std::shared_ptr<Car> car : vectorCar)
    {
        std::shared_ptr<ICEngineCar> ice= std::dynamic_pointer_cast<ICEngineCar>(car);
        std::shared_ptr<EvCar> ev= std::dynamic_pointer_cast<EvCar>(car);
        if(ice!=nullptr && ice->CalculateInsuranceCost()>20000.0f)
        {
            countICE++;
        }
        if(ev!=nullptr && ev->CalculateInsuranceCost()>20000.0f)
        {
            countEV++;
        }
    }
    result[0]=countEV;
    result[1]=countICE;
    return result;

};





