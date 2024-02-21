#include <iostream>
#include "Functionalities.h"

int main() {
    // Declaring container of Sensors.
    SensorContainer sensorData;

    // Creating Objects
    CreateObjects(sensorData);

    // Checking for Sensor readings > 25.
    std::cout << "Checking for Sensor Reading above 25 for type CABIN_PRESSURE..." << std::endl;
    bool bresult = CheckSensorReadingAbove25ByType(sensorData, SensorType::CABIN_PRESSURE);
    bresult ? 
        std::cout<<"Found sensors reading values above 25!!"<<std::endl :
        std::cout<<"No sensors found with reading values above 25!!"<<std::endl;

    std::cout << std::endl;

    // Calculating average sensor readings based on type matching.
    std::cout << "Calculating Average Readings of Sensors of Type TYRE_PRESSURE..."<<std::endl;
    float fresult = CalculateAverageReadings(sensorData, SensorType::TYRE_PRESSURE);
    std::cout << "Average: " << fresult << std::endl;

    std::cout << std::endl;

    // Getting instances of sensors with reading > 15 and type TYRE_PRESSURE
    std::cout << "Getting instances of sensors with reading > 15 and type TYRE_PRESSURE..."<<std::endl;
    std::vector<Sensor> sensors = GetInstancesByReadingAndType(sensorData);

    for(Sensor sptr : sensors) {
        std::cout << sptr << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Thanks for using the system." << std::endl;
}