#include<iostream>

    enum class COLOR {RED, BLUE};
    enum class RANK {FIRST, SECOND};
    enum class GEAR {FIRST, SECOND};

void magic(int val)
{
    int n1 = val + 10;
}
int main()
{
    COLOR c1 = COLOR::RED;
    GEAR g1 = GEAR::FIRST;
    RANK r1 = RANK::FIRST;

    // don't compare these values
    // if(g1 == r1)
    // {
    //     std::cout<<"OH No!";
    // }
    
    magic((int)r1);
}