#ifndef CAR_H
#define CAR_H
#include <ostream>
#include <string>
//#include <memory>
#include "CarType.h"
#include "Engine.h"
#include <functional>

// Engine defEngine();

//using EnginePointer = std::shared_ptr<Engine>;
using RefType = std::reference_wrapper<Engine>;

class Car
{
    const std::string _carId {""};
    const std::string _carBrand {""};
    const CarType _carType {CarType::SEDAN};
    //EnginePointer _carEngine;
    RefType _carEngine; //{Engine()}
    //Engine _carEngine;
    float _carPrice {0.0f};

public:
    Car() = delete;
    Car(const Car&) = default;  //copy constructor
    Car& operator=(const Car&) = delete;
    Car(Car&&) = delete; //moving constructor
    Car& operator=(Car&&) = delete;
    ~Car() = default;

    //parameterized constructor

    //Car(std::string, std::string, CarType carType, float);
    
    // Car(std::string, std::string, CarType carType, EnginePointer carEngine, float);
    // Car(std::string , std::string, CarType carType, Engine carEngine, float);
    Car(std::string carId, std::string carBrand, CarType carType, RefType carEngine, float carPrice);

    std::string carBrand() const { return _carBrand; }

    std::string carId() const { return _carId; }

    CarType carType() const { return _carType; }

    // EnginePointer carEngine() const { return _carEngine; }
    // void setCarEngine(const EnginePointer &carEngine) { _carEngine = carEngine; }
    // Engine carEngine() const { return _carEngine; }
    // void setCarEngine(const Engine &carEngine) { _carEngine = carEngine; }
    // RefType carEngine() const { return _carEngine; }
    // void setCarEngine(const RefType &carEngine) { _carEngine = carEngine; }
    RefType carEngine() const { return _carEngine; }
    void setCarEngine(const RefType &carEngine) { _carEngine = carEngine; }

    float carPrice() const { return _carPrice; }
    void setCarPrice(float carPrice) { _carPrice = carPrice; }

    friend std::ostream &operator<<(std::ostream &os,const Car &rhs);
};

#endif // CAR_H

