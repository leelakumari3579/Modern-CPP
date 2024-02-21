#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle {
    std::string vehicleChassisNumber;
    std::string vehicleBrand;
    float vehicleExShowroomPrice;
    float vehicleTax;
    float vehicleInsurance;

    public:
        virtual void display()=0;
        virtual void accept()=0;

        std::string getVehicleChassisNumber() const { return vehicleChassisNumber; }

        std::string getVehicleBrand() const { return vehicleBrand; }

        float getVehicleExShowroomPrice() const { return vehicleExShowroomPrice; }

        float getVehicleTax() const { return vehicleTax; }

        float getVehicleInsurance() const { return vehicleInsurance; }

        void setVehicleChassisNumber(const std::string &vehicleChassisNumber_) { vehicleChassisNumber = vehicleChassisNumber_; }

        void setVehicleBrand(const std::string &vehicleBrand_) { vehicleBrand = vehicleBrand_; }

        void setVehicleExShowroomPrice(float vehicleExShowroomPrice_) { vehicleExShowroomPrice = vehicleExShowroomPrice_; }

        void setVehicleTax(float vehicleTax_) { vehicleTax = vehicleTax_; }

        void setVehicleInsurance(float vehicleInsurance_) { vehicleInsurance = vehicleInsurance_; }
};

#endif // VEHICLE_H
