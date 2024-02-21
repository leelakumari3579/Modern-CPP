#include"DataHandler.hpp"
#include"DataEmptyException.hpp"
#include"InvalidNvalueException.hpp"
#include<algorithm>
#include<numeric>

std::ostream &operator<<(std::ostream &os, const DataHandler &rhs) {
    os << "_data: " << rhs._data;
    return os;
}

DataHandler::DataHandler(std::array<int, 5> data):_data(data)
{
}

void DataHandler::FilterData(const std::function<bool(int &)> &fn)
{
    if(_data.empty())
    {
        throw DataEmptyException("Data is Empty!!");
    }
    for(int& val:_data)
    {
        if(fn(val))
        {
            std::cout<<"Odd Number="<<val<<"\n";
        }
    }
}

int DataHandler::FindNthValue(int N)
{
    if(_data.empty())
    {
        throw DataEmptyException("Data is Empty!!");
    }
    if(_data.size()<N || N<0)
    {
        throw InvalidNvalueException("Invalid N value!!");
    }

    return _data[N];
}

std::optional<int> DataHandler::SumOfOdd(const std::function<bool(int&)> &fn)
{
    if(_data.empty())
    {
        throw DataEmptyException("Data is Empty!!");
    }
    int total=0;
    for(int& num:_data)
    {
        if(fn(num))
        {
            total+=num;
        }
    }
    if(total<=0)
    {
        return std::nullopt;
    }
    return total;
}

int DataHandler::operator+(DataHandler &rhs)
{
    if(_data.empty())
    {
        throw DataEmptyException("Data is Empty!!");
    }
    int total=0;
    for(int val:_data)
    {
        total+=val;
    }
    for(int val:rhs._data)
    {
        total+=val;
    }
    return total;
}
