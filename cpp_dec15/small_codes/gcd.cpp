//Greatest Common Divisor(GCD)  or  heighest common divisor (HCF)
#include<iostream>
#include<math.h>
int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int gcd(int a,int b)
{
    int res=min(a,b);
    while(res!=0){
    if(a%res==0 && b%res==0)
        break;
    res--;
    }
    return res;
}
int main()
{
    int a=54,b=33;
    std::cout<<"gcd: "<<gcd(a,b);
    return 0;
}
