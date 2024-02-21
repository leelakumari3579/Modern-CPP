#include "Train.hpp"
std::ostream &operator<<(std::ostream &os, const Train &rhs) {
    os << "_trainNumber: " << rhs._trainNumber
       << " trainStartingStation: " << rhs._trainStartingStation
       << " trainDestinationStation: " << rhs._trainDestinationStation
       << " _trainDepartureHour: " << rhs._trainDepartureHour
       << " _trainDepartureMinute: " << rhs._trainDepartureMinute;
       os << std::endl;
       for(const TicketPointer& ticket : rhs._trainBookedTickets) {
            os << *ticket << std::endl;
       }
    //    << " _trainBookedTickets: " << rhs._trainBookedTickets;
    return os;
}

Train::Train(std::string trainNumber, std::string trainSS, std::string trainDS, int trainDH, int trainDM, TicketContainer trainBT):
_trainNumber(trainNumber), _trainStartingStation(trainSS), _trainDestinationStation(trainDS),
_trainDepartureHour(trainDH), _trainDepartureMinute(trainDM), _trainBookedTickets(trainBT) {}