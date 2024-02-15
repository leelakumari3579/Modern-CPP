#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <array>
#include <functional>
#include <ostream>
#include <algorithm>
#include "EmptyDataExcception.h"
#include "NoMatchingInstanceException.h"
#include "NvalueNotFoundException.h"

using ArrayData = std::array<int, 5>;

class DataHandler
{
private:
    ArrayData _data;
public:
    DataHandler() = default;
    DataHandler(const DataHandler &) = default;
    DataHandler &operator=(const DataHandler &) = delete;
    DataHandler &operator=(DataHandler &&) = delete;
    DataHandler(DataHandler &&) = default;
    ~DataHandler() = default;

    DataHandler(ArrayData data);
    std::function<int(std::array<int,5>)> FilterData(std::function<int(std::array<int,5>)> fn);
    int FindNthValue(int n);
    int SumOfOdd();

    friend std::ostream &operator<<(std::ostream &os, const DataHandler &rhs);
    DataHandler operator+(DataHandler &dh);

    ArrayData data() const { return _data; }

};



#endif // DATAHANDLER_H
