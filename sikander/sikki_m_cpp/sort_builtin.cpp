#include<algorithm> 
#include<iostream>
#include<string>
using namespace std;

bool compare(int a, int b)
{
    //cout<<"comaparing "<<a<<" "<<b<<endl;
    return a>b;
}
int main()
{
    int arr[]={12,21,34,54,34,23,4};
    int n=sizeof(arr)/sizeof(int);

    //descending order......
    sort(begin(arr),end(arr), compare);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;


    //ascending order.......
    // sort(begin(arr),end(arr));
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
}