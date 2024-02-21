#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={1,3,5,12,7,8,9};
    int key=5;
    auto it= find_if(begin(arr),end(arr),[&](int num){ ++key;return num>key;});
    cout << *it << key;
}