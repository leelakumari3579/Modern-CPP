#include "TouristVehicle.h"

TouristVehicle::TouristVehicle(std::string number, VehicleType vehicleType, int seatCount, float perHourBookingCharge, PermitPointer permit):
_number(number), _vehicleType(vehicleType), _seatCount(seatCount), _perHourBookingCharge(perHourBookingCharge),
_permit(permit) {}
std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    os << "_number: " << rhs._number
       << " _vehicleType: " << static_cast<int>(rhs._vehicleType)
       << " _seatCount: " << rhs._seatCount
       << " _perHourBookingCharge: " << rhs._perHourBookingCharge
       << " _permit: " << *rhs._permit;
    return os;
}
