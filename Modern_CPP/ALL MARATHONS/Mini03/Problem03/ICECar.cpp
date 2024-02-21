#include "ICECar.hpp"
#include "IllegalValueException.hpp"

std::ostream &operator<<(std::ostream &os, const ICECar &rhs) {
    os << "_id: " << rhs._id
       << " _fuelType: " << static_cast<int>(rhs._fuelType)
       << " _fuelTankCapacity: " << rhs._fuelTankCapacity;
    return os;
}

ICECar::ICECar(int id, FuelType fType, int fuelTankCapacity):
_id(id) {
    if(fuelTankCapacity <= 0) {
        throw IllegalValueException("Value for Fuel Tank Capacity cannot be negative or 0!!");
    }
    _fuelTankCapacity = fuelTankCapacity;
}
