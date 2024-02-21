#include <iostream>
#include <cstring>
#include"header.h"

Vehicle::Vehicle()
{
    ChassisNumber=0000;
    VehicleBrand="NA";
    Ex_ShowroomPrice=50000.20;
    Tax=1200;
    InsuranceAmount=3000.5; 
}

Vehicle::Vehicle(VEHICLE vh, int cn, std::string vb, float sp, float tx, float ia)
{
    v=vh;
    VehicleBrand=vb;
    Ex_ShowroomPrice=sp;
    Tax=tx;
    InsuranceAmount=ia;
}

Vehicle::~Vehicle()
{
}

void Vehicle::accept()
{
    std::cin>>ChassisNumber;
    std::cin>>VehicleBrand;
    std::cin>>Ex_ShowroomPrice;
    std::cin>>Tax;
    std::cin>>InsuranceAmount;
}

void Vehicle::ByChassisNumber(int ChNum)
{
    if(ChNum==ChassisNumber)
        std::cout<<ChassisNumber<<"\n"<<VehicleBrand<<"\n"<<Ex_ShowroomPrice<<"\n"<<Tax<<"\n"<<InsuranceAmount<<std::endl;
}

float Vehicle::avgPrice(VEHICLE v)
{
    return ((Ex_ShowroomPrice+Tax+InsuranceAmount)/3)*100;
}

int Vehicle::GetByCategory(VEHICLE v,int n,Vehicle &v1)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
    if(v1.v==v)
        count++;
    }
    return count;
}

Car::Car()
{
    ChassisNumber=0000;
    VehicleBrand="NA";
    Ex_ShowroomPrice=50000.20;
    Tax=1200;
    InsuranceAmount=3000.5; 
}

Car::Car(VEHICLE vh, int cn, std::string vb, float sp, float tx, float ia):Vehicle(vh,cn,vb,sp,tx,ia)
{
}

Car::~Car()
{
}

void Car::ByChassisNumber(int ChNum)
{
    if(ChNum==ChassisNumber)
        std::cout<<ChassisNumber<<"\n"<<VehicleBrand<<"\n"<<Ex_ShowroomPrice<<"\n"<<Tax<<"\n"<<InsuranceAmount<<std::endl;
}

float Car::avgPrice(VEHICLE v)
{
    return ((Ex_ShowroomPrice+Tax+InsuranceAmount)/3)*100;
}

int Car::GetByCategory(VEHICLE v,int n,Car &c1)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
    if(c1.v==v)
        count++;
    }
    return count;
}

Bike::Bike()
{
    ChassisNumber=0000;
    VehicleBrand="NA";
    Ex_ShowroomPrice=50000.20;
    Tax=1200;
    InsuranceAmount=3000.5; 
}

Bike::Bike(VEHICLE vh, int cn, std::string vb, float sp, float tx, float ia):Vehicle(vh,cn,vb,sp,tx,ia)
{
}

Bike::~Bike()
{
}

void Bike::ByChassisNumber(int ChNum)
{
    if(ChNum==ChassisNumber)
        std::cout<<ChassisNumber<<"\n"<<VehicleBrand<<"\n"<<Ex_ShowroomPrice<<"\n"<<Tax<<"\n"<<InsuranceAmount<<std::endl;
}

float Bike::avgPrice(VEHICLE v)
{
    return ((Ex_ShowroomPrice+Tax+InsuranceAmount)/3)*100;
}

int Bike::GetByCategory(VEHICLE v,int n,Bike &b1)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
    if(b1.v==v)
        count++;
    }
    return count;
}
