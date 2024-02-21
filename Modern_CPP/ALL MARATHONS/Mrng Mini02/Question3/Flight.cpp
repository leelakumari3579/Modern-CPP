#include"Flight.h"

std::ostream &operator<<(std::ostream &os, const Flight &rhs) {
    os << "_duration_minutes: " << rhs._duration_minutes<<std::endl;
      os << " _ticket_price: " << rhs._ticket_price<<std::endl;
      os << " _plane: " << *(rhs._plane.get());
    return os;
}

Flight::Flight(int durationminutes, float ticketprice,ReferenceWrapper plane)
:_duration_minutes{durationminutes},_ticket_price{ticketprice},_plane{plane}
{
}


