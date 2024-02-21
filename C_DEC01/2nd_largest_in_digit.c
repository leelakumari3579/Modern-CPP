#include<stdio.h>
int main()
{
    int n,largest=0,s_largest,reminder;//3241
    printf("enter a no:");
    scanf("%d",&n);
    while(n>0)
    {
        reminder=n%10;
        if(reminder>largest)
        {
            s_largest=largest;
            largest=reminder;
        }
       else if(reminder<largest && reminder>s_largest)
        {
            s_largest=reminder;
        }
     n=n/10;   

    }
    printf("%d",s_largest);
}
/*
int sec_larg(int n)
{
   int max=0,max1=0;
   int r,r1;
   int num2;
   num2=n;
   while(n!=0)
   {
    r=n%10;
    if(r>max)
    {
        max=r;
    }
    n=n/10;
   }
   printf("%d\n",max);
   while(num2!=0)
   {
    r1=num2%10;
    if(r1!=max && r1>max1)
    {
        max1=r1;
    }
    num2=num2/10;
   }
    printf("%d",max1);

   
}
int main()
{
    int n1=1432;
    sec_larg(n1);
}*/
