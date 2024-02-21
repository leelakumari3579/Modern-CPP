#ifndef HOTEL_H
#define HOTEL_H
#include "Room.h"
#include "CategoryType.h"
#include<memory>
#include <ostream>

using RoomPointer = std::shared_ptr<Room>;

class Hotel
{
private:
   const std::string _name;
    const unsigned int _location_code;
    RoomPointer _room;
    CategoryType _category;
public:
    Hotel()=delete;
    Hotel(const Hotel&)=delete;
    Hotel(Hotel&&)=default;
    Hotel& operator=(const Hotel&)=delete;
    Hotel& operator=(Hotel&&)=delete;
    ~Hotel()=default;
    
    Hotel(std::string name,const unsigned int location_code,RoomPointer room,CategoryType category);

    std::string name() const { return _name; }

    unsigned int locationCode() const { return _location_code; }

    RoomPointer room() const { return _room; }

    CategoryType category() const { return _category; }

    friend std::ostream &operator<<(std::ostream &os, const Hotel &rhs);
};

#endif // HOTEL_H
