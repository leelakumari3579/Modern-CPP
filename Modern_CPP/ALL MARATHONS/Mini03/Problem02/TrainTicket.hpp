#ifndef TRAINTICKET_HPP
#define TRAINTICKET_HPP

#include "TicketType.hpp"
#include "TicketClass.hpp"
#include <ostream>

class TrainTicket {

    private:
        float _ticketPrice;
        TicketType _ticketType;
        TicketClass _ticketClass;

    public:

        // Initial Setup
            TrainTicket() = delete;
            TrainTicket(const TrainTicket&) = delete;
            TrainTicket(TrainTicket&&) = delete;
            TrainTicket operator=(const TrainTicket&) = delete;
            TrainTicket operator=(TrainTicket&&) = delete;
            ~TrainTicket() = default;

        // Parameterized Constructor
            TrainTicket(float ticketPrice, TicketType ticketType, TicketClass ticketClass);

        // Getters
            float ticketPrice() const { return _ticketPrice; }
            TicketType ticketType() const { return _ticketType; }
            TicketClass ticketClass() const { return _ticketClass; }


        // Operator Overloading
            friend std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs);
};

#endif // TRAINTICKET_HPP
