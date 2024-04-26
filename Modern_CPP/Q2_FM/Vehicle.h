#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<memory>
#include"ServiceRecord.h"


using ServiceRecordPointer=std::shared_ptr<ServiceRecord>;
class Vehicle
{
private:
    const std::string _vehicle_id;
    int _active_duration_months;
    ServiceRecordPointer _latest_service_record;

public:
//Special member functions
    Vehicle()=delete;
    Vehicle(const Vehicle&)=delete;
    Vehicle& operator=(const Vehicle&)=delete;
    Vehicle(Vehicle&&)=delete;
    Vehicle& operator=(Vehicle&&)=delete;
    ~Vehicle()=default;

//Getters and setters
    std::string vehicleId() const { return _vehicle_id; }
    int activeDurationMonths() const { return _active_duration_months; }
    void setActiveDurationMonths(int active_duration_months) { _active_duration_months = active_duration_months; }
    ServiceRecordPointer latestServiceRecord() const { return _latest_service_record; }
    void setLatestServiceRecord(const ServiceRecordPointer &latest_service_record) { _latest_service_record = latest_service_record; }

//Parameterized constructor

    Vehicle(std::string id,int months,ServiceRecordPointer record);
    
//member functions
    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
    




};

#endif // VEHICLE_H
