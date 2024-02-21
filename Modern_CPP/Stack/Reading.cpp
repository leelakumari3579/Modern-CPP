#include "Reading.h"
Reading::Reading(ReadingType readingType, float readingValue)
:_readingType(readingType),_readingValue(readingValue)
{
}
bool Reading::operator<(const Reading &other) const
{
    return _readingValue < other._readingValue;
}
std::ostream &operator<<(std::ostream &os, const Reading &rhs) {
    os << "_readingType: " << static_cast<int>(rhs._readingType)
       << " _readingValue: " << rhs._readingValue;
    return os;
}
