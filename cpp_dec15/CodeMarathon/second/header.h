#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstring>
enum VEHICLE
{
    SUV,
    HatchBack,
    Sedan,
    Commute,
    Sports,
    Offroader
};
class Vehicle
{
    protected:
        enum VEHICLE v;
        int ChassisNumber;
        std::string VehicleBrand;
        float Ex_ShowroomPrice;
        float Tax;
        float InsuranceAmount;
    public:
        Vehicle();
        Vehicle(enum VEHICLE,int,std::string,float,float,float);
        ~Vehicle();
        void accept();
        virtual void ByChassisNumber(int);
        virtual int GetByCategory(enum VEHICLE v,int,Vehicle &v1);
        virtual float avgPrice(enum VEHICLE v);
};
class Car:public Vehicle
{
    public:
        Car();
        Car(enum VEHICLE,int,std::string,float,float,float);
        ~Car();
        virtual void ByChassisNumber(int);
        virtual int GetByCategory(enum VEHICLE v,int,Car &c1);
        virtual float avgPrice(enum VEHICLE v);
};
class Bike:public Vehicle
{
    public:
        Bike();
        Bike(enum VEHICLE,int,std::string,float,float,float);
        ~Bike();
        void ByChassisNumber(int);
        int GetByCategory(enum VEHICLE v,int,Bike &b1);
        float avgPrice(enum VEHICLE v);
};

#endif // HEADER_H
