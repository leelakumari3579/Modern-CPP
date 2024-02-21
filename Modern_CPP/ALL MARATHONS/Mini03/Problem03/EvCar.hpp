#ifndef EVCAR_HPP
#define EVCAR_HPP

#include "ChassisType.hpp"
#include <ostream>

class EvCar {
    private:

        int _id;
        ChassisType _chassisType;
        float _batteryCapacity;

    public:

        // Initial Setup
            EvCar() = delete;
            EvCar(const EvCar&) = delete;
            EvCar(EvCar&&) = delete;
            EvCar& operator=(const EvCar&) = delete;
            EvCar& operator=(EvCar&&) = delete;
            ~EvCar() = default;

        // Parameterized Constructor
            EvCar(int id, ChassisType cType, float batteryCapacity);

        // Getters
            int id() const { return _id; }
            ChassisType chassisType() const { return _chassisType; }
            float batteryCapacity() const { return _batteryCapacity; }

        // Operator OVerloading
            friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);

            

            


};

#endif // EVCAR_HPP
