#include<iostream>
// //int p=50;
// class a{
//     int p=20;
//     public:
//         // a()
//         // {
//         //     p=30;
//         // }
//         // a(int p1)
//         // {
//         //     p=p1;
//         // }
//         void show()
//         {
//             std::cout<<p;
//         }
//         friend void operator<<(std::ostream &os,a &a1)
//         {
//             os<<a1.p;
//         }
//         friend void operator>>(std::istream &is,a &b1)
//         {
//             std::cout<<"enter object value: "<<std::endl;
//             is>>b1.p;
//         }
//         a operator ++()
//         {

//         }
// };
// int main()
// {
//     a a1;
//     // a1.show();    
//     std::cout<<" is a1 "<<a1;
//     std::cin>>a1;
//     a b1;
//     std::cin>>b1;
//     std::cout<<" is b1 "<<b1;
//     // a res=a1+b1;

// }
class GP
{
protected:
int y=20;
public:

};
class A:public GP
{
    protected:
        int x=10;
public:
void display()
{
    std::cout<<"parent \n";
}
};
class B:public A
{
public:
void display()
{
    std::cout<<y<<"\t derived \n";
}
};
int main()
{
    B b1;
    b1.display();
    A *a1=new B;
    a1->display();
}