#include <iostream>

inline void add(int a, int b){ std::cout<<a+b<<"\n";}

int main()
{
    //int array3D [3][3][3];//3D array in stack
    add(10,20);
}






// class sample
// {
// private:
//     int id;
// public:
//     sample() = default;
//     sample(int i):id(i){}
//     virtual ~sample()
//     {std::cout<<"destructor";}
//     void Display(){std::cout<<"display";}
// };
// void magic(sample& obj){obj.Display();}

// int main()
// {
//     sample* obj = new sample[3];
//     magic(*obj);
//     delete obj;
// }
