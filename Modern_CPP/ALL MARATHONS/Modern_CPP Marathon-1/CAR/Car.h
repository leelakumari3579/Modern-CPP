#ifndef CAR_H
#define CAR_H

#include"ChassisType.h"
#include"PermitType.h"
#include<string>
#include <ostream>

class Car 
{
    private:
        const std::string _id;
        float _price;
        ChassisType _chassisType {ChassisType::EV};
        PermitType _permitType {PermitType::TOURIST};

    public:
        
        //Constructors
        Car()=delete;
        Car(const Car&)=default;
        Car& operator=(const Car&)=delete;
        Car(const Car&&)=delete;
        Car& operator=(const Car&&)=delete;
        ~Car()=default;
        
        //parameterized Constructor
        Car(std::string id,float price, ChassisType chassisType,PermitType permitType);

        //member functions
        float calculateDiscount(PermitType ptype);

        friend std::ostream &operator<<(std::ostream &os, const Car &c);

        
        float operator+(const Car &c2);

       

       // float operator+(Car& c1, Car& c2);

        //getters and setters
        std::string id() const { return _id; }

        float price() const { return _price; }
        void setPrice(float price) { _price = price; }

        ChassisType chassisType() const { return _chassisType; }

        PermitType permitType() const { return _permitType; }

};

#endif // CAR_H
