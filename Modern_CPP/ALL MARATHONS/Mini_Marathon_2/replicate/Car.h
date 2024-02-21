#ifndef CAR_H
#define CAR_H

#include<string>
#include <ostream>
#include"CarType.h"

class Car
{
protected:
    float _carPrice;
    std::string _carModel;
    CarType _cType;
    int _carSeatCount;
   
public:
    Car() =delete;
    Car(const Car&)=delete;
    Car(const Car&&)=delete;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&) =delete;
    ~Car() =default;

    //paramaterized
    Car(float carPrice,std::string carModel,CarType cType,int carSeatCount);

    //pure virtual fucntion

    virtual float CalculateInsuranceCost()=0;

    //+ overaload

    float operator+(const Car& rhs){
         return this->carPrice()+rhs.carPrice();
    }

    float carPrice() const { return _carPrice; }
    void setCarPrice(int carPrice) { _carPrice = carPrice; }

    std::string carModel() const { return _carModel; }
    void setCarModel(const std::string &carModel) { _carModel = carModel; }

    CarType cType() const { return _cType; }
    void setCType(const CarType &cType) { _cType = cType; }

    int carSeatCount() const { return _carSeatCount; }
    void setCarSeatCount(int carSeatCount) { _carSeatCount = carSeatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
