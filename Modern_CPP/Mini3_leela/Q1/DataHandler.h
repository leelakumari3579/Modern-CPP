#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <array>
#include <functional>
#include <iostream>


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
    void FilterData(const std::function<bool(int&)>& fn);
    int FindNthValue(int n);
    int SumOfOdd();

    friend std::ostream &operator<<(std::ostream &os, const DataHandler &rhs);
    int operator+(DataHandler &dh);

    ArrayData data() const { return _data; }

};



#endif // DATAHANDLER_H
