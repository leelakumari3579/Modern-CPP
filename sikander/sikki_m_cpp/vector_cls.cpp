#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
// //void update(std::vector<int> arr)  //will  not modifies remains same == 2 3 4
// void update(std::vector<int> &arr) //modifies to == 4 6 8
// {
//     for(int &ele:arr)
//         ele=ele*2;
// }
// int main()
// {
//     std::vector<int> arr={2,3,4};
//     for(int &ele:arr)
//         std::cout<<ele<<" ";
//     std::cout<<std::endl;
//     update(arr);
//     for(int &ele:arr)
//         std::cout<<ele<<" ";
// }

class Base
{
    public:
        void print(){std::cout<<"base print \n";}
        virtual void display()
        {
            std::cout<<"base \n";
        }
};
class Derived:public Base
{
    public:
        void print(){std::cout<<"derived print \n";}
        void display()
        {
            std::cout<<"derived \n";
        }
};
 int main()
 {
    Base b;
    Derived d;
   
    // std::vector<Base> v={b,d};
    // for(Base ele:v)
    //     ele.display();  //base //base

    // Base *b=new Base();
    // Derived *d=new Derived();
    // b->print();
    // b->display();
    // d->print();
    // d->display();

    // Base &b=*(new Base());
    // Derived &d=*(new Derived());
    b.print();
    b.display();
    d.print();
    d.display();
 }
   