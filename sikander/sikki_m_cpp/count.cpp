#include<algorithm> 
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int arr[]={12,21,23,34,34,34,54};
    int key=34;
    int n = count(begin(arr), end(arr), key);  
    
    int *ptrlw = lower_bound(begin(arr), end(arr), key); 
    int *ptrup = upper_bound(begin(arr), end(arr), key); 
    cout<<n<<endl;
    cout<<ptrup-ptrlw<<endl;

    // cout<<"base address "<<arr<<endl;
    cout<<"first accurance "<<*ptrlw<<"\t address2 "<<ptrlw<<"\t index "<<ptrlw-arr<<endl;
    cout<<"last accurance "<<*(ptrup-1)<<"\t address1 "<<ptrup-1<<"\t index "<<(ptrup-1)-arr<<endl;
}