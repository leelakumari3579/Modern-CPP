#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <vector>
#include <string>
#include <ostream>
#include <memory>

#include "TrainTicket.hpp"

using TicketPointer = std::shared_ptr<TrainTicket>;
using TicketContainer = std::vector<TicketPointer>;

class Train {

    private:
        std::string _trainNumber;
        std::string _trainStartingStation;
        std::string _trainDestinationStation;
        int _trainDepartureHour;
        int _trainDepartureMinute;
        TicketContainer _trainBookedTickets;

    public:
        // Initial Setup
            Train() = delete;
            Train(const Train&) = default;
            Train(Train&&) = delete;
            Train operator=(const Train&) = delete;
            Train operator=(Train&&) = delete;
            ~Train() = default;

        // Parameterized Constructor
            Train(std::string trainNumber, std::string trainSS, std::string trainDS, int trainDH, int trainDM, TicketContainer trainBT);

            
        // Getters
            std::string trainNumber() const { return _trainNumber; }
            std::string TrainStartingStation() const { return _trainStartingStation; }
            std::string TrainDestinationStation() const { return _trainDestinationStation; }
            int trainDepartureHour() const { return _trainDepartureHour; }
            int trainDepartureMinute() const { return _trainDepartureMinute; }
            TicketContainer trainBookedTickets() const { return _trainBookedTickets; }

        // Operator Overloading
            friend std::ostream &operator<<(std::ostream &os, const Train &rhs);

            
        
        
};

#endif // TRAIN_HPP
