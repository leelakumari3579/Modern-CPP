#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <ostream>
#include "VehicleType.h"

/*
    common behaviour
    book a appointment
    pay registration tax 
*/

class Vehicle
{
private:
    const std::string _vehicleId;
    float _vehiclePrice;
    VehicleType _vehicleType;
public:
    Vehicle() = delete;
    Vehicle(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle& operator=(Vehicle&&) = delete;
    ~Vehicle() = default;

    // option1: only give id
    explicit Vehicle(std::string id);
    // option2: ID, type
    Vehicle(std::string id, VehicleType vtype);
    // option3: TELL ME EVERYTHING!!!
    Vehicle(std::string id, float price, VehicleType vtype);

    std::string vehicleId() const { return _vehicleId; }

    float vehiclePrice() const { return _vehiclePrice; }
    void setVehiclePrice(float vehiclePrice) { _vehiclePrice = vehiclePrice; }

    VehicleType vehicleType() const { return _vehicleType; }
    void setVehicleType(const VehicleType &vehicleType) { _vehicleType = vehicleType; }
    
    //user defined member functions
    
    virtual void BookServiceAppointment() = 0;
    virtual float CalculateRegistrationTax();
    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H