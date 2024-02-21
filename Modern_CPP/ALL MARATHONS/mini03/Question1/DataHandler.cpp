#include "DataHandler.h"

DataHandler::DataHandler(container data)
:_data(data)
{
}

void DataHandler::FilterData(pred &fn)
{   
    if(_data.empty()){
        throw EmptyContainer("No elements in the container");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"Filter data based on predicate" <<std::endl;
    std::for_each(_data.begin(),_data.end(),[&](const int& val){
        if(fn(val)){
            std::cout<<val<<" ";
        }
    });
    std::cout<<"\n";
}

void DataHandler::FindNthValue(int pos)
{
    if(pos>=5){
        throw IndexOutBoundExec("Index out of Bounds");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"The value at pos "<<pos<<" is "<<_data[pos]<<std::endl;
}

void DataHandler::SumOfOdd()
{
    int  ans=std::accumulate(_data.begin(),_data.end(),0.0f,[](float total,const int& val){
        if(val%2==0) return total;
        return total+val;
    });
    if(ans==0){
        throw NoOddExec("No odd Numbers are present");
    }else{
        std::lock_guard<std::mutex> lg(mt);
        std::cout<< "The sum of odd :"<<ans<<std::endl;
    }
}

void DataHandler::operator+(const DataHandler &obj)
{   
    int sum=0;
    sum+=std::accumulate(_data.begin(),_data.end(),0.0f,[](float total,const int& val){
        return total+val;
    });
    sum+=std::accumulate(obj._data.begin(),obj._data.end(),0.0f,[](float total,const int& val){
        return total+val;
    });
    std::lock_guard<std::mutex> lg(mt);
    std::cout<< "The Total sum of Both Arrays is "<<sum<<std::endl;
}

std::ostream &operator<<(std::ostream &os, const DataHandler &rhs) {
    os << "_data: \n";
    for(int i=0;i<5;i++){
        os<<rhs._data[i]<<" ";
    }
    os<<"\n";
    return os;
}

