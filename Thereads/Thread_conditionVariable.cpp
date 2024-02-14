#include <iostream>
#include <thread>
#include <condition_variable>

/*
    condtion_variable
*/

std::mutex mt;
int amount = 0;
std::condition_variable cv;
bool flag = false; 

void CalulateSqauare()
{
    std::unique_lock<std::mutex> lk(mt);
    cv.wait(lk,[](){return flag;});
    //lk is unclocked. t1 thread goes to sleep
    std::cout<<amount*amount<<"\n";
}

int main()
{
    //step1: CREATE AND SCHEDULE T1
    std::thread t1(CalulateSqauare);
    std::cin>>amount;
    flag = true;
    cv.notify_one();
    t1.join(); //cpp 20: jthread
}
//  ([](parameters)->returnType {body;}, Args)
    // auto fn = [](int n){std::cout<<"Entha???"<<n<<"\n";};
    // std::thread t1(fn,20);
    // std::this_thread::sleep_for(std::chrono::seconds(5));