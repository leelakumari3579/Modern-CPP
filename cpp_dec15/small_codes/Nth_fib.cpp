#include<iostream>
int fib(int n)
{
    int n1=0,n2=1,res;
    if(n==0)
        return n1;
    //else
    //{
        for(int i=2;i<=n;i++)
        {
            res=n1+n2;
            n1=n2;
            n2=res;
        }
        return res;
    //}
}
int main()
{
    int n=0;
    std::cout<<fib(n);
}