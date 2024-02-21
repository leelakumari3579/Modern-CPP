#include<iostream>
#include<stack>
#include<list>
#include<string>
#include<queue>
#include<algorithm>
#include<typeinfo>
using namespace std;

//we can vector as parameter like this -->void myfunc(vector<int> &v)

//int main()
//{
    // int arr[]={2,4,5,7,8};
    // // for(int &ele:arr)
    // //     ele=ele+2;
    // for(const auto &ele:arr)
    //     cout<<ele<<endl;

    // vector<int> v={0,1,7,3,2,4,7};
    // for(const auto &ele:v)
    //     cout<<ele<<" ";
    // list<int> l={7,3,2,4,7};
    // for(const auto &ele:l)
    //     cout<<ele<<" ";
//}

class Base
{
    public:
        Base(){};
        Base(const Base &b)
        {
            cout<<"copy constructor"<<endl;
        }
        virtual void display()
        {
            cout<<"base display "<<endl;
        }
};
class Derived:public Base
{
    public:
        Derived(){}
        Derived(const Derived &b):Base(b)
        {
            cout<<"derived copy constructor "<<endl;
        }
        virtual void display()
        {
            cout<<"derived display "<<endl;
        }
};
int main()
{
    vector<Base *> v;
    v.push_back(new Base());
    v.push_back(new Base());
    v.push_back(new Derived());
    v.push_back(new Derived());
    for(Base *ele:v)
        ele->display();
}