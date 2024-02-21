#ifndef TOURISTVEHICLE_HPP
#define TOURISTVEHICLE_HPP

#include <iostream>
#include <memory>

#include "VehicleType.h"
#include "Permit.hpp"

using PermitPointer = std::shared_ptr<Permit>;

class TouristVehicle {

    private:
        std::string _vehicleNumber;
        VehicleType _TouristVehicleType;
        int _seatCount;
        float _bookingChaarge;
        PermitPointer _permit;

    public:

        // Initial Setup
        TouristVehicle() = delete;
        TouristVehicle(const TouristVehicle&) = default;
        TouristVehicle(TouristVehicle&&) = delete;
        TouristVehicle& operator=(const TouristVehicle&) = delete;
        TouristVehicle& operator=(TouristVehicle&&) = delete;
        ~TouristVehicle() = default;

        // Parameterized Constructor.
        TouristVehicle(std::string vehicleNumber, VehicleType vType, int seatCount, float bookingCharge, PermitPointer permit);

        // Getters
        std::string vehicleNumber() const { return _vehicleNumber; }
        VehicleType touristVehicleType() const { return _TouristVehicleType; }
        int seatCount() const { return _seatCount; }
        float bookingChaarge() const { return _bookingChaarge; }
        PermitPointer permit() const { return _permit; }        

        // Operator Overloading.
        friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);

        

        
};

#endif // TOURISTVEHICLE_HPP
