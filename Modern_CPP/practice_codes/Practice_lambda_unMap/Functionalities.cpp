#include "Functionalities.h"

// void CreateObjects(TouristContainer & data)
// {
// data.emplace_back(std::make_shared<TouristVehicle>("202l",VehicleType::BIKE,3,579.3f,std::make_shared<Permit>("111l",PermitType::OWNED,5)));
// data.emplace_back(std::make_shared<TouristVehicle>("203l",VehicleType::BUS,4,57.3f,std::make_shared<Permit>("144l",PermitType::LEASE,2)));
// data.emplace_back(std::make_shared<TouristVehicle>("204l",VehicleType::CAB,5,1000.0f,std::make_shared<Permit>("133l",PermitType::OWNED,4)));
// data.emplace_back(std::make_shared<TouristVehicle>("205l",VehicleType::BIKE,1,50.78f,std::make_shared<Permit>("122l",PermitType::OWNED,9)));
// }

// void LambdaFun(TouristContainer &data, std::function<bool(TouristPointer &, std::string)> fn, std::string id)
// {
//     for(TouristPointer& ptr : data)
//     {
//         if(fn(ptr,id))
//         {
//             std::cout<<*ptr<<"\n";
//         }
//     }
// }

// std::function<TouristContainer(TouristContainer&,int)> GetNInstancesByCondition = [](TouristContainer& data, int n)->TouristContainer
// {
//     TouristContainer result;
//     int count = 0;
//     for(TouristPointer& ptr : data)
//     {
//         if(count == n)
//             break;
//         else
//         {
//             if(ptr->seatCount()>=4 && ptr->permit()->permitType() == PermitType::LEASE)
//                 result.emplace_back(ptr);
//         }
//         count++;
//     }
//     return result;
// };

// std::function<float(TouristContainer&,VehicleType)> GetAverageBookingChanrge = [](TouristContainer& data,VehicleType vt) ->float
// {
//     float result = 0.0f;
//     int count = 0;
//     for(TouristPointer& ptr : data)
//     {
//         if(ptr->touristVehicleType() == vt)
//         {
//             result += ptr->bookingChaarge();
//             count++;
//         }
//     }
//     return result/count;
// };

void CreateObjects(TouristContainer &data, MapContainer &mapData)
{
    data.emplace_back(std::make_shared<TouristVehicle>("202l", VehicleType::BIKE, 3, 579.3f, std::make_shared<Permit>("111l", PermitType::OWNED, 5)));
    data.emplace_back(std::make_shared<TouristVehicle>("203l", VehicleType::BUS, 4, 57.3f, std::make_shared<Permit>("144l", PermitType::LEASE, 2)));
    data.emplace_back(std::make_shared<TouristVehicle>("204l", VehicleType::CAB, 5, 1000.0f, std::make_shared<Permit>("133l", PermitType::OWNED, 4)));
    data.emplace_back(std::make_shared<TouristVehicle>("205l", VehicleType::BIKE, 1, 50.78f, std::make_shared<Permit>("122l", PermitType::OWNED, 9)));

    mapData.emplace(std::make_pair<std::string, TouristPointer>(data[0]->vehicleNumber(), std::move(data[0])));
    mapData.emplace(std::make_pair<std::string, TouristPointer>(data[1]->vehicleNumber(), std::move(data[1])));
    mapData.emplace(std::make_pair<std::string, TouristPointer>(data[2]->vehicleNumber(), std::move(data[2])));
    mapData.emplace(std::make_pair<std::string, TouristPointer>(data[3]->vehicleNumber(), std::move(data[3])));
}

TouristContainer GetNInstancesByCondition(MapContainer &mapData, int n)
{
    TouristContainer result;
    int count = 0;
    for (std::pair<std::string, TouristPointer> &&ptr : mapData)
    {
        if (count == n)
            break;
        if (ptr.second->seatCount() >= 4 && ptr.second->permit()->permitType() == PermitType::LEASE)
        {
            result.emplace_back(ptr.second);
            count++;
        }
    }
    return result;
}

float GetAverageBookingChanrge(MapContainer &mapData, VehicleType vt)
{
    float sum = 0.0f;
    int count = 0;
    for(std::pair<std::string,TouristPointer>&& ptr : mapData)
    {
        if(ptr.second->touristVehicleType() == vt)
        {
            sum += ptr.second->bookingChaarge();
            count++;
        }
    }
    return sum/count;
}


void createobj(MapContainer& map)
{
    map.emplace(std::make_pair<std::string,TouristPointer>("A",std::make_shared<TouristVehicle>("202l", VehicleType::BIKE, 3, 579.3f, std::make_shared<Permit>("111l", PermitType::OWNED, 5))));
    map.emplace(std::make_pair<std::string,TouristPointer>("B",std::make_shared<TouristVehicle>("203l", VehicleType::BUS, 4, 57.3f, std::make_shared<Permit>("144l", PermitType::LEASE, 2))));
    std::cout<<"...";
}
