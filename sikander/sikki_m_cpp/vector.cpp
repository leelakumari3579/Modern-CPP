#include<vector> 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
Containers: Data structures which hold a group of elements
Sequence Containers: vector, list(doubly linked list), forward_list, deque(Double Ended Queue)
Associative Containers: set, multiset, map, multimap(BST), unordered_set(Hash)
Container Adapters: stack, queue, priority_queue
*/

int main()
{
    vector<int> v; //v={12,34,53,90};
    //cout<<sizeof(v)<<endl; //using sizeof(v) will give default vector size
    cout<<v.size()<<endl; //using v.size() will give no of elements in vector
    v.push_back(39);
    v.push_back(90);
    v.push_back(78);
    v.push_back(40);
    v.push_back(34);

    cout<<v.size()<<" ";  //4
    cout<<v.capacity()<<endl; //4

    for(int ele:v)
        cout<<ele<<endl;

    v.pop_back();  //34
    v.pop_back();  //40

    cout<<v.size()<<" ";   //2
    cout<<v.capacity()<<endl; //4

    cout<<"accessing elemets through vector"<<endl;
    vector<int>::iterator it;
    it=v.begin();
    cout<<*it<<"*"<<endl;//39
    it++;
    cout<<*it<<"*"<<endl;//90
    it++;
    cout<<*it<<"*"<<endl;//78
    it++;
    cout<<*it<<"*"<<endl;//40
    it++;
    cout<<*it<<"*"<<endl;//34

    for(it=begin(v);it<end(v);it++)
        cout<<*it<<" ";
    
    auto it2=v.begin();
    v.insert(it2, 123); //add a new element in starting position

    auto it3=v.end();
    v.insert(it3, 234); //add a new elemet in end

    v.insert(v.begin()+2,000); //add element at 2nd place.
    v.insert(v.end()-2,000); //add element at 2nd from last position.
    
    //how will i get mid element

    cout<<"\nusing AUTO: ";
    for(auto ele:v)  //auto will helps to take data type automatically (but compilation will be slow)
        cout<<ele<<" ";

    // vector<int> v2;
    // int ele=12;
    // auto it4=upper_bound(begin(v2),end(v2),ele);
    // v.insert(it4,ele);    
}