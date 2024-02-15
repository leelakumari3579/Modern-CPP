#include "Functionalities.hpp"

std::function<void(std::reference_wrapper<TVContainer>)> LCreateObjects = [](TVContainer &data)->void {
    data.emplace_back(
        std::make_shared<TouristVehicle> (
            "tv101", VehicleType::CAB, 4, 34.05f,
            std::make_shared<Permit> (
                "p101", PermitType::LEASE, 4
            )
        )
    );

    data.emplace_back(
        std::make_shared<TouristVehicle> (
            "tv102", VehicleType::BIKE, 2, 28.0f,
            std::make_shared<Permit> (
                "p102", PermitType::OWNED, 2
            )
        )
    );

    data.emplace_back(
        std::make_shared<TouristVehicle> (
            "tv103", VehicleType::BUS, 14, 180.0f,
            std::make_shared<Permit> (
                "p103", PermitType::LEASE, 6
            )
        )
    );

    data.emplace_back(
        std::make_shared<TouristVehicle> (
            "tv104", VehicleType::CAB, 4, 34.05f,
            std::make_shared<Permit> (
                "p104", PermitType::OWNED, 4
            )
        )
    );

    data.emplace_back(
        std::make_shared<TouristVehicle> (
            "tv105", VehicleType::BIKE, 2, 28.0f,
            std::make_shared<Permit> (
                "p105", PermitType::LEASE, 2
            )
        )
    );

    data.emplace_back(
        std::make_shared<TouristVehicle> (
            "tv106", VehicleType::BUS, 14, 180.0f,
            std::make_shared<Permit> (
                "p106", PermitType::OWNED, 6
            )
        )
    );
};

std::function<std::vector<TouristVehicle>(TVContainer&, int)> LGetNInstancesByCondition = [](TVContainer &data, int N)->std::vector<TouristVehicle>
{
    /* Check for value of N */
    std::vector<TouristVehicle> vehicles;
    if(!data.empty()) {
        /* Do something */
        // int count {0};
        auto itr = data.begin();
        // for(TouristVehiclePointer& tvptr : data) {
        //     if(count == N) {
        //         break;
        //     }
        //     if(tvptr->seatCount() >= 4 && tvptr->permit()->permitType() == PermitType::LEASE) {
        //         vehicles.emplace_back(*tvptr.get());
        //     }
        //     count++;
        // }
        for(int i=0; i<N; i++, itr++) {
            if((*itr)->seatCount() >= 4 && (*itr)->permit()->permitType() == PermitType::LEASE) {
                vehicles.emplace_back(*(*itr).get());
            }
        }
        return vehicles;
    }
    throw std::runtime_error("Empty Container");
};

std::function<float(TVContainer&, VehicleType)> LGetAverageBookingCharge = [](TVContainer &data, VehicleType vType)->float
{
    /* Check for the value of N */
    float sum {0.0f};
    int count {0};
    if(!data.empty()) {
        for(const TouristVehiclePointer& tvptr : data) {
            if(tvptr->touristVehicleType() == vType)
                sum += tvptr->bookingChaarge();
                count++;
        }
    }
    return sum / count;
};

std::function<std::string(TVContainer&)> LGetSerialNumber = [](TVContainer &data)->std::string {
    float max {0};
    int index {0};
    if(!data.empty()) {
        auto itr = data.begin();
        for(int i=0; i<data.size(); i++, itr++) {
            if((*itr)->bookingChaarge() > max) {
                max = (*itr)->bookingChaarge();
                index = i;
            }
        }
    }
    return data[index]->permit()->serailNumber();
};

std::function<std::vector<TouristVehiclePointer>(TVContainer&, int)> LGetFirstNInstances = [](TVContainer & data, int N)->std::vector<TouristVehiclePointer>
{
    std::vector<TouristVehiclePointer> vehiclePointers;
    if(!data.empty()) {
        auto itr = data.begin();
        for(int i=0; i<N; i++, itr++) {
            vehiclePointers.emplace_back(*itr);
        }
    }
    return vehiclePointers;
};