#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <memory>
#include "Sensor.h"

using SensorPointer = std::shared_ptr<Sensor>;
using SensorContainer = std::vector<SensorPointer>;

void CreateObjects(SensorContainer& sensorData);

bool CheckSensorReadingAbove25ByType(const SensorContainer& sensorData, SensorType sensorType);

float CalculateAverageReadings(const SensorContainer& sensorData, SensorType sensorType);

std::vector<Sensor> GetInstancesByReadingAndType(const SensorContainer& sensorData);

#endif // FUNCTIONALITIES_H
