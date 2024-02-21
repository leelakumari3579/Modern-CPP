#ifndef ROOM_H
#define ROOM_H

#include"RoomType.h"
#include <ostream>
class Room 
{
    private:
        const float _area;
        float _price;
        RoomType _roomtype;
    public:
        Room()=delete;
        Room(const Room&)=default;
        Room(Room&&)=default;
        Room& operator=(const Room&)=delete;
        Room& operator=(Room&&)=delete;
        ~Room()=default;

        Room(float area,float price,RoomType roomtype);

        float area() const { return _area; }

        float price() const { return _price; }

        void setPrice(float price) { _price = price; }

        RoomType roomtype() const { return _roomtype; }

        friend std::ostream &operator<<(std::ostream &os, const Room &rhs);

        float calculateTaxAmount();        


};

#endif // ROOM_H
