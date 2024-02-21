#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoMatchingRecordsFound.h"

void CreateObjects(SensorContainer& sensorData) {
    sensorData.emplace_back(
        std::make_shared<Sensor>(
            101,
            "Temperature Sensor",
            SensorType::TEMPERATURE,
            13
        )
    );

    sensorData.emplace_back(
        std::make_shared<Sensor>(
            102,
            "Pressure Sensor",
            SensorType::CABIN_PRESSURE,
            8
        )
    );

    sensorData.emplace_back(
        std::make_shared<Sensor>(
            103,
            "Vaccuum Sensor",
            SensorType::TYRE_PRESSURE,
            16
        )
    );
}

bool CheckSensorReadingAbove25ByType(const SensorContainer &sensorData, SensorType sensorType) {
    if(!sensorData.empty()) {
        bool flag {false};
        for(SensorPointer sptr : sensorData) {
            if(sptr->type() == sensorType && sptr->reading() > 25) {
                flag = true;
                break;
            }
        }
        return flag;
    }
    throw EmptyContainerException("Sensor Container is empty for CheckSensorReadingAbove25ByType() function.");
}

float CalculateAverageReadings(const SensorContainer &sensorData, SensorType sensorType)
{
    if(!sensorData.empty()) {
        int count {0}, sum {0};
        for(SensorPointer sptr : sensorData) {
            if(sptr->type() == sensorType) {
                sum += sptr.get()->reading();
                count++;
            }
        }
        if(count == 0) {
            throw NoMatchingRecordsFoundException("No sensor matching conditions found in CalculateAverageReadings().");
        }
        return sum / count;
    }
    throw EmptyContainerException("Sensor Container is empty for CalculateAverageReadings() function.");
}

std::vector<Sensor> GetInstancesByReadingAndType(const SensorContainer &sensorData)
{
    if(!sensorData.empty()) {
        std::vector<Sensor> sensors;
        for(SensorPointer sptr : sensorData) {
            if(sptr->type() == SensorType::TYRE_PRESSURE && sptr->reading() >= 15) {
                sensors.emplace_back(*sptr);
            }
        }
        if(sensors.empty()) {
            throw NoMatchingRecordsFoundException("No sensor matching conditions found in GetInstancesByReadingAndType().");
        }
        return sensors;
    }
    throw EmptyContainerException("Sensor Container is empty for GetInstancesByReadingAndType() function.");
}
