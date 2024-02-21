#include<algorithm> 
#include<iostream>
#include<string>

using namespace std;
// int isOdd(int num)
// {
//     return num&2!=0;
// }
int mycount_if(int *start,int* last,bool (*pf)(int))
{
    int c=0;
    while(start!=last)
    {
        if(pf(*start))
            c++;
        ++start;
    }
    return c;
}
int main()
{
    int arr[]={12,0,3,21,2,1,23,34,13,34,34,7,27,54};
    int res=mycount_if(begin(arr),end(arr),[](int num){return num%2!=0;});
    cout<<res;
}