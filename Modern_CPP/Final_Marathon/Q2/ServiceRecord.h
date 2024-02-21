#ifndef SERVICERECORD_H
#define SERVICERECORD_H
#include "ServiceType.h"
#include <string>
#include <ostream>

class ServiceRecord
{
private:
    std::string _service_id {"000"};
    ServiceType _type {ServiceType::REGULAR};
    int _duration_hours {0};
    float _charges {0.0f};
    std::string _service_attendant_name {"xyz"};
    std::string _service_location {"abc"};
public:
    ServiceRecord() = default;
    ServiceRecord(const ServiceRecord &) = delete;
    ServiceRecord &operator=(const ServiceRecord &) = delete;
    ServiceRecord &operator=(ServiceRecord &&) = delete;
    ServiceRecord(ServiceRecord &&) = delete;
    ~ServiceRecord() = default;

    //parameterised constructor
    ServiceRecord(std::string id, ServiceType type, int hrs, float charge, std::string attendant, std::string location);

    //getter setter methods
    std::string serviceId() const { return _service_id; }
    void setServiceId(const std::string &service_id) { _service_id = service_id; }

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

    friend std::ostream &operator<<(std::ostream &os, const ServiceRecord &rhs);
    
};



#endif // SERVICERECORD_H
