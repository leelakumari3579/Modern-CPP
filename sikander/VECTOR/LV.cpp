/* 
iterator vector : pointer+int  , pointer-int , pointer-pointer , pointer++ , pointer--
                    > , < , <= , >= , == , != 
iterator list : pointer++  ,  pointer-- 
                == , !=

*/
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include<vector>
using namespace std;
template <class T>
void display(T names)
{
    for (auto s : names)
    {
        cout << s << " --> ";
    }
    cout << "\n";
}

int main()
{
    list<string> names;
    names.push_back("uma");
    names.push_front("mahi");
    names.push_back("manu");
    names.push_back("gowtu");
    names.push_back("uma2");
    vector<string> namesv;
    namesv.push_back("uma");
    namesv.push_back("manu");
    namesv.push_back("gowtu");
    namesv.push_back("uma2");
    auto it_v=begin(namesv);
    auto it_l=begin(names);
    namesv.push_back("anu");
    names.push_back("anu");
    // cout << "it_v" << *it_v << endl;
     cout << "it_l" << *it_l << endl;
    cout << "\n";
    display(names);
    display(namesv);
    cout << "\n";
    return 0;
}