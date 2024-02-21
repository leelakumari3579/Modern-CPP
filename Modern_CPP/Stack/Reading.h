#ifndef READING_H
#define READING_H
#include"ReadingType.h"
#include <ostream>
class Reading
{
private:
   ReadingType _readingType;
   float _readingValue;
public:
    Reading()=delete;
    Reading(const Reading&)=delete;
    Reading(Reading&&)=default;
    Reading &operator=(const Reading&)=delete;
    Reading &operator=(Reading&&)=delete;
    ~Reading() =default;
    
    Reading(ReadingType readingType,float readingValue);

    bool operator<(const Reading &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Reading &rhs);
    
    
};

#endif // READING_H
