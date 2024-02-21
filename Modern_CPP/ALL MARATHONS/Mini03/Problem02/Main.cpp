#include "Functionalities.hpp"
#include "NoMatchingRecordsException.hpp"
#include "EmptyContainerException.h"

int main() {
    TrainContainer trData;
    TicketContainers tcData;
    CreateObjects(trData, tcData);

    int result;

    try {
        std::cout << "Getting count of train with atleast 3 tickets booked: " << std::endl;
        result = FindCountWithAtleast3Tickets(trData);
        std::cout << result << std::endl;

    } catch(NoMatchingRecordsException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << "Getting trains whose departure time is within 3 hours of 19 : " << std::endl;
        std::vector<Train> trains = ReturnTrainsWithin3HoursDeparture(trData, 19);
        for(const Train& train : trains) {
            std::cout << train << std::endl;
        }

    } catch(NoMatchingRecordsException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << "Getting total ticket price of train : 155216" << std::endl;
        std::optional<float> total = CalculateTotalTicketPrices(trData, "155216");
        if(total.has_value()) {
            std::cout << "Total is: " << total.value() << std::endl;
        } else {
            std::cout << "No such a train found!" << std::endl;
        }

    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << "Getting Starting Train Station of Train : 115216" << std::endl;
        std::string starting = getTrainStartingStation(trData, "115216");
        std::cout << starting << std::endl;

    } catch(NoMatchingRecordsException& ex) {
        std::cout << ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout << ex.what() << std::endl;
    }
}