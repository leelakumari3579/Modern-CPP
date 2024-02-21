
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int ele;
    auto it=upper_bound(v.begin(),v.end(),ele);
    for(int i=0;i<5;i++){
        cin>> ele;
        it=upper_bound(v.begin(),v.end(),ele);
        v.insert(it,ele);   
    }
    for(int ele : v){
        cout << ele << " ";
    }
    return 0;
}