#include "player.h"
#include<iostream>
int main(int argc, char const *argv[])
{
    // player p;
    // std::cout<<p;
    int m1[]={2,3,2};
    int m2[]={3,3,3};
    player p1(2,"varma",m1);
    player p2(3,"madhav",m2);
    player p3(4,"madhav",m1);
    // std::cout<<p1;
    // std::cout<<p2;
    std::cout<<(p1==p3)<<std::endl;//false; -->(1)
    p1[0]='k';// -->(2);
    std::cout<<p1.getPname()<<std::endl;
   // std::cout<<p1;
     std::cout<<(p1<p2)<<std::endl;     //checking <; m2 has more so true;
    
    return 0;
}
