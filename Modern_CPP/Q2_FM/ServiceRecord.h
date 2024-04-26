#ifndef SERVICERECORD_H
#define SERVICERECORD_H

#include<iostream>
#include"ServiceType.h"

class ServiceRecord
{
private:
    const std::string _service_id;
    ServiceType _type;
    int _duration_hours;
    float _charges;
    std::string _service_attendant_name;
    std::string _service_location;

public:
//special member functions
    ServiceRecord()=delete;
    ServiceRecord(const ServiceRecord&)=delete;
    ServiceRecord& operator=(const ServiceRecord&)=delete;
    ServiceRecord(ServiceRecord&&)=delete;
    ServiceRecord& operator=(ServiceRecord&&)=delete;
    ~ServiceRecord()=default;

//Getters and setters
    std::string serviceId() const { return _service_id; }
    ServiceType type() const { return _type; }
    void setType(const ServiceType &type) { _type = type; }
    int durationHours() const { return _duration_hours; }
    void setDurationHours(int duration_hours) { _duration_hours = duration_hours; }
    float charges() const { return _charges; }
    void setCharges(float charges) { _charges = charges; }
    std::string serviceAttendantName() const { return _service_attendant_name; }
    void setServiceAttendantName(const std::string &service_attendant_name) { _service_attendant_name = service_attendant_name; }
    std::string serviceLocation() const { return _service_location; }
    void setServiceLocation(const std::string &service_location) { _service_location = service_location; }

//parameterized constructor
    ServiceRecord(std::string id,ServiceType type,int duration,float charges,std::string name,std::string loc);

//member function
    friend std::ostream &operator<<(std::ostream &os, const ServiceRecord &rhs);

    
};

#endif // SERVICERECORD_H
