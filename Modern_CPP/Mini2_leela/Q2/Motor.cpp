#include "Motor.h"

Motor::Motor(float time, float maxPower, int maxTorque)
    :_time_0_to_100(time), _maxPower(maxPower), _maxTorque(maxTorque)
{
}

Motor Motor::operator+(Motor &m1)
{
    Motor sumObj;
    sumObj._time_0_to_100 = this->_time_0_to_100 + m1._time_0_to_100;
    sumObj._maxPower = this->_maxPower + m1._maxPower;
    sumObj._maxTorque = this->_maxTorque + m1._maxTorque;
    return sumObj;
}

std::ostream &operator<<(std::ostream &os, const Motor &rhs) {
    os << "_time_0_to_100: " << rhs._time_0_to_100 <<"\n"
       << " _maxPower: " << rhs._maxPower <<"\n"
       << " _maxTorque: " << rhs._maxTorque <<"\n";
    return os;
}
