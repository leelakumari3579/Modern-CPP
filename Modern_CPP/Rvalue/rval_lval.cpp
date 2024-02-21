#include<iostream>
#include<vector>
#include<thread>

//f1 takes one integer by value and returns an integer by value 
int f1(const int n1){}
//f2 takes a lvalue reference to an integer and returns an integer by value
int f2(int& n1){}

int f1(std::vector<int>& n1){}

//Demo takes a rvalue reference to standard vector of integers and return integre by value
int Demo(std::vector<int>&& n1){
    //operation on a vector of integer passed!
}
int Demo(std::string&& s1){
    //s1 = "nani";
}

int main()
{
    int n1=10;
    /*
    10 is rvalue in main function. it will be ASSIGNED to n1 variable in f1 scope
    which means 10 will get a fixed location in RAM inside the call stack of f1
    */
    f1(10); //rvalue
    /*
    n1 is a lvalue stored in 4bytes of memory in main function. these 4 bytes of data will
    be copied into the scope of f1 and a new variable "n1" local to f1 will be created 
    this is copy semantics NOT ASSIGNMENT.
    */
    f1(n1);
    f1(n1);
    
    std::vector<int> v1 {10,20,30};
    Demo(std::move(v1));
    //do not access v1 in main!~

    std::string s1 = "leela";
    std::cout<<s1<<"\n";
    Demo(std::move(s1));

    //std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout<<s1<<"\n"; //illegal! i can get any output!
}
/*
only lvalue accepted by reference:
    e.g: Magic(int& n1)

only rvalue accepted by assignment:
    e.g: Magic(int&& n1)

both accepted
    a) lvalues accepted by copy, rvalues must be assigned
        e.g: Magic(int n1)
    b) lvalues by reference, rvalues must be assigned
        e.g: Magic(const int& n1)
*/