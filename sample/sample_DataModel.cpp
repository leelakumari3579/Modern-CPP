#include <iostream>

class DataModel
{
private:
    int _id {-1};
    float _value {0.0f};
public:
    DataModel() = default;
    ~DataModel() = default;
    DataModel(const DataModel&) = default;
    DataModel& operator=(const DataModel&) = default;
    DataModel& operator=(DataModel&&) = default;
    DataModel(DataModel&&) = default;

    int id() const {return _id;}
    float value() const {return _value;}
    DataModel(int id, float value):_id(id), _value(value){}
};
 
void Magic(DataModel obj)
{
    std::cout<<"magic triggered!\nExpecto Petronas!";
}
int main()
{
   //DataModel d1(101, 78.9f); 
   DataModel *d1 = new DataModel(101, 78.9f);
   Magic(*d1); //d1 is pointer [0x879H]
   delete d1;
}
/*
    Main Call Stack
    [101   |  78.9]
    0x145H |  0x14cH
    -----------------
    parametarized constructor call stack
    
    rule of zero
    rule of three
    rule of five
    */