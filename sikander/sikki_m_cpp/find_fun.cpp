#include<algorithm> 
#include<iostream>
#include<string>
using namespace std;

int* myfind(int* start, int* end, int key)
{
    while(start!=end)
    {
        if(*start==key)
            break;
        ++start;
    }
    return start;
}
int main()
{
    int arr[]={12,23,34,34,21,54};
    // int *ptr=find(begin(arr), end(arr), 5);  //builtin function -> if element is not found it gives last address/position
    int *ptr=myfind(begin(arr), end(arr), 5);
    cout<<"base address "<<arr<<endl;
    cout<<"address where element is present "<<ptr<<endl;
    if(ptr==end(arr))
        cout<<"element not found \n";
    else
        cout<<"index "<<ptr-arr<<endl;
}