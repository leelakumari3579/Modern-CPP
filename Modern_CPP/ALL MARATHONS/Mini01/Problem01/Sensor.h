#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <ostream>
#include "SensorType.h"

class Sensor {
    
    private:
        const int _id;
        const std::string _name;
        const SensorType _type;
        int _reading;

    public:

        //Initial Setup
        Sensor() = delete;
        Sensor(const Sensor&) = default;
        Sensor(Sensor&&) = delete;
        Sensor& operator=(const Sensor&) = delete;
        Sensor& operator=(Sensor&&) = delete;
        ~Sensor() = default;

        // Parameterized Constructor
        Sensor(int id, std::string name, SensorType type, int reading);

        // Getters
        int id() const { return _id; }
        std::string name() const { return _name; }
        SensorType type() const { return _type; }
        int reading() const { return _reading; }

        friend std::ostream &operator<<(std::ostream &os, const Sensor &rhs);
};

#endif // SENSOR_H
