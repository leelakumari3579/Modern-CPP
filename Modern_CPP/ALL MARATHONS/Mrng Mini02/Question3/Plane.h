#ifndef PLANE_H
#define PLANE_H
#include<string>
#include <ostream>
#include"PlaneType.h"

class Plane
{
private:

    std::string _id;
    PlaneType _type;
    int _capacity;

public:

    Plane(std::string id,PlaneType type,int capacity);

    Plane() =delete;
    Plane(const Plane&)=default;
    Plane(Plane&&)=default;
    Plane& operator=(const Plane&)=default;
    Plane& operator=(Plane&&)=default;
    ~Plane()=default;

    std::string id() const { return _id; }

    PlaneType type() const { return _type; }
    void setType(const PlaneType &type) { _type = type; }

    int capacity() const { return _capacity; }
    void setCapacity(int capacity) { _capacity = capacity; }

    friend std::ostream &operator<<(std::ostream &os, const Plane &rhs);


};

#endif // PLANE_H
