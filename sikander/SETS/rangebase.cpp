#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void update(vector<int> arr){
     for(int &ele: arr){
        ele=ele+2;
        cout << ele << " ";
    }
    cout<< "\n";
}
int main(){
    vector<int> arr={1,2,3,4,5};
    update(arr);
    for(int ele: arr){
        cout << ele << " ";
    }
    return 0;
}