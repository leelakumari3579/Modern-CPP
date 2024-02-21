#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <optional>
#include <iostream>

#include "Train.hpp"

using TrainPointer = std::shared_ptr<Train>;
using TrainContainer = std::vector<TrainPointer>;
using TicketContainers = std::array<TicketContainer, 3>;

void CreateObjects(TrainContainer& trData, TicketContainers& tcData);

int FindCountWithAtleast3Tickets(TrainContainer& data);

std::vector<Train> ReturnTrainsWithin3HoursDeparture(TrainContainer& data, int hour);

std::optional<float> CalculateTotalTicketPrices(TrainContainer& data, std::string trainNumber);

std::string getTrainStartingStation(TrainContainer& data, std::string trainNumber);

#endif // FUNCTIONALITIES_HPP
