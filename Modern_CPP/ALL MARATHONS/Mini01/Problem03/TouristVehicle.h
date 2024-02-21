#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include <string>
#include <memory>
#include <ostream>
#include "VehicleType.h"
#include "Permit.h"

using PermitPointer = std::shared_ptr<Permit>;

class TouristVehicle {
    private:

        std::string _number;
        const VehicleType _vehicleType;
        const int _seatCount;
        float _perHourBookingCharge;
        PermitPointer _permit;

    public:

        // Initial Setup
        TouristVehicle() = delete;
        TouristVehicle(const TouristVehicle&) = default;
        TouristVehicle(TouristVehicle&&) = delete;
        TouristVehicle& operator=(const TouristVehicle&) = delete;
        TouristVehicle& operator=(TouristVehicle&&) = delete;
        ~TouristVehicle() = default;

        // Parameterized Constructor
        TouristVehicle(std::string number, VehicleType vehicleType, int seatCount, float perHourBookingCharge, PermitPointer permit);

        // Getters
        std::string number() const { return _number; }
        VehicleType vehicleType() const { return _vehicleType; }
        int seatCount() const { return _seatCount; }
        float perHourBookingCharge() const { return _perHourBookingCharge; }
        PermitPointer permit() const { return _permit; }           

        friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TOURISTVEHICLE_H
