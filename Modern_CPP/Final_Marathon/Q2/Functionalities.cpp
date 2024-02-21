#include "Functionalities.h"
#include <algorithm>
#include <numeric>

void CreateObjects(VehicleContainer &data)
{
    data.emplace_back(std::make_shared<Vehicle>("102l", 3,
                                                std::make_shared<ServiceRecord>("201l", ServiceType::REGULAR, 3, 500.0f, "sagar", "bangalore")));
    data.emplace_back(std::make_shared<Vehicle>("103l", 5,
                                                std::make_shared<ServiceRecord>("202l", ServiceType::REPAIR, 9, 1700.0f, "udhay", "hyderabad")));
    data.emplace_back(std::make_shared<Vehicle>("107l", 2,
                                                std::make_shared<ServiceRecord>("203l", ServiceType::REGULAR, 1, 400.0f, "rani", "pune")));
    data.emplace_back(std::make_shared<Vehicle>("104l", 7,
                                                std::make_shared<ServiceRecord>("204l", ServiceType::REGULAR, 2, 120.0f, "kiran", "vizag")));
    data.emplace_back(std::make_shared<Vehicle>("105l", 10,
                                                std::make_shared<ServiceRecord>("205l", ServiceType::REPAIR, 8, 2000.0f, "umesh", "bangalore")));
}

VehicleContainer ReturnListOfLastNinstances(VehicleContainer &data, int n)
{
    if (data.empty())
        throw EmptyContainerException("Container empty!!");
    VehicleContainer result;
    std::for_each(
        data.end() - n,
        data.end(),
        [&](VehiclePointer &data)
        {
            return result.emplace_back(data);
        });
    if (result.empty())
        throw NoMatchingInstanceException("No matching instrance found!!");
    return result;
}

std::unordered_map<std::string, std::string> ReturnDictionary(VehicleContainer &data, std::vector<std::string> ids)
{
    if (data.empty())
        throw EmptyContainerException("Container empty!!");
    std::unordered_map<std::string, std::string> result;
    int i = 0;
    std::for_each(
        data.begin(),
        data.end(),
        [&](VehiclePointer &ptr)
        {
            if (ids[i++] == ptr->vehicleId())
            {
                return result.emplace(std::make_pair<std::string, std::string>(ptr->vehicleId(), ptr->latestServiceRecord()->serviceId()));
            }
        });
    return result;
    if (result.empty())
        throw NoMatchingInstanceException("No matching instrance found!!");
}

std::unordered_map<std::string, ServiceRecordPointer> ReturnDictionaryOfLatestRecord(VehicleContainer &data)
{
    if (data.empty())
        throw EmptyContainerException("Container empty!!");
    std::unordered_map<std::string,ServiceRecordPointer> result;

    auto max = std::max_element(
        data.begin(),
        data.end(),
        [](VehiclePointer &ptr,VehiclePointer& ptr1){
            return ptr->latestServiceRecord()->charges() > ptr1->latestServiceRecord()->charges();
        }
    );
    auto max_ele = (*max)->latestServiceRecord()->charges();
    std::for_each(
        data.begin(),
        data.end(),
        [&](VehiclePointer &ptr)
        {
            if (ptr->latestServiceRecord()->charges() == max_ele)
            {
                return result.emplace(std::make_pair<std::string,ServiceRecordPointer>(ptr->vehicleId(),ptr->latestServiceRecord()));
            }
        });
    return result;
    if (result.empty())
        throw NoMatchingInstanceException("No matching instrance found!!");
}

float AvegrageChargesofServiceRecord(VehicleContainer &data)
{
    if (data.empty())
        throw EmptyContainerException("Container empty!!");
    int count = 0;
    auto ans = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float total,VehiclePointer& ptr) {
            if(ptr->latestServiceRecord()->type() == ServiceType::REGULAR)
            {
                return total + ptr->latestServiceRecord()->charges();
                count++;
            }
        }
    );
    if (ans == 0)
        throw NoMatchingInstanceException("No matching instrance found!!");
    return (float)ans/count;
}

std::string ReturnVehicleIdByServiceId(VehicleContainer &data, std::string serviceId)
{
    if (data.empty())
        throw EmptyContainerException("Container empty!!");
    auto ans = std::find_if(
        data.begin(),
        data.end(),
        [&](VehiclePointer& ptr) {
            return ptr->latestServiceRecord()->serviceId() == serviceId;
        }
    );
    return (*ans)->vehicleId();
}
