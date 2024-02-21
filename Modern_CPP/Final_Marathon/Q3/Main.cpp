// #include "Functionalities.h"

#include "ThreadHandler.h"
#include <thread>


int main()
{
    ThreadHandler data;
    std::vector<int> arr;
    std::thread th(&ThreadHandler::Operation, &data);

    data.InputCapture(arr);

    if (th.joinable())
        th.join();
}