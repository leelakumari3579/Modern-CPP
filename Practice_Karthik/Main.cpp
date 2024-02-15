#include <iostream>
#include "Functionalities.hpp"

int main() {
    TVContainer data;
    LCreateObjects(data);

    auto res1 = LGetNInstancesByCondition(std::ref(data), 2);

    float res2 = LGetAverageBookingCharge(data, VehicleType::BUS);

    std::string res3 = LGetSerialNumber(data);

    auto res4 = LGetFirstNInstances(data, 3);

    /* Code for Standard Binding */
    // auto bindedRes4 = std::bind(std::ref(LGetFirstNInstances), data, std::placeholders::_1);
    // auto res4 = bindedRes4(3);

    // std::cout << res1 << std::endl;
    for(const TouristVehicle& tptr : res1) {
        std::cout << tptr << std::endl;
    }
    std::cout << res2 << std::endl;
    std::cout << res3 << std::endl;
    // std::cout << res1 << std::endl;
    for(const TouristVehiclePointer& tptr : res4) {
        std::cout << *tptr << std::endl;
    }

    
}