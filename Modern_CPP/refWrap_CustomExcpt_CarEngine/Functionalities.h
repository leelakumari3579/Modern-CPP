#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <string>
#include <vector>
#include <memory>
#include "Car.h"
#include "Engine.h"

using CarPointer = std::shared_ptr<Car>;
using CarPointerContainer = std::vector<CarPointer>;
using EngineContainer = std::vector<Engine>;

void CreateObjects(CarPointerContainer& carData,EngineContainer& engineData);
int FindHoursepowerByCarId(CarPointerContainer& carData, std::string carId);
std::vector<Car> FindAbove80TorqueCars(CarPointerContainer& carData);
// std::vector<Engine> FindEngineDetilsByCarType(CarPointerContainer& carData, CarType cType);
float AverageHoursepower(CarPointerContainer& carData);
std::string FindLowPriceByCarId(CarPointerContainer& carData);
float TwoCarInstancesCombinedPrice(CarPointer& car1,CarPointer& car2);

#endif // FUNCTIONALITIES_H



// CarPointerContainer CarTypeMatches(CarPointerContainer &data, CarType carType)
// {
//     CarPointerContainer result;
//     for (CarPointer &ptr : data)
//     {
//         if (ptr->carType() == carType)
//         {
//             result.push_back(ptr);
//         }
//     }
//     return result;
// }



// std::ostream &operator<<(std::ostream &out, CarPointer &ptr)
// {
//     out << "\n***************************************\n";
//     out << "car Id     : " << ptr->carId() << std::endl;
//     out << "car Brand  : " << ptr->carBrand() << std::endl;
//     out << "Car Type   : ";
//     switch (ptr->carType())
//     {
//     case CarType::HATCHBACK:
//         out << "HATCHBACK";
//         break;
//     case CarType::SEDAN:
//         out << "SEDAN";
//         break;
//     case CarType::SPORTS:
//         out << "SPORTS";
//         break;
//     case CarType::SUV:
//         out << "SUV";
//         break;
//     }
//     out << "\nCar Price  : " << ptr->carPrice() << std::endl;
//     out << "CAR ENGINE\n";
//     out << "  Engine Number     : " << ptr->carEngine().engineNumber() << std::endl;
//     out << "  Engine Horsepower : " << ptr->carEngine().engineHorsepower() << std::endl;
//     out << "  Engine Torque     : " << ptr->carEngine().engineTorque() << std::endl;
//     out << "  Engine Type       : ";
//     switch (ptr->carEngine().engineType())
//     {
//     case EngineType::HYBRID:
//         out << "HYBRID";
//         break;
//     case EngineType::ICT:
//         out << "ICT";
//         break;
//     }
//     out << std::endl;
//     return out;
// }
// void DisplayObjects(CarContainer &data)
// {
//     for (CarPointer &ptr : data)
//     {
//         std::cout << ptr << std::endl;
//     }
// }
