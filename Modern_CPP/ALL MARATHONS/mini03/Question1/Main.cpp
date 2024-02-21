#include "DataHandler.h"
#include<future>
int main(int argc, char const *argv[])
{   
    container data1{1,2,3,4,5};
    container data2{6,7,8,9,10};
    //1.) creation of two objects
    DataHandler obj1(data1);
    DataHandler obj2(data2);
   
    // create of predicate;
    pred Predicate =[](int num){ return num%5==0;};

    pred Predicate1 =[](int num){ return num%3==0;};
    // mapping to 1st object;
    try
    {

    std::future<void> FilterData=std::async(std::launch::async,&DataHandler::FilterData,&obj1,std::ref(Predicate));
    std::future<void> NthVale=std::async(std::launch::async,&DataHandler::FindNthValue,&obj1,3);
    std::future<void> SumOdd=std::async(std::launch::async,&DataHandler::SumOfOdd,&obj1);

    std::future<void> FilterData1=std::async(std::launch::async,&DataHandler::FilterData,&obj2,std::ref(Predicate1));
    std::future<void> NthVale1=std::async(std::launch::async,&DataHandler::FindNthValue,&obj2,3);
    std::future<void> SumOdd1=std::async(std::launch::async,&DataHandler::SumOfOdd,&obj2);

    FilterData.get();NthVale.get();SumOdd.get();
    FilterData1.get();NthVale1.get();SumOdd1.get();
    }
    catch(EmptyContainer& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(IndexOutBoundExec& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(NoOddExec& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   //Last function:
   std::cout<< "The last Operator + using thread"<<std::endl;
    auto ObjectOperation = [&](){obj1+obj2;};
    std::future<void> ft=std::async(std::launch::async,ObjectOperation);

    return 0;
}
