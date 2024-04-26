#include "Vehicle.h"
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_vehicle_id: " << rhs._vehicle_id
       << " _active_duration_months: " << rhs._active_duration_months
       << " _latest_service_record: " << *(rhs._latest_service_record);
    return os;
}

Vehicle::Vehicle(std::string id, int months, ServiceRecordPointer record)
:_vehicle_id(id),_active_duration_months(months),_latest_service_record(record)
{
}