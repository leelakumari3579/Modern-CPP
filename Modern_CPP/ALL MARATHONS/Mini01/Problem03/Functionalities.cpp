#include <memory>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoMatchingRecordsFound.h"
#include "IllegalValueForNException.h"

void CreateObjects(TouristVehicleContainer &tVData)
{
    tVData.emplace_back(
        std::make_shared<TouristVehicle>(
            "tv101",
            VehicleType::BIKE,
            2,
            98.0f,
            std::make_shared<Permit>(
                "tv101s101",
                PermitType::LEASE,
                3
            ))
    );

    tVData.emplace_back(
        std::make_shared<TouristVehicle>(
            "tv102",
            VehicleType::BIKE,
            2,
            75.0f,
            std::make_shared<Permit>(
                "tv102s102",
                PermitType::OWNED,
                2
            ))
    );

    tVData.emplace_back(
        std::make_shared<TouristVehicle>(
            "tv103",
            VehicleType::CAB,
            4,
            150.0f,
            std::make_shared<Permit>(
                "tv103s103",
                PermitType::LEASE,
                1
            ))
    );

    tVData.emplace_back(
        std::make_shared<TouristVehicle>(
            "tv104",
            VehicleType::CAB,
            5,
            180.0f,
            std::make_shared<Permit>(
                "tv104s104",
                PermitType::OWNED,
                5
            ))
    );

    tVData.emplace_back(
        std::make_shared<TouristVehicle>(
            "tv105",
            VehicleType::BUS,
            15,
            420.0f,
            std::make_shared<Permit>(
                "tv105s105",
                PermitType::LEASE,
                4
            ))
    );

    tVData.emplace_back(
        std::make_shared<TouristVehicle>(
            "tv106",
            VehicleType::BUS,
            21,
            580.0f,
            std::make_shared<Permit>(
                "tv106s106",
                PermitType::OWNED,
                7
            ))
    );
}

std::vector<TouristVehicle> GetPermitInstancesBasedOnConditions(TouristVehicleContainer &tVData, int N)
{
    if (N < 0 || N > tVData.size()) {
        throw IllegalValueForNException("N value incorrect for GetPermitInstancesBasedOnConditions().");
    }
    if(!tVData.empty()) {
        std::vector<TouristVehicle> permits;
       auto itr=tVData.begin();
      for(int i=0;i<N;i++,itr++){
        if(itr->get()->seatCount()>4 && (*itr)->permit()->permitType()==PermitType::LEASE){
            permits.emplace_back((*itr).get()->permit());
        }
      }
        if(permits.empty()) {
            throw NoMatchingRecordsFoundException("No data matched the condition for GetPermitInstancesBasedOnConditions().");
        }
        return permits;
    }
    throw EmptyContainerException("No data in container for GetPermitInstancesBasedOnConditions().");
}

float AverageBookingChargeByType(TouristVehicleContainer &tVData, VehicleType vType) {
    if(!tVData.empty()) {
        int sum {0}, count {0};
        for(const TouristVehiclePointer& tvptr : tVData) {
            if(tvptr->vehicleType() == vType) {
                sum += tvptr->perHourBookingCharge();
                count++;
            }
        }
        if(count == 0) {
            throw NoMatchingRecordsFoundException("No data matched the condition for AverageBookingChargeByType().");
        }
        return sum / count;
    }
    throw EmptyContainerException("No data in container for AverageBookingChargeByType().");
}

std::string FindSerialNumberByTVMAXBookingCharge(TouristVehicleContainer &tVData)
{
    if(!tVData.empty()) {
        int maxIndex {0};
        float maxCharge {0.0f};
        auto itr = tVData.begin();
        for(int i=0; i<tVData.size(); i++, itr++) {
            if((*itr)->perHourBookingCharge() > maxCharge) {
                maxCharge = (*itr)->perHourBookingCharge();
                maxIndex = i;
            }
        }
        return tVData[maxIndex]->permit()->serialNumber();
    }
    throw EmptyContainerException("No data in container for FindSerialNumberByTVMAXBookingCharge().");
}

std::vector<TouristVehiclePointer> GetFirstNTV(TouristVehicleContainer &tVData, int N)
{
    if(!tVData.empty()) {
        if (N < 0 || N > tVData.size()) {
            throw IllegalValueForNException("N value incorrect for GetPermitInstancesBasedOnConditions().");
        }
        std::vector<TouristVehiclePointer> vehicles;
        auto itr = tVData.begin();
        for(int i=0; i<N; i++, itr++) {
            vehicles.emplace_back((*itr));
        }
        return vehicles;
    }
    throw EmptyContainerException("No data in container for GetFirstNTV().");
}
