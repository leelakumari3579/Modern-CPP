#include<stdio.h>
int main()
{
    int num=234214534;
    int rem=0,even=0,odd=0;
    while(num!=0)
    {
        rem=num%10;
        if(rem%2==0)
        {
            even +=1;
        }else{
            odd +=1;
        }
        num=num/10;
    }
    printf("even = %d\n odd = %d",even,odd);
}