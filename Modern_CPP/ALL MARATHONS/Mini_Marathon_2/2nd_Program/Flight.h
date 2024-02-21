#ifndef FLIGHT_H
#define FLIGHT_H

#include"FlightOperatorType.h"
#include"AirPlane.h"
#include<string>
#include <ostream>
#include<functional>
class Flight
{
private:
    std::string _flightOperatorCompany;
    FlightOperatorType _flightOperatorType;
    std::reference_wrapper<AirPlane> _airPlane;


public:
    Flight()=delete;
    Flight(const Flight&)=default;
    Flight(Flight&&)=delete;
    Flight& operator=(const Flight&)=delete;
    Flight& operator=(Flight&&)=delete;
    ~Flight()=default;

    Flight(std::string flightOperatorCompany,FlightOperatorType flightOperatorType,
    AirPlane& airPlane);

    

    std::string flightOperatorCompany() const { return _flightOperatorCompany; }
    void setFlightOperatorCompany(const std::string &flightOperatorCompany) { _flightOperatorCompany = flightOperatorCompany; }

    FlightOperatorType flightOperatorType() const { return _flightOperatorType; }
    void setFlightOperatorType(const FlightOperatorType &flightOperatorType) { _flightOperatorType = flightOperatorType; }

    std::reference_wrapper<AirPlane> airPlane() const { return _airPlane; }
    void setAirPlane(const std::reference_wrapper<AirPlane> &airPlane) { _airPlane = airPlane; }

    

    friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);
};

#endif // FLIGHT_H
