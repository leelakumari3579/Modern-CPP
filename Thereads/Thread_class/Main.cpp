#include "ThreadOperation.h"

int main()
{
    ThreadOperation obj1(10);
    std::thread th1(&ThreadOperation::Square, &obj1);
    std::thread th2(&ThreadOperation::Cube, &obj1);

    if(th1.joinable())
    {
        th1.join();
    }

    if(th2.joinable())
    {
        th2.join();
    }
}