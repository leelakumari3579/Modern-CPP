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

void Display(std::unique_ptr<DataModel>& ptr){}

int main()
{
    int n1 = 10;
    std::string name = "lee";
    std::string grade = "A";
    /*
        on heap we have acquired memory for one DataModel object
        its pointer(address) is now owned by unique_ptr.
        ptr is owner of memory. ptr goes out of scope, memory gets freed
    */

    std::unique_ptr<DataModel> ptr = std::make_unique<DataModel>(
        10,name,grade,std::vector<int>{10,20,30});

    
}