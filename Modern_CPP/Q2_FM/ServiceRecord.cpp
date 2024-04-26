#include "ServiceRecord.h"
std::ostream &operator<<(std::ostream &os, const ServiceRecord &rhs) {
    os << "_service_id: " << rhs._service_id
       << " _type: " ;
        switch(rhs._type)
        {
            case ServiceType::REGULAR:os<<"REGULAR";
            break;
            case ServiceType::REPAIR:os<<"REPAIR";
            break;
        }
     os << " _duration_hours: " << rhs._duration_hours
       << " _charges: " << rhs._charges
       << " _service_attendant_name: " << rhs._service_attendant_name
       << " _service_location: " << rhs._service_location;
    return os;
}

ServiceRecord::ServiceRecord(std::string id, ServiceType type, int duration, float charges, std::string name, std::string loc)
:_service_id(id),_type(type),_duration_hours(duration),_charges(charges),_service_attendant_name(name),_service_location(loc)
{
}