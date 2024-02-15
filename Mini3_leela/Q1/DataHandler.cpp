#include "DataHandler.h"
#include "EmptyDataExcception.h"
#include "NoMatchingInstanceException.h"
#include "NvalueNotFoundException.h"

std::ostream &operator<<(std::ostream &os, const DataHandler &rhs) {
    os << "_data: " << rhs._data;
    return os;
}

DataHandler::DataHandler(ArrayData data)
    :_data(data)
{
}

void DataHandler::FilterData(const std::function<bool(int&)>& fn)
{
    if(_data.empty())
        throw EmptyDataException("Data Not Found!!");

    //std::array<int, 5> result;
    // auto lambdaFn =([](int num) ->int{
    //        return num%3 == 0;
    //    },_data);
    for( int& val : _data)
    {
        if(fn(val))
        {
            std::cout<<"Odd Number="<<val<<"\n";
        }
    }
    if(fn == 0)
        throw NoMatchingInstanceException("There is no matching data!!");
    
    //return fn(result);
}

int DataHandler::FindNthValue(int n)
{
    if(_data.empty())
        throw EmptyDataException("Data Not Found!!");

    // int NthValue = 0;
    // int count = 0;
    // for(int i = 0; i < 5; i++)
    // {
    //     if(count == n)
    //     {
    //         NthValue = _data[i];
    //         break;
    //     }
    //     count++;
    // }

    // if(NthValue == 0)
    //     throw NvalueNotFoundException("N value not found or there is no data in given position!");
    
    // return NthValue;
    if(_data.size() < n || n < 0)
        throw NvalueNotFoundException("Invalid value!!");
    
    return _data[n];
}

int DataHandler::SumOfOdd()
{
    if(_data.empty())
        throw EmptyDataException("Data Not Found!!");
        
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        if(_data[i] % 2 != 0)
        {
            sum += _data[i];
        }
    }

    if(sum == 0)
        throw NoMatchingInstanceException("There is no matching data!!");

    return sum;
}

// int DataHandler::operator+(DataHandler &dh)
// {
//     int sumobj;
//     for(int i = 0; i < 5; i++)
//         sumobj = this->_data[i] + dh._data[i];
//     return sumobj;
// }

int DataHandler::operator+(DataHandler &rhs)
{
    if(_data.empty())
    {
        throw EmptyDataException("Data is Empty!!");
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