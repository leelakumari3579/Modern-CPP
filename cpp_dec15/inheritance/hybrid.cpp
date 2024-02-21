#include<iostream>

class A
{
    int arr[20];
      public:
        void print()
        {
             std::cout<<"in A "<<std::endl;
        }
};

class B :virtual public A{
     public:
        void print()
        {
            std::cout<<"in B "<<std::endl;
        }

};
class C :virtual public A{


};

class D :public B,public C{


};
int main()
{
    D d1;
    std::cout<<sizeof(d1)<<std::endl;
   
}