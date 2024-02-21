#ifndef VEHICLE_H
#define VEHICLE_H
// #include <memory>
#include<functional>
#include <memory>
#include <ostream>
#include "ServiceRecord.h"

using ServiceRecordInstance = std::shared_ptr<ServiceRecord>;

class Vehicle
{
private:
    std::string _vehicle_id {"000"};
    int _active_duration_months {0};
    ServiceRecordInstance _latest_service_record;
public:
    Vehicle() = default;
    Vehicle(const Vehicle &) = default;
    Vehicle &operator=(const Vehicle &) = delete;
    Vehicle &operator=(Vehicle &&) = delete;
    Vehicle(Vehicle &&) = delete;
    ~Vehicle() = default;

    //parameterised constructor
    Vehicle(std::string id, int duration);
    Vehicle(std::string id, int duration, ServiceRecordInstance latestRecord);

    //getter setter methods
    std::string vehicleId() const { return _vehicle_id; }
    void setVehicleId(const std::string &vehicle_id) { _vehicle_id = vehicle_id; }

    int activeDurationMonths() const { return _active_duration_months; }
    void setActiveDurationMonths(int active_duration_months) { _active_duration_months = active_duration_months; }

    ServiceRecordInstance latestServiceRecord() const { return _latest_service_record; }
    void setLatestServiceRecord(const ServiceRecordInstance &latest_service_record) { _latest_service_record = latest_service_record; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};




#endif // VEHICLE_H
