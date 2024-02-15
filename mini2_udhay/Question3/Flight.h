#ifndef FLIGHT_H
#define FLIGHT_H
#include<functional>
#include <ostream>
#include"Plane.h"
#include<memory>

using ReferenceWrapper = std::reference_wrapper<std::shared_ptr<Plane>>;

class Flight
{

private:

    int _duration_minutes;
    float _ticket_price;
    ReferenceWrapper _plane;

public:

    Flight(int durationminutes,float ticketprice,ReferenceWrapper plane);

    Flight() =delete;
    Flight(const Flight&)=default;
    Flight(Flight&&)=default;
    Flight& operator=(const Flight&)=default;
    Flight& operator=(Flight&&)=default;
    ~Flight()=default;

    int durationMinutes() const { return _duration_minutes; }

    float ticketPrice() const { return _ticket_price; }
    void setTicketPrice(float ticket_price) { _ticket_price = ticket_price; }

    ReferenceWrapper plane() const { return _plane; }
    void setPlane(const ReferenceWrapper &plane) { _plane = plane; }

    friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);
    
};

#endif // FLIGHT_H
