#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using Container = std::vector<int>;

std::mutex mt; //LOCK!

/*
    my program will excecute in synchronously, in a single process, single thread mode

*/

void Square(Container &number)
{
    for (int val : number)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mt.lock();
        std::cout << "Square of number " << val << " is " << val * val << std::endl;
        mt.unlock();
    }
}

void Cube(Container &number)
{
    for (int val : number)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mt.lock();
        std::cout << "Cubee of number " << val << " is " << val * val * val << std::endl;
        mt.unlock();
    }
}

int main()
{
    std::vector<int> data{10, 20, 30};

    /*
        creates a thread object, assigned a function to the thread, accepts requires by the thread.
        thread  will now run like a mini program
        t1 is now available for scheduling by the OS
    */
    //std::thread t1(Square, data); //always pass by value in threads , not by reference
    std::thread t1(Square, std::ref(data));
    std::thread t2(Cube, std::ref(data)); // if you want to pass data by reference forcefully we use std::ref(data)
    
    t1.join(); // main should wait till "t1" is finished. then go to next line
    t2.join(); // main will wait for "t2" to finish. if it is finished go to next line

    // to Avoid race contions we use Thread Synchronization ----->mutex locks
    
    // Square(data);
    // Cube(data);
}

//g++ Thread.cpp -lpthread -g -o app
//time ./app