#ifndef CAR_H
#define CAR_H

#include<string>
#include"CarType.h"

class Car
{
private:
    std::string _id;
    float _price;
    VehicleType _type;

public:
    //explicit Car(std::string id = "", float price = 0.0f, VehicleType type);
    explicit Car(std::string, float, VehicleType type);
    //explicit Car(std::string, VehicleType type = VehicleType::SUV);
    explicit Car(std::string, VehicleType type);
    explicit Car(std::string); //only called explicit convertion 

    Car() = delete; // deleted default constructor
    Car(const Car&) = delete; // deleted copy constructor 
    ~Car() = default; // defaulted destructor 
    Car& operator=(const Car&) = delete;
    Car& operator=(const Car&&) = delete;  //new consept! (move assignment)
    Car(Car&&) = delete; //new concept (move constructor) 

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    VehicleType type() const { return _type; }
    void setType(const VehicleType &type) { _type = type; }
};

#endif // CAR_H
