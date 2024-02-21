#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {1,2,3,4,5};
    auto it1=v.begin();
    auto it2=v.cbegin();
    while(it1!=v.end()){
        cout << *it1<< " ";
        ++it1;
    }
    cout<< "\n";
    while(it2!=v.end()){
        cout << *it2 << " ";
        ++it2;
    }
    cout<< "\n";

    return 0;
}