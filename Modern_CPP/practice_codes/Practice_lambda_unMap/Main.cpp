#include "Functionalities.h"

int main()
{
    TouristContainer data;
    // CreateObjects(data);
    // auto fn = [](TouristPointer& ptr,std::string id)->bool {
    //     return ptr->vehicleNumber() == id;
    // };
    // LambdaFun(data,fn,"202l");

    // auto ans = GetNInstancesByCondition(data,3);
    // for(TouristPointer& ptr : ans)
    // {
    //     std::cout<<*ptr<<"\n";
    // }

    // auto ans1 = GetAverageBookingChanrge(data,VehicleType::BIKE);
    // std::cout<<"average based on vehicle type: "<<ans1<<"\n";


    MapContainer mapData;
    // CreateObjects(data, mapData);

    createobj(mapData);

    auto ans = GetNInstancesByCondition(mapData, 3);
    for (TouristPointer &ptr : ans)
        std::cout << *ptr << "\n";

    float ans1 = GetAverageBookingChanrge(mapData,VehicleType::BIKE);
    std::cout<<"tyep: "<<ans1<<"\n";
}