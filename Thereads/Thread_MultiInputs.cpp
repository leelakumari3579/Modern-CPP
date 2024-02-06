#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

std::mutex mt;
int main()
{
    // fill data in container
    std::vector<std::vector<int>> inputs 
    {
        std::vector<int> {10, 20, 30},
        std::vector<int> {10, 20, 30},
        std::vector<int> {10, 20, 30}
    };

    // diclaration of lambda expression
    auto f1 = [](std::vector<int>& data) {
        float total = 0.0f;
        for(int val : data)
        {
            total = total +val;
        }
        mt.lock();
        std::cout<<"Average is: "<<total/data.size()<<"\n";
        mt.unlock();
    };
    std::array<std::thread, 3> arr;

    // mapping thread array 
    auto itr = inputs.begin();
    for(std::thread& th : arr)
    {
        th = std::thread(f1, std::ref(*itr));
        itr++;
    }

    // joining of threads
    for(std::thread& th : arr)
    {
        if(th.joinable())
        {
            th.join();
        }
    }
}