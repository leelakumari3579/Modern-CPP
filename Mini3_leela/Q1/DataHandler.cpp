#include "DataHandler.h"


std::ostream &operator<<(std::ostream &os, const DataHandler &rhs) {
    os << "_data: " << rhs._data;
    return os;
}

DataHandler::DataHandler(ArrayData data)
    :_data(data)
{
}

std::function<int(std::array<int,5>)> DataHandler::FilterData(std::function<int(std::array<int,5>)> fn)
{
    if(_data.empty())
        throw EmptyDataException("Data Not Found!!");

    //std::array<int, 5> result;
    // auto lambdaFn =([](int num) ->int{
    //        return num%3 == 0;
    //    },_data);
    // for(int i = 0; i < 5; i++)
    //     result.fill(_data[i]);
    return fn;    

    if(fn == 0)
        throw NoMatchingInstanceException("There is no matching data!!");
    
    //return fn(result);
}

int DataHandler::FindNthValue(int n)
{
    int NthValue = 0;
    if(_data.empty())
        throw EmptyDataException("Data Not Found!!");

    int count = 0;
    for(int i = 0; i < 5; i++)
    {
        if(count == n)
        {
            NthValue = _data[i];
            break;
        }
        count++;
    }

    if(NthValue == 0)
        throw NvalueNotFoundException("N value not found or there is no data in given position!");
    
    return NthValue;
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

DataHandler DataHandler::operator+(DataHandler &dh)
{
    DataHandler sumobj;
    for(int i = 0; i < 5; i++)
        sumobj._data[i] = this->_data[i] + dh._data[i];
    return sumobj;
}

