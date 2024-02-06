#include <iostream>
#include <functional>

class Demo
{
    int _id;
    public:
        explicit Demo(int id):_id(id) {}
        ~Demo() = default;

        int id() const { return _id; }
};

int main()
{
    int n1 = 10;
    Demo d1(20);

    std::reference_wrapper<int> ref = n1;
    
    std::cout<<ref<<"\n";
    std::cout<<ref.get()<<"\n";

    std::reference_wrapper<Demo> dref = d1; 
    //std::reference_wrapper<Demo*> dref = d1;
    //std::reference_wrapper<std::shared_ptr<Demo>> dref = d1;

    std::cout<<dref.get().id()<<"\n";
}