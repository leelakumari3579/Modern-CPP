#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#include<string>
class employee
{
private:
    int empid;
    string name;
    int salary;
public: 
    employee()=default;
    employee(int p_empid,string p_name,int s)
    {
        cout<<"constructor called"<<endl;
        empid=p_empid;
        name=p_name;
        salary=s;
    }
    friend void operator>>(istream &in,employee &e);
    friend ostream &operator<<(ostream &out,const employee &e);
    bool operator<(employee &e1);//print emp details decreasing order based on salary
    bool operator==(const employee &e); //for checking emp names are equal

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
// bool descending(employee &e1,employee &e2)
// {
//     return e1>e2;
// }

int main()
{
    vector<employee> v;
    for(int i=0;i<3;i++)
    {
        cout<<"enter emp details: ";
        employee ele;
        cin>>ele;
        v.push_back(ele);
    }
    cout<<"displaying emp details: \n";
    for(employee ele:v)
        cout<<ele<<" ";
    cout<<endl;
    
    auto it=max_element(begin(v),end(v));
    cout<<" the employee with heighest salary "<<*it<<endl;

    // sort(begin(v),end(v),descending);
    sort(begin(v),end(v));
    cout<<"records sorted based on salary \n";
    for(const employee ele:v)
        cout<<ele<<endl;
    cout<<endl;

    string name;
    cout<<"enter employee name to search ";
    cin>>name;
    employee key(0,name,0);
    it = find(begin(v),end(v),key);
    if(it==end(v))
        cout<<"record not found "<<endl;
    else    
        cout<<*it<<endl;
    
    auto cnt=count_if(v.begin(),v.end(),[](employee &obj){return obj.getSalary()>2000;});
    cout<<"count of salary greater than 2000: "<<cnt;
}
