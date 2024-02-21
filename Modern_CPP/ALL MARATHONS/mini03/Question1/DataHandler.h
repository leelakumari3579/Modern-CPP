#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include<iostream>
#include<array>
#include<functional>
#include<algorithm>
#include<numeric>
#include"IndexOutBoundExec.h"
#include"EmptyContainer.h"
#include"NoOddExec.h"
#include<thread>
#include<mutex>
using pred=std::function<bool(int num)>;
using container=std::array<int,5>;
class DataHandler{
    private:
        container _data;
        std::mutex mt;
    public:
        DataHandler()=delete;
        DataHandler(const DataHandler&)=delete;
        DataHandler(DataHandler&&)=delete;
        DataHandler& operator=(const DataHandler&)=delete;
        DataHandler& operator=(DataHandler&&)=delete;
        ~DataHandler()=default;

        DataHandler(container data);

        // mem funcs:
        void FilterData(pred& fn);

        void FindNthValue(int pos);

        void SumOfOdd();

        void operator +(const DataHandler& obj);

        friend std::ostream &operator<<(std::ostream &os, const DataHandler &rhs);

};

#endif // DATAHANDLER_H
