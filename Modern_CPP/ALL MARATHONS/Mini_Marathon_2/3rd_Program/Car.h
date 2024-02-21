#ifndef CAR_H
#define CAR_H

#include"CarType.h"
#include<string>
#include <ostream>

class Car
{
protected:
    float _carPrice;
    std::string _carModel;
    CarType _carType;
    int _carSeatCount;


public:
    Car()=delete;
    Car(const Car&)=default;
    Car(Car&&)=delete;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&)=delete;
    ~Car()=default;

    Car(float carPrice,std::string carModel,CarType carType,int carSeatCount);

    virtual float CalculateInsuranceCost()=0;

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    float operator+(const Car&);

    float carPrice() const { return _carPrice; }
    void setCarPrice(float carPrice) { _carPrice = carPrice; }

    std::string carModel() const { return _carModel; }
    void setCarModel(const std::string &carModel) { _carModel = carModel; }

    CarType carType() const { return _carType; }
    void setCarType(const CarType &carType) { _carType = carType; }

    int carSeatCount() const { return _carSeatCount; }
    void setCarSeatCount(int carSeatCount) { _carSeatCount = carSeatCount; }

    
};

#endif // CAR_H
