#include "Functionalities.hpp"
#include "EmptyContainerException.h"
#include "NoMatchingRecordsException.hpp"
#include "IllegalValueException.hpp"

#include <iostream>

void CreateObjects(Container &data) {
    data.emplace_back(
        std::make_shared<EvCar>(
            101, ChassisType::TUBULAR, 35.5f
        )
    );

    data.emplace_back(
        std::make_shared<ICECar>(
            201, FuelType::PETROL, 40.0f
        )
    );

    data.emplace_back(
        std::make_shared<EvCar>(
            102, ChassisType::LADDER, 42.5f
        )
    );

    data.emplace_back(
        std::make_shared<ICECar>(
            202, FuelType::DIESEL, 35.0f
        )
    );

    data.emplace_back(
        std::make_shared<EvCar>(
            103, ChassisType::TUBULAR, 49.5f
        )
    );

    data.emplace_back(
        std::make_shared<ICECar>(
            203, FuelType::DIESEL, 45.0
        )
    );
}

Container GetFirstNBasedOnType(Container &data, CarType cType, int N) {
    if(N < 0 || N > data.size()) {
        throw IllegalValueException("N cannot be negative or greater than size of container!");
    }
    if(!data.empty()) {
        Container result;

        if(cType == CarType::ICECar_TYPE) {
            for(int i=0; i < N; i++) {
                if(std::holds_alternative<ICPointer>(data[i])) {
                    result.emplace_back(std::get<1>(data[i]));
                }
            }
        } else if(cType == CarType::EvCAR_TYPE) {
            for(int i=0; i < N; i++) {
                if(std::holds_alternative<EVPointer>(data[i])) {
                    result.emplace_back(std::get<0>(data[i]));
                }
            }
        }
        if(result.empty()) {
            throw NoMatchingRecordsException("No records match the specified condition in GetFirstNBasedOnType");
        }
        return result;
    }
    throw EmptyContainerException("Data Empty in GetFirstNBasedOnType!");

}

bool CheckICForTankCapacityAbove30(Container &data) {
    if(!data.empty()) {
        bool flag = true;
        for(auto& var : data) {
            if(std::holds_alternative<ICPointer>(var)) {
                if(std::get<1>(var)->fuelTankCapacity() <= 30) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
    throw EmptyContainerException("Data Empty in CheckICForTankCapacityAbove30!");
}

void CountEvCars(Container &data) {
    if(!data.empty()) {
        int count {0};
        for(auto& var : data) {
            if(std::holds_alternative<EVPointer>(var)) count++;
        }
        if(count == 0) {
            std::cout << "No EV Cars found!" << std::endl;
        } else {
            std::cout << "Found " << count << " Ev Cars!" << std::endl;
        }
        return;
    }
    throw EmptyContainerException("Data Empty in CountEvCars!");
}

ChassisType FindChassisTypeOnId(Container& data, int id) {
    if(!data.empty()) {
        for(auto& var : data) {
            if(std::holds_alternative<EVPointer>(var)) {
                if(std::get<0>(var)->id() == id) {
                    return std::get<0>(var)->chassisType();
                }
            }
        }
        throw NoMatchingRecordsException("No records match the specified condition in FindChassisTypeOnId");
    }
    throw EmptyContainerException("Data Empty in FindChassisTypeOnId!");
}

void PrintBatteryCapacity(Container &data) {
    if(!data.empty()) {
        float total {0};
        for(auto& var : data) {
            if(std::holds_alternative<EVPointer>(var)) total+=std::get<0>(var)->batteryCapacity();
        }
        if(total == 0) {
            std::cout << "No EV Cars found!" << std::endl;
        } else {
            std::cout << "Total Battery Capacity: " << total << std::endl;
        }
        return;
    }
    throw EmptyContainerException("Data Empty in CountEvCars!");
}

void DisplayNthData(Container &data, int N) {
    if(N < 0 || N > data.size()) {
        throw IllegalValueException("N cannot be negative or greater than size of container!");
    }

    if(!data.empty()) {
        if(std::holds_alternative<EVPointer>(data[N])) {
            std::cout << *(std::get<0>(data[N])) << std::endl;
        } else {
            std::cout << *(std::get<1>(data[N])) << std::endl;
        }
        return;
    }
    throw EmptyContainerException("Data Empty in DisplayNthData!");

}
