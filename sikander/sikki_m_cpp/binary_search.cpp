#include<algorithm> 
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int arr[]={12,21,23,34,34,54};
    
    bool res = binary_search(begin(arr), end(arr), 34); //binary search only use if the list is sorted.
    //if list is not sorted use lenear search.

    cout<<"res "<<res<<endl;
    if(res==false)
        cout<<"element not found \n";
    else
        cout<<"found "<<endl;
}