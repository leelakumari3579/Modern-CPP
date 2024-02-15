#include<iostream>
#include<vector>
#include<stack>
#include<list>

class Demo{
    private:
        int _id {-1};  //default value  --->inClass initialization
    public:
        Demo() = default;
        Demo(int id):_id{id}{}  // :assigning members  --->MemberList initialization
};

struct abc{
    int id;
    std::string s1;
};

int main()
{
    //std::list<int> l1 {10, 20, 30};
    //for(std::list<int>::iterator itr = l1.begin(); itr != l1.end(); itr++){}
    //for(auto itr = l1.begin(); itr != l1.end(); itr++){}

    //uniform initialization
    
    float f1 {10.21f};

    int arr[] {10,20,30};
    int arr1[4] {1,2,3,4};

    Demo d1 {};
    Demo d2 {10};
    struct abc x {101,"leela"};
    
    int n1=90;
    int* p_n1 {&n1};

    Demo* d1 {new Demo(101)};

    std::list<int> l1 {10,20};

    return 0;
}