#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
using namespace std;

class employee
{
private:
    int empid;
    string name;
    int salary;
public: 
    employee(int p_empid=0, string p_name="leela", int s=40000)
    {
        cout<<"constructor called "<<endl;
        empid=p_empid;
        name=p_name;
        salary=s;
    }
    employee(const employee &e)
    {
        cout<<"copy constructor called "<<endl;
        empid=e.empid;
        name=e.name;
        salary=e.salary;
    }
    employee &operator=(const employee &e)
    {
        cout<<" = operator is called \n";
        empid=e.empid;
        name=e.name;
        salary=e.salary;
        return *this;
    }
    friend void operator>>(istream &in,employee &e);
    friend ostream &operator<<(ostream &out,const employee &e);
    bool operator<(employee &e1);
    bool operator==(const employee &e);

    int getSalary() const { return salary; }
    void setSalary(int salary_) { salary = salary_; }

    string getName() const { return name; }
    void setName(const string &name_) { name = name_; }
};
void operator>>(istream &in,employee &e)
{
    in>>e.empid>>e.name>>e.salary;
}
ostream &operator<<(ostream &out, const employee &e)
{
    out<<e.empid<<" "<<e.name<<" "<<e.salary;
    return out;
}
bool employee::operator<(employee& e1)
{
    return this->getSalary() < e1.getSalary();
}
bool employee::operator==(const employee& e)
{
    return this->getName()==e.getName();
}

int main()
{
    #if 0
    vector<employee>  v ;
    #else
    list<employee> v;
    #endif
    employee ele;
    for (int i = 0; i < 4; i++)
    {
        cin >> ele;
        v.push_back(ele);
        cout <<"---------------\n";
    }
    cout<<"\n****************\n";
    // v.insert(v.begin(),employee(9,"pichi"));
    // v.push_back(employee(0,"pichi_sikki"));
    auto it=v.begin();
    employee e=employee(10,"janaki",90);
    v.insert(it,e);
}