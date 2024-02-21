#include "EvCar.hpp"

#include "IllegalValueException.hpp"


std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << "_id: " << rhs._id
       << " _chassisType: " << static_cast<int>(rhs._chassisType)
       << " _batteryCapacity: " << rhs._batteryCapacity;
    return os;
}

EvCar::EvCar(int id, ChassisType cType, float batteryCapacity):
_id(id), _chassisType(cType) {
    if(!(20.0f<=batteryCapacity<=50.0f)) {
        throw IllegalValueException("Battery value must be between 20.0 to 50.0!");
    }
    _batteryCapacity = batteryCapacity;
}
