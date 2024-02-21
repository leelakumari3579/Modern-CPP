#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
using namespace std;
auto mymax(auto a,auto b) //gives warning -->only works in (-fconcepts) platform/compiler
{
    return a>b?a:b;
}
int main()
{
    // register int r=3;
    // cout<<&r;

    // auto x=5;
    // auto y=5.5;
    // cout<<sizeof(x)<<" "<<typeid(x).name()<<endl; 
    // cout<<sizeof(y)<<" "<<typeid(y).name()<<endl; 

    // auto x=5;
    // const auto y=8;
    // auto px=&x;
    // auto py=&y;
    // cout<<"type of px: "<<typeid(px).name()<<endl; 
    // cout<<"type of py: "<<typeid(py).name()<<endl; 

    // auto a=5;
    // const auto x=4;
    // auto y=x; //non constant integer Y
    // auto &z=x; //constant integer Z
    // auto p1=&x; //constant integer pointer P1
    // auto *a2=&x; //constant integer pointer a2
    // const auto p3=&a; //integer pointer to contant P3
    // auto p4=&x; //constant integer pointer P4
    // const auto p5=&x; //constant integer pointer to constant (const int *const p5)

    // vector<int> v={30,20,89};
    // auto it = v.begin();  //vector<int>::iterator it = v.begin();
    // auto it2 = v.cbegin();  //vector<int>::const_iterator it = v.begin();
    // // *it2=43; ->error
    // while(it2!=v.end())
    // {
    //     cout<<*it2<<endl;
    //     it2++;
    // }
    // v.insert(it2,56);
    // it2=v.begin();
    // while(it2!=v.end())
    // {
    //     cout<<*it2<<" ";
    //     it2++;
    // }

    // auto ptr1 = new int; //int *ptr1
    // auto ptr2 = new int[5]; //int *ptr1
    // auto ptr3 = new int[5][4]; //int (*ptr3)[4] -->pointer to array
    // auto ptr4 = new int*[5]; //pointer to pointer
    // int *p[4]; //array of pointers
    // auto ptr5 = p; //int **ptr5 = p; -->pointer to pointer
    // cout<<typeid(ptr2).name()<<endl;
    // cout<<typeid(ptr3).name()<<endl;

    // int a=5;
    // int b=10;
    // cout<<mymax(a,b)<<endl;
    // string s1="sikki";
    // string s2="nidhi";
    // cout<<mymax(s1,s2)<<endl;
    // cout<<mymax(12.5,2.5)<<endl;
    // cout<<mymax(5,10.3)<<endl;
    // cout<<mymax(5,5.8)<<endl;


    return 0;
}