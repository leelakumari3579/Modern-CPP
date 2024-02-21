#include <iostream>
#include "Bike.h"

void Bike::display() {
    std::cout<<"Chassis Number: "<<getVehicleChassisNumber()<<std::endl;
    std::cout<<"Vehicle Brand: "<<getVehicleBrand()<<std::endl;
    std::cout<<"Ex-Showroom price: "<<getVehicleExShowroomPrice()<<std::endl;
    std::cout<<"Tax Amount: "<<getVehicleTax()<<std::endl;
    std::cout<<"Insurance Amount: "<<getVehicleInsurance()<<std::endl;
    std::cout<<"Vehicle Type: Bike- "<<getBikeType()<<std::endl;
}

void Bike::accept() {
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

    std::cout<<"Enter the type of Bike from the below options: "<<std::endl;
    std::cout<<"Enter 1 for Commute."<<std::endl;
    std::cout<<"Enter 2 for Sports."<<std::endl;
    std::cout<<"Enter 3 for Offroader."<<std::endl;
    std::cin>>tempi;
    switch(tempi) {
        case 1: setBikeType(Commute);
                break;

        case 2: setBikeType(Sports);
                break;

        case 3: setBikeType(Offroader);
                break;
    }

    std::cout<<"\nRecord of Bike Added Successfully!";
}