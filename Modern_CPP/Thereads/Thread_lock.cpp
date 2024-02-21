#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

/*
    amount = x
    100 times i will withdraw 10 rupees
    100 time i will deposit 10 rupees
*/

int amount = 100;
std::mutex mt;
void Withdraw()
{
    for(int i=0; i<100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        mt.lock();
        amount = amount - 10;
        mt.unlock();
    }
}

void Deposit()
{
    for(int i=0; i<100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        mt.lock();
        amount = amount + 10;
        mt.unlock();
    }
}

int main()
{
    std::thread t1(Withdraw);
    std::thread t2(Deposit);

    t1.join();
    t2.join();

    std::cout<<"Final Amount is "<<amount<<std::endl;
}


//g++ Thread.cpp -lpthread -g -o app
//for((i =0;i<50;i++)); do ./app; done     --->run the program 50 times in terminal using bash