#ifndef MOTOR_H
#define MOTOR_H
#include<iostream>
class Motor{
    private:
        float _time_0_to_100;
       const float _maxPower;
       const int _maxTorque;
    public:

        Motor()=delete;
        Motor(const Motor&)=delete;
        Motor(Motor&&)=default;
        Motor& operator=(const Motor&)=delete;
        Motor& operator=(Motor&&)=delete;
        ~Motor()=default;

        Motor( float _time_0_to_100,float _maxPower,int _maxTorque);

        float operator +(Motor& m);

        float time0To_100() const { return _time_0_to_100; }
        void setTime0To_100(float time_0_to_100) { _time_0_to_100 = time_0_to_100; }
        int maxTorque() const { return _maxTorque; }
        float maxPower() const { return _maxPower; }

        friend std::ostream &operator<<(std::ostream &os, const Motor &rhs);
    
};

#endif // MOTOR_H
