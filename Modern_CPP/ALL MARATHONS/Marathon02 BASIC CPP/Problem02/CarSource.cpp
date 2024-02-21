#include <iostream>
#include "Car.h"

void Car::display() {
    std::cout<<"Chassis Number: "<<getVehicleChassisNumber()<<std::endl;
    std::cout<<"Vehicle Brand: "<<getVehicleBrand()<<std::endl;
    std::cout<<"Ex-Showroom price: "<<getVehicleExShowroomPrice()<<std::endl;
    std::cout<<"Tax Amount: "<<getVehicleTax()<<std::endl;
    std::cout<<"Insurance Amount: "<<getVehicleInsurance()<<std::endl;
    std::cout<<"Vehicle Type: Car- "<<getCarType()<<std::endl;
}

void Car::accept() {
    std::string temps;
    float tempf;
    int tempi;

    std::cout<<"\nEnter the chassis number: ";
    std::cin>>temps;
    setVehicleChassisNumber(temps);

    std::cout<<"Enter the vehicle brand: ";
    std::cin>>temps;
    setVehicleBrand(temps);

    std::cout<<"Enter the Ex-Showroom price: ";
    std::cin>>tempf;
    setVehicleExShowroomPrice(tempf);

    std::cout<<"Enter the Tax Amount: ";
    std::cin>>tempf;
    setVehicleTax(tempf);

    std::cout<<"Enter the Insurance Amount: ";
    std::cin>>tempf;
    setVehicleInsurance(tempf);

    std::cout<<"Enter the type of Car from the below options: "<<std::endl;
    std::cout<<"Enter 1 for SUV."<<std::endl;
    std::cout<<"Enter 2 for HatchBack."<<std::endl;
    std::cout<<"Enter 3 for Sedan."<<std::endl;
    std::cin>>tempi;
    switch(tempi) {
        case 1: setCarType(SUV);
                break;

        case 2: setCarType(HatchBack);
                break;

        case 3: setCarType(Sedan);
                break;
    }

    std::cout<<"\nRecord of Car Added Successfully!";
}