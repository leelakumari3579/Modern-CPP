#include<vector> 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    // vector<int> v2;
    // int ele=12;
    // auto it4=upper_bound(begin(v2),end(v2),ele);
    // v.insert(it4,ele);  

    vector<int> v;
    int n;
    cout<<"enter no of elements to the vector: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;

        v.push_back(ele);
        
        // auto it=upper_bound(begin(v),end(v),ele);
        // v.insert(it,ele);
        
        //cin>>v[i];
    }
    int key;
    cout<<"enter the element to delete ";
    cin>>key;
    auto it = find(v.begin(),v.end(),key);
    if(it==v.end())
        cout<<"element not found \n";
    else
    {
        // v.pop_back();
    }
    for(int ele:v)
        cout<<ele<<" ";
    return 0;
}