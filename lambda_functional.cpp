#include <iostream>
#include <vector>
#include <functional>

// void manager(int (*fn)(int), std::vector<int> &data)
void manager(std::function<int(int)> fn, std::vector<int> &data) // function wrapper -->provides type eraser
{
    for (int val : data)
    {
        std::cout << fn(val);
    }
}

// int square(int num)
// {
//     return num * num;
// }

// int cube(int num)
// {
//     return num * num * num;
// }

void magic()
{
    // manager(cube, data);
    /*
    //lvalue lambda function with name of object as f1
    //this lambda is of signature
       -input of 1 integer by value
       -return of 1 integer by value
    */
    std::function<int(int)> f1 = [](int num) -> int
                                { return num * num * num; };

    // execute f1 directly like a function without passing
    std::cout << f1(10);
}

int main()
{
    std::vector<int> data{2, 23, 45, 23};

    magic();

    // manager(square, data);
    manager([](int num) -> int
            { return num * num; },
            data);

    // int(*ptr)(int) = square;
    // square(10);
    // cube(10);
}

// class lambda
// {
//     private:

//     public:
//         int operator()(int num)
//         {
//             return num * num;
//         }
// };

// lambda obj(10);

// objdump -Cd ./app | less ---->assembly code / instructions