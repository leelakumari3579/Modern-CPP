#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include<vector>
using namespace std;
void display(vector<string> namesv)
{
    for (string s : namesv)
    {
        cout << s << " --> ";
    }
    cout << "\n";
}
void display(list<string> names)
{
    for (string s : names)
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
    display(names);
    names.pop_front();
    names.pop_back();
    display(names);

    list<string>::iterator it = max_element(begin(names), end(names));
    cout << "Max Name : " << *it << endl;
    names.sort();
    display(names);

    cout << "\n";
    return 0;
}