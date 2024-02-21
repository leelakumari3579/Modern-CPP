#include <iostream>
#include <list>

// ref becomes alternate name for n1
// sec_ref is an alternate for n1

int main()
{
    int n1 = 10;
    int &ref = n1;
    int &sec_ref = ref;

    std::cout << sizeof(ref) << "\n";
    std::cout << sizeof(n1) << "\n";
    std::cout << sizeof(sec_ref) << "\n";

    // int& arr[1] {ref}; //-->refrences can't go in array
    int arr[1]{ref};
    std::cout << arr[0] << "\n";

    // std::list<int&> data; //-->error: forming pointer to reference type ‘int&’
    // data.push_back(ref);
}