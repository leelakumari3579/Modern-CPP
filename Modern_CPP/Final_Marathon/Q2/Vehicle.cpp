#include "Vehicle.h"

Vehicle::Vehicle(std::string id, int duration)
    :_vehicle_id(id), _active_duration_months(duration)
{
}

Vehicle::Vehicle(std::string id, int duration, ServiceRecordInstance latestRecord)
    :Vehicle(id,duration)
{
    _latest_service_record = latestRecord;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_vehicle_id: " << rhs._vehicle_id
       << " _active_duration_months: " << rhs._active_duration_months
       << " _latest_service_record: " << rhs._latest_service_record.get();
    return os;
}
