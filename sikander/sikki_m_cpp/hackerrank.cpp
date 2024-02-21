#include<algorithm> 
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int candles[]={4,4,1,3};
    int *largest=max_element(begin(candles),end(candles));
    cout<<"max candle "<<*largest<<endl;
    int count_largest=count(begin(candles),end(candles),*largest);
    cout<<"count of largest candles "<<count_largest<<endl;
}