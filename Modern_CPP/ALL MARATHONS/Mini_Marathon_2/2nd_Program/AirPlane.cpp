#include "AirPlane.h"
#include<iostream>


AirPlane::AirPlane(std::string airPlaneManufacturer, AirPlaneType airPlaneType, int airPlaneSeatCount)
:_airPlaneManufacturer(airPlaneManufacturer),_airPlaneType(airPlaneType),_airPlaneSeatCount(airPlaneSeatCount)
{
}
std::ostream &operator<<(std::ostream &os, const AirPlane &rhs) {
    os << "_airPlaneManufacturer: " << rhs._airPlaneManufacturer<<"\n"
       << " _airPlaneSeatCount: " << rhs._airPlaneSeatCount<<"\n";

    if(rhs._airPlaneType==AirPlaneType::NEO)
    {
        std::cout<<"Air plane type is NEO"<<"\n";
    } 
    else if(rhs._airPlaneType==AirPlaneType::JUMBO)
    {
        std::cout<<"Air plane type is JUMBO"<<"\n";
    }   
    else if(rhs._airPlaneType==AirPlaneType::CRUISELINER)
    {
        std::cout<<"Air plane type is CRUISELINER"<<"\n";
    }   
    std::cout<<"\n";  
    return os;
}
