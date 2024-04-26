#include "Functionalities.h"

void CreateObjects(VehicleContainer &data)
{

    data.emplace_back(std::make_shared<Vehicle>(
    "V101",
    12,
    std::make_shared<ServiceRecord>(
        "S101",
        ServiceType::REGULAR,
        3,
        1000.0f,
        "Murali",
        "Pune")));

    data.emplace_back(std::make_shared<Vehicle>(
        "V102",
        11,
        std::make_shared<ServiceRecord>(
            "S102",
            ServiceType::REPAIR,
            5,
            5000.0f,
            "Varma",
            "Nellore")));

    data.emplace_back(std::make_shared<Vehicle>(
        "V103",
        24,
        std::make_shared<ServiceRecord>(
            "S103",
            ServiceType::REGULAR,
            3,
            2000.0f,
            "Uday",
            "Hyderabad")));

    data.emplace_back(std::make_shared<Vehicle>(
        "V104",
        12,
        std::make_shared<ServiceRecord>(
            "S104",
            ServiceType::REGULAR,
            7,
            10000.0f,
            "Vijay",
            "Telangana"))); 
            
    data.emplace_back(std::make_shared<Vehicle>(
        "V105",
        13,
        std::make_shared<ServiceRecord>(
            "S105",
            ServiceType::REPAIR,
            8,
            5000.0f,
            "Ravi",
            "Pune")));
}

std::optional<std::list<VehiclePointer>> FindLastNinstances(VehicleContainer &data, int n)
{
    if(data.empty())
    {
        throw EmptyContainerException("Conatiner is empty!!!");
    }
    
    std::list<VehiclePointer> result;
    if(n<0 || n>data.size())
    {
        return std::nullopt;
    }
    for(int i=n;i<data.size();i++)
    {
        result.emplace_back(data[i]);
    }
    return result;
}

std::unordered_map<std::string, std::string> FindPairByVehicleId(VehicleContainer &data,  std::list<std::string> &id)
{
    if(data.empty())
    {
        throw EmptyContainerException("Conatiner is empty!!!");
    }

    std::unordered_map<std::string,std::string> result;
    for(VehiclePointer& ptr:data)
    {
        for(auto itr:id)
        {
            if(ptr->latestServiceRecord()->serviceId()==itr)
            {
                result.emplace(std::pair<std::string,std::string>(ptr->vehicleId(),ptr->latestServiceRecord()->serviceId()));
            }
        }
    }
    return result;
}

std::unordered_map<std::string, ServicePointer> FindMaximumServiceChargeInstance(VehicleContainer &data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Conatiner is empty!!!");
    }

    std::unordered_map<std::string,ServicePointer> result;
    auto itr=std::max_element(data.begin(),data.end(),[](VehiclePointer& ptr1,VehiclePointer& ptr2){
        return ptr1->latestServiceRecord()->charges()>ptr2->latestServiceRecord()->charges();
    });

    result.emplace(std::pair<std::string, ServicePointer>((*itr)->vehicleId(),(*itr)->latestServiceRecord()));
    return result;
}

float AverageChargesOfRegularType(VehicleContainer &data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Conatiner is empty!!!");
    }

    float ans=std::accumulate(data.begin(),data.end(),0.0f,[](float total,VehiclePointer& ptr){
        if(ptr->latestServiceRecord()->type()==ServiceType::REGULAR)
            total+=ptr->latestServiceRecord()->charges();
        return total;
    });
    return ans/data.size();
}

std::optional<std::string> FindVehicleIdByServiceId(VehicleContainer &data, std::string serviceid)
{
    if(data.empty())
    {
        throw EmptyContainerException("Conatiner is empty!!!");
    }

   auto itr= std::find_if(data.begin(),data.end(),[&](VehiclePointer& ptr){
    return ptr->latestServiceRecord()->serviceId()==serviceid;
   });

   if(itr==data.end())
   {
        return std::nullopt;
   }
   return (*itr)->vehicleId();
}
