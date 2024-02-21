#include <iostream>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoMatchingRecordsFound.h"
#include "IllegalValueForNException.h"

int main() {
    TouristVehicleContainer tVData;
    float fresult;

    //Creating Objects
    CreateObjects(tVData);

    try {
        // Returning first N instances based on specified consitions
        std::cout << "Returning first N(3) instances based on specified consitions" << std::endl;
        std::vector<TouristVehicle> permits = GetPermitInstancesBasedOnConditions(tVData, 3);
        for(const TouristVehicle& ptr : permits) {
            std::cout << ptr << std::endl;
        }
    } catch(IllegalValueForNException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(NoMatchingRecordsFoundException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        // Returning Average Booking Charge Based on Type.
        std::cout << "Returning Average Booking Charge Based on Type (Bike)." << std::endl;
        fresult = AverageBookingChargeByType(tVData, VehicleType::BIKE);
        std::cout << "Average Charge: " << fresult << std::endl;
    } catch(NoMatchingRecordsFoundException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        // Returning Serial Number Based on Max Booking Charge.
        std::cout << "Returning Serial Number Based on Max Booking Charge." << std::endl;
        std::string sresult = FindSerialNumberByTVMAXBookingCharge(tVData);
        std::cout << "Serial Number: " << sresult << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        // Returning the first N Tourist Vehicle Instances.
        std::cout << "Returning the first N(4) Tourist Vehicle Instances." << std::endl;
        std::vector<TouristVehiclePointer> vehicles = GetFirstNTV(tVData, 4);

        for(const TouristVehiclePointer& ptr : vehicles) {
            std::cout << *ptr << std::endl;
        }
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(IllegalValueForNException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;
}