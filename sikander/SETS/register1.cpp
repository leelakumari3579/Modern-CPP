/*
dynamic cast 
static cast
*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    auto x=4;
    register int a=19;
    cout<< "register  a : " << a <<  "Address : " << &a <<endl;
    cout << "auto x : " << x << endl;

    auto a=5;
    

    return 0;
}