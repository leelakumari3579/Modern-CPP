#include "ThreadOperation.h"
#include "Functionalities.h"

int main()
{
    ThreadOperation obj1(10);
    std::thread th1(&ThreadOperation::Square, &obj1);
    std::thread th2(&ThreadOperation::Cube, &obj1);

    if(th1.joinable())
    {
        th1.join();
    }

    obj1.Produce_value_for_cube();

    if(th2.joinable())
    {
        th2.join();
    }

    // ThreadContainer data(10);
    // std::thread th1(Square, data);
    // std::thread th2(Cube, data);

    // if(th1.joinable())
    // {
    //     th1.join();
    // }

    // Producer_value_cube(data);

    // if(th2.joinable())
    // {
    //     th2.join();
    // }

}