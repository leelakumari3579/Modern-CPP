#include <iostream>

#include "Functionalities.hpp"
#include "NoMatchingRecordsException.hpp"
#include "EmptyContainerException.h"
#include "IllegalValueException.hpp"

int main() {
    Container data;
    CreateObjects(data);

    std::cout << "Getting first 3 instances of type EvCar" << std::endl;
    try {
        Container result = GetFirstNBasedOnType(data, CarType::EvCAR_TYPE, 3);
        for(auto& var : result) {
            std::visit([](auto&& value) { std::cout << *value << std::endl; }, var);
        }
    } catch(IllegalValueException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(NoMatchingRecordsException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Checiking if all ICE Car instances have a fuel tank capacity above 30:" << std::endl;
    try {
        bool result = CheckICForTankCapacityAbove30(data);
        if(result == false) {
            std::cout << "False" << std::endl;
        } else {
            std::cout << "True" << std::endl;
        }
    }catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Getting the count of EV Cars..." << std::endl;
    try {
        CountEvCars(data);
    }catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Getting chassis type of car with id: 101" << std::endl;
    try {
        ChassisType ctype = FindChassisTypeOnId(data, 101);
        if(ctype == ChassisType::LADDER) {
            std::cout << "Ladder" << std::endl;
        } else {
            std::cout << "Tubular" << std::endl;
        }
    } catch(NoMatchingRecordsException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Printing the total battery capacity of EV Cars..." << std::endl;
    try {
        PrintBatteryCapacity(data);
    }catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Getting the 4th instance of the container..." << std::endl;
    try {
        // DisplayNthData(data);
        DisplayNthData(data, 4);
    } catch(IllegalValueException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << std::endl;
}