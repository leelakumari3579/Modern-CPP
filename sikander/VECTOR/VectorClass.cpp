#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Employee
{
    int id;
    string name;

public:
    Employee() = default;
    Employee(int p_id, string p_name)
    {
        cout << "Constructor\n";
        id = p_id;
        name = p_name;
    }
    Employee (const Employee &emp){
        id=emp.id;
        name=emp.name;
    }
    friend istream &operator>>(istream &in, Employee &emp);
    friend ostream &operator<<(ostream &out, Employee &emp);
    bool operator < (const Employee emp){
        return id<emp.id;
    }
    bool operator == ( int key){
        return id == key;
    }
};
istream & operator>>(istream &in, Employee &emp)
{
    cout << "enter ID : ";
    in >> emp.id;
    cout << "enter Name :";
    in >> emp.name;
    return in;
}
ostream &operator<<(ostream &out, Employee &emp)
{
    out << "ID : " << emp.id << endl;
    out << "Name :" << emp.name << endl;
    return out;
}

int main()
{

    vector<Employee> v;
    Employee ele;
    
    for (int i = 0; i < 3; i++)
    {
        cin >> ele;
        v.push_back(ele);
    }
    // for (Employee ele : v)
    // {
    //     cout << ele;
    // }
    auto ptr=max_element(v.begin(),v.end());
    cout<< " MAX : " << *ptr;
    sort(begin(v),end(v));
     for (Employee ele : v)
    {
        cout << ele;
    }
    auto b=find(begin(v),end(v),12);
    if(b!=end(v)){
        cout << "id present"<< endl;
        cout<< *b;
    }
    else{
        cout << "id not present "<< endl;
    }
    return 0;
}
