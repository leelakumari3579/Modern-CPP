#include "Funtionalities.h"

void create(container& data)
{
    data.push_back(std::make_shared<Ev2>(1,ElectricType::REGULAR,23,34,23,23,ConnectedType::DIGITAL));
    data.push_back(std::make_shared<Ev2>(3,ElectricType::REGULAR,23,34,23,23,ConnectedType::DIGITAL));
    data.push_back(std::make_shared<Ev2>(2,ElectricType::REGULAR,23,34,23,23,ConnectedType::DIGITAL));
    data.push_back(std::make_shared<EvCar>(1,ElectricType::TRANSPORT,234,34,543,34,ChargingType::DC_FAST_CHARGE));
    data.push_back(std::make_shared<EvCar>(1,ElectricType::TRANSPORT,234,34,543,34,ChargingType::DC_FAST_CHARGE));

}

void display(container& data,int id){
    for(const auto&val :data){
        if(val.get()->id()==id){
            std::cout<<*val <<std::endl;
        }
    }
}
