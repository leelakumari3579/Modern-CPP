#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push(Reading(ReadingType::TEMPERATURE,32.1f));
    data.push(Reading(ReadingType::TEMPERATURE,35.1f));
    data.push(Reading(ReadingType::TYRE_PRESSURE,36.1f));
    data.push(Reading(ReadingType::RPM,3000.1f));
}
/*
Worst case time complexity
1)pushing one element on a stack:O(1)
2)pop element from top of a stack:O(1)
3)peek element from top of a stack:O(1)



*/