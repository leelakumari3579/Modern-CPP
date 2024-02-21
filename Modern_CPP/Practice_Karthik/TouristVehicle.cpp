#include "TouristVehicle.hpp"
std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    os << "_vehicleNumber: " << rhs._vehicleNumber
       << " _TouristVehicleType: " << static_cast<int>(rhs._TouristVehicleType)
       << " _seatCount: " << rhs._seatCount
       << " _bookingChaarge: " << rhs._bookingChaarge
       << " _permit: " << *rhs._permit;
    return os;
}


TouristVehicle::TouristVehicle(std::string vehicleNumber, VehicleType vType, int seatCount, float bookingCharge, PermitPointer permit):
_vehicleNumber(vehicleNumber), _TouristVehicleType(vType), _seatCount(seatCount), _bookingChaarge(bookingCharge), _permit(permit) {}
