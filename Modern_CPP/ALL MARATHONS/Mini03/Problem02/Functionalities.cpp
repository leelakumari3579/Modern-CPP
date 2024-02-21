#include "Functionalities.hpp"
#include "EmptyContainerException.h"
#include "NoMatchingRecordsException.hpp"

void CreateObjects(TrainContainer &trData, TicketContainers &tcData) {
    tcData[0].emplace_back(
        std::make_shared<TrainTicket>(
            150.0f, TicketType::GENERAL, TicketClass::SECOND
        )
    );

    tcData[0].emplace_back(
        std::make_shared<TrainTicket>(
            1500.0f, TicketType::RESERVED, TicketClass::AC
        )
    );

    tcData[0].emplace_back(
        std::make_shared<TrainTicket>(
            350.0f, TicketType::RESERVED, TicketClass::SLEEPER
        )
    );

    tcData[0].emplace_back(
        std::make_shared<TrainTicket>(
            350.0f, TicketType::WAITING, TicketClass::SLEEPER
        )
    );

    tcData[1].emplace_back(
        std::make_shared<TrainTicket>(
            250.0f, TicketType::GENERAL, TicketClass::SECOND
        )
    );

    tcData[1].emplace_back(
        std::make_shared<TrainTicket>(
            850.0f, TicketType::RESERVED, TicketClass::SLEEPER
        )
    );

    tcData[2].emplace_back(
        std::make_shared<TrainTicket>(
            3500.0f, TicketType::RESERVED, TicketClass::AC
        )
    );

    tcData[2].emplace_back(
        std::make_shared<TrainTicket>(
            1700.0f, TicketType::RESERVED, TicketClass::SECOND
        )
    );

    trData.emplace_back(
        std::make_shared<Train>(
            "155216",
            "Belagavi",
            "Pune",
            16,
            50,
            tcData[0]
        )
    );

    trData.emplace_back(
        std::make_shared<Train>(
            "155217",
            "Belagavi",
            "Bangalore",
            19,
            15,
            tcData[1]
        )
    );

    trData.emplace_back(
        std::make_shared<Train>(
            "155218",
            "Belagavi",
            "Patna",
            12,
            48,
            tcData[2]
        )
    );
}

int FindCountWithAtleast3Tickets(TrainContainer &data) {
    if(!data.empty()) {
        int count {0};
        for(const TrainPointer& tptr : data) {
            if(tptr->trainBookedTickets().size() >= 3) {
                count++;
            }
        }
        if(count == 0) {
            throw NoMatchingRecordsException("No records matching the specified condition for FindCountWithAtleast3Tickets!");
        }
        return count;
    }
    throw EmptyContainerException("Data Empty for FindCountWithAtleast3Tickets!");
}

std::vector<Train> ReturnTrainsWithin3HoursDeparture(TrainContainer &data, int hour) {
    if(!data.empty()) {
        std::vector<Train> trains;
        for(const TrainPointer& tptr: data) {
            if(tptr->trainDepartureHour() + 3 <= hour) {
                trains.emplace_back(*(tptr.get()));
            }
        }
        if(trains.empty()) {
            throw NoMatchingRecordsException("No records matching the specified condition for ReturnTrainsWithin3HoursDeparture!");
        }
        return trains;
    }
    throw EmptyContainerException("Data Empty for FindCountWithAtleast3Tickets!");
}

std::optional<float> CalculateTotalTicketPrices(TrainContainer &data, std::string trainNumber) {
    if(!data.empty()) {
        float totalPrice {0.0f};
        for(const TrainPointer& tptr: data) {
            if(tptr->trainNumber() == trainNumber) {
                for(const TicketPointer& tcptr : tptr->trainBookedTickets()) {
                    totalPrice += tcptr->ticketPrice();
                }
                break;
            }
        }
        if(totalPrice == 0) {
            return std::nullopt;
        }
        return totalPrice;
    }
    throw EmptyContainerException("Data Empty for CalculateTotalTicketPrices!");
}

std::string getTrainStartingStation(TrainContainer &data, std::string trainNumber) {
    if(!data.empty()) {
        float totalPrice {0.0f};
        int index {-1};
        for(const TrainPointer& tptr: data) {
            index++;
            if(tptr->trainNumber() == trainNumber) {
                for(const TicketPointer& tcptr : tptr->trainBookedTickets()) {
                    totalPrice += tcptr->ticketPrice();
                }
                break;
            }
        }
        if(!(15<=data[index]->trainDepartureHour()<=16) && (totalPrice >= 2000) ) {
            throw NoMatchingRecordsException("No records matching the specified condition for getTrainStartingStation!");
        }
        return data[index]->TrainStartingStation();
    }
    throw EmptyContainerException("Data Empty for getTrainStartingStation!");
}
