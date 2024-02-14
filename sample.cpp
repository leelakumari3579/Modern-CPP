#include <iostream>

class sample
{
private:
    int id;
public:
    sample() = default;
    sample(int i):id(i){}
    virtual ~sample()
    {std::cout<<"destructor";}
    void Display(){std::cout<<"display";}
};
void magic(sample& obj){obj.Display();}

int main()
{
    sample* obj = new sample[3];
    magic(*obj);
    delete obj;
}
