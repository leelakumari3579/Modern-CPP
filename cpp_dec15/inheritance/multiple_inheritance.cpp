#include<iostream>

class A
{
    public:
        void print()
        {
            std::cout<<"in A "<<std::endl;
        }
};

class B {
    public:
        void print()
        {
            std::cout<<"in B "<<std::endl;
        }

};
class C :public A,public B
{

};

int main()
{
    C c1;
    c1.A::print();
    // c1.print();  //it will call [C::print()] so, it will give error ambiguous
    c1.B::print();
   
}