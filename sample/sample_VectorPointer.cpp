#include <iostream>
#include <functional>
#include <vector>

class Demo
{
    int _id;

public:
    explicit Demo(int id) : _id(id) {}
    ~Demo() = default;

    int id() const { return _id; }
};

/*
    objective: gather all values created in a main and "put them in a container"
    give access to the values to a function called operation
*/

void Magic(std::vector<int *> &data)
{
    for (int *ptr : data)
        std::cout << *ptr;
}

void Magic(std::vector<std::reference_wrapper<int>> &data)
{
    for (int ptr : data)
        std::cout << ptr;
}

int main()
{
    // int n1 = 10;
    // int n2 = 20;

    Demo n1(10);
    Demo n2(20);

    // option1: store them in a container!!!
    // std::vector<int> data {n1, n2};
    std::vector<Demo> data{n1, n2};

    // option2: put pointers to data values in the container
    // std::vector<int*> data2 {&n1, &n2};
    std::vector<Demo *> data2{&n1, &n2};

    // option3: put reference wrapper in the container
    // std::vector<std::reference_wrapper<int>> data3 {n1, n2};
    std::vector<std::reference_wrapper<Demo>> data3{n1, n2};

    
}