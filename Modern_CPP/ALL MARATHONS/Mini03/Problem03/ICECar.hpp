#ifndef ICECAR_HPP
#define ICECAR_HPP

#include "FuelType.hpp"
#include <ostream>

class ICECar {
    private:
        int _id;
        FuelType _fuelType;
        int _fuelTankCapacity;

    public:
        // Initial Setup
            ICECar() = delete;
            ICECar(const ICECar&) = delete;
            ICECar(ICECar&&) = delete;
            ICECar& operator=(const ICECar&) = delete;
            ICECar& operator=(ICECar&&) = delete;
            ~ICECar() = default;

        // Parameterized Constructor
            ICECar(int id, FuelType fType, int fuelTankCapacity);

        // Getters
            int id() const { return _id; }
            FuelType fuelType() const { return _fuelType; }
            int fuelTankCapacity() const { return _fuelTankCapacity; }

        // Operator Overloading
            friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);

            
};

#endif // ICECAR_HPP
