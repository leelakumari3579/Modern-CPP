#ifndef DATAHANDLER_HPP
#define DATAHANDLER_HPP

#include<array>
#include <iostream>
#include<functional>

class DataHandler
{
private:
    std::array<int,5> _data;
public:
    DataHandler()=delete;
    DataHandler(const DataHandler&)=delete;
    DataHandler(DataHandler&&)=delete;
    DataHandler& operator=(const DataHandler&)=delete;
    DataHandler& operator=(DataHandler&&)=delete;
    ~DataHandler()=default;

    DataHandler(std::array<int,5> data);

    std::array<int,5> data() const { return _data; }

    friend std::ostream &operator<<(std::ostream &os, const DataHandler &rhs);
    void FilterData(const std::function<bool(int&)>& fn);
    int FindNthValue(int N);
    std::optional<int> SumOfOdd(const std::function<bool(int&)> &fn);
    int operator+(DataHandler& rhs);
};



#endif // DATAHANDLER_HPP
