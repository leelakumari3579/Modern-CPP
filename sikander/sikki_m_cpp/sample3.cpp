#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<typeinfo>
using namespace std;
template<class T>
//T mymax(T &a,T &b) //it will not work if values pass directly without assigning to another variable
T mymax(T a,T b)
{
    cout<<"my max of "<<typeid(T).name()<<endl;
    return a>b?a:b;
}
int main()
{
    cout<<mymax(5,10)<<endl;//cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    cout<<mymax(15.9,10.0)<<endl;
    // cout<<mymax(5.9,10)<<endl; //will not work for two different types
}