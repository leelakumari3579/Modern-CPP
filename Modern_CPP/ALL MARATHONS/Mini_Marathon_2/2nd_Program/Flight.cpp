#include "Flight.h"
#include<iostream>


Flight::Flight(std::string flightOperatorCompany, FlightOperatorType flightOperatorType, AirPlane &airPlane)
:_flightOperatorCompany(flightOperatorCompany),_flightOperatorType(flightOperatorType),_airPlane(airPlane)
{
}
std::ostream &operator<<(std::ostream &os, const Flight &rhs) {
    os << "_flightOperatorCompany: " << rhs._flightOperatorCompany<<"\n"
       << " _airPlane: " << rhs._airPlane<<"\n";

    if(rhs._flightOperatorType==FlightOperatorType::DOMESTIC)
    {
        std::cout<<"FlightOperatorType::DOMESTIC"<<"\n";
    }   
    else if(rhs._flightOperatorType==FlightOperatorType::INTERNATIONAL)
    {
        std::cout<<"FlightOperatorType::INTERNATIONAL"<<"\n";
    }    


    return os;
}
