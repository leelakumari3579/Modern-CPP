#include <iostream>
#include <functional>

void Magic(std::reference_wrapper<int> ref)
{
    std::cout<<ref.get()<<std::endl;
}

void Demo (int& n1){}

int main()
{
    int n1 = 10;
    
    Magic(n1); //implicit
    Magic(std::ref(n1)); //explicit

    Demo(std::reference_wrapper<int>(n1));
}