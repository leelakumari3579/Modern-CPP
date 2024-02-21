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
        cout << "Copy Constructor \n";
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
istream &operator>>(istream &in, Employee &emp)
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
    for(int i=0;i<3;i++){
        cin >> ele;
        v.push_back(ele);
        cout<<endl;
    }
    
    
    return 0;
}