/*
vector : ArrayList , list
Arrays: fixed size
vector: resizeable array

Containers : data structures which hold a group of elements

Sequence Containers: vector, list(DLL), forward_list , deque(DEQ)

Asscoiative Containers : set , multiset , map , multimap(BST), unordered_set(Hash)

COntainer Adapters : stack , queue , priority_queue


*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> v={1,2,3,4,5};
    cout<< "sizeof(v) :"<< sizeof(v) << endl;
    cout<< "v.size() :"<< v.size() << endl;
    v.push_back(3);
    for(int ele: v){
        cout<< ele << " " ;
    }
    cout<<"\n";
    v.insert(v.begin()+3,3000);
    for(int ele: v){
        cout<< ele << " " ;
    }
    cout<<"\n";
     v.erase(v.begin()+3);
     for(int ele: v){
        cout<< ele << " " ;
    }
    cout<<"\n";

    vector<int>::iterator it;
    it=v.begin();
    while(it!=v.end()){
        cout<< *it++ << " ";
    }
    cout<<"\n";
    auto ita=v.begin();
    while(ita!=v.end()){
        cout<< *ita++ << " ";
    }
    cout<<"\n";
    v.insert(it,123);
    v.insert(it,1234);
   // it=v.begin();
     while(it!=v.end()){
        cout<< *it++ << " ";
    }
    cout<<"\n";
    for(int ele: v){
        cout<< ele << " " ;
    }
    return 0;
}