#include <iostream>
#include <vector>
#include <memory>

class DataModel
{
private:
    int _n1;
    std::string& _name;
    const std::string& _grade;
    std::vector<int>_data;
public:
    DataModel() = default;
    ~DataModel() = default;
    DataModel(const DataModel&) = default;
    DataModel& operator=(const DataModel&) = default;
    DataModel& operator=(DataModel&&) = default;
    DataModel(DataModel&&) = default;

    DataModel(int n1, std::string& name,const std::string& grade, std::vector<int>&& data)
        :_n1(n1),_name(name),_grade(grade),_data(data){}

    std::vector<int> data() const {return _data;}

    int n1() const { return _n1; }
    void setN1(int n1) { _n1 = n1; }

    std::string& name() const { return _name; }
    void setName(const std::string& name) { _name = name; }

    const std::string& grade() const { return _grade; }

};


// DataModel, n1, name, grade, std::vector<int>{19,29,39};
// T = DataModel
// Args... is type for all parameters
// args = (n1,name, grade, std::vector<int>{19,20,30});
template <typename T, typename... Args>
T Relay(Args &&...args)
{
    return T(std::forward<Args>(args)...);// DataModel(n1, name, grade, std::vector<int>{10, 20, 30});
}
// main is original source of data
// Relay is the middle man (relaying or forward function)
// constructor is the actual destination function where parameters should---
// ARRIVE AS THEY ARE SENT FROM MAIN WITHOUT ANY CHANGES


int main()
{
    int n1 = 10;
    std::string name = "lee";
    std::string grade = "A";
    // std::vector<int> &&data{10, 20, 30};
    // std::move(data) --->previous data become nullptr and new ptr to data assigned
    // Relay(n1,name,grade,std::move(data));
    // Relay(n1, name, grade, std::vector<int>{10, 20, 30});

    // std::make_shared<int> ;

    DataModel obj = Relay<DataModel>(n1,name,grade,std::vector<int> {10,20,30});
    std::cout<<obj.n1()<<"\n";
    std::cout<<obj.name()<<"\n";
    std::cout<<obj.grade()<<"\n";
    for(int val : obj.data())
    {
        std::cout<<val<<"\n";
    }
}

/*
    RULE1: for regular, no templete functions , T&& simply means Rvalue reference to T
    RULE2: for template of type T, T&& menas forward references
        [NOTE: such a template function should involve type deduction for parameters]
    e.g:- Relay deduces type for incoming parameters n1, grade, data
*/