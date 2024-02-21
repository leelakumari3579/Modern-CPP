#include <iostream>
#include <vector>
#include <functional>
#include <mutex>
#include <thread>

// cp Thread4.cpp Thread5.cpp   -->coping fine from Thread4.cpp to Thread5.cpp

std::mutex mt;

// fill data in container
void FillData(std::vector<std::vector<int>> &inputs)
{
    inputs.emplace_back(
        std::vector<int>{10, 20, 30});
    inputs.emplace_back(
        std::vector<int>{30, 40, 50});
    inputs.emplace_back(
        std::vector<int>{10, 20, 30});
}

std::function<void(std::vector<int> &data)> MakeLambda()
{
    // diclaration of lambda expression
    auto f1 = [](std::vector<int> &data) -> void
    {
        float total = 0.0f;
        for (int val : data)
        {
            total = total + val;
        }
        std::lock_guard<std::mutex> lg(mt);
        std::cout << "Average is: " << total / data.size() << "\n";
    };
    return f1;
}

void MapThreadsToActions(
    std::vector<std::vector<int>> &inputs,
    std::array<std::thread, 3> &arr,
    std::function<void(std::vector<int> &data)> &fn)
{
    // mapping thread array
    auto itr = inputs.begin();
    for (std::thread &th : arr)
    {
        th = std::thread(fn, std::ref(*itr));
        itr++;
    }
}

void JoinThreads(std::array<std::thread, 3> &arr)
{
    // joining of threads
    for (std::thread &th : arr)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}

int main()
{
    // creating and filling inputs
    std::vector<std::vector<int>> inputs;

    // declaration of thread array
    std::array<std::thread, 3> arr;

    // lambda function
    auto fn = MakeLambda();

    // function calls
    FillData(inputs);

    // mapping of thread array
    MapThreadsToActions(inputs, arr, fn);

    // joining of threads
    JoinThreads(arr);
}