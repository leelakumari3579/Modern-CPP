#include<algorithm> 
#include<iostream>
#include<string>
using namespace std;

bool isOdd(int a)
{
    bool res = a%2!=0;
    //cout<<"isOdd("<<a<<")"<<res<<endl;
    return res;
    //return a%2!=0;
}
bool isPrime(int a)
{
    if(a==0||a==1)
        return false;
    for(int i=2;i<a;i++)
        if(a%i==0)
            return false;
    return true;
}
int main()
{
    int arr[]={12,0,3,21,2,1,23,34,13,34,34,7,27,54};

    int totalOdd = count_if(begin(arr), end(arr), isOdd);  
    cout<<"number of odd elements "<<totalOdd<<endl;
    int totalPrime = count_if(begin(arr), end(arr), isPrime);  
    cout<<"number of Prime elements "<<totalPrime<<endl;

    int *FirstPrime = find_if(begin(arr), end(arr), isPrime);  
    cout<<"First prime number "<<*FirstPrime<<endl;
    //find_if ->first accurance of a number. eg:- first prime number in an array (gives 3).
}