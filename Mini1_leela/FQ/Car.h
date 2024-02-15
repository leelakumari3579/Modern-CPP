#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "ChassisType.h"
#include "PermitType.h"

class Car
{
private:
    const std::string _id;
    float _price;
    ChassisType _chassisType;
    PermitType _permitType;
public:
    Car() = default;                       //default constructor
    Car(const Car &) = default;             // deleted copy constructor
    ~Car() = default;                      // defaulted destructor
    Car &operator=(const Car &) = delete;  // deleted assignment operator overloading
    Car &operator=(const Car &&) = delete; // new concept! (move assignment)
    Car(const Car &&) = delete;            // move constructor

    Car(std::string id, float price, ChassisType chassisType, PermitType permitType);

    float CalculateDiscount();
    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
    float operator+(Car &car1);    

    std::string id() const { return _id; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    ChassisType chassisType() const { return _chassisType; }
    void setChassisType(const ChassisType &chassisType) { _chassisType = chassisType; }

    PermitType permitType() const { return _permitType; }
    void setPermitType(const PermitType &permitType) { _permitType = permitType; }
};


#endif // CAR_H
