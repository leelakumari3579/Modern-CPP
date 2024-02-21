#ifndef AIRPLANE_H
#define AIRPLANE_H

#include"AirPlaneType.h"
#include<string>
#include <ostream>

class AirPlane
{
private:
    std::string _airPlaneManufacturer;
    AirPlaneType _airPlaneType;
    int _airPlaneSeatCount;
    
public:
    AirPlane()=delete;
    AirPlane(const AirPlane&)=default;
    AirPlane(AirPlane&&)=default;
    AirPlane& operator=(const AirPlane&)=default;
    AirPlane& operator=(AirPlane&&)=delete;

    AirPlane(std::string airPlaneManufacturer,AirPlaneType airPlaneType,int airPlaneSeatCount);

    ~AirPlane()=default;

    std::string airPlaneManufacturer() const { return _airPlaneManufacturer; }
    void setAirPlaneManufacturer(const std::string &airPlaneManufacturer) { _airPlaneManufacturer = airPlaneManufacturer; }

    AirPlaneType airPlaneType() const { return _airPlaneType; }
    void setAirPlaneType(const AirPlaneType &airPlaneType) { _airPlaneType = airPlaneType; }

    int airPlaneSeatCount() const { return _airPlaneSeatCount; }
    void setAirPlaneSeatCount(int airPlaneSeatCount) { _airPlaneSeatCount = airPlaneSeatCount; }

    friend std::ostream &operator<<(std::ostream &os, const AirPlane &rhs);
};

#endif // AIRPLANE_H
