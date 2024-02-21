#include<stdio.h>
int main()
/*{
    int i,l_limit=2,u_limit=50,n;
    for(n=l_limit;n<=u_limit;n++)
    {
        int flag=1;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag=0; //not prime
            break;
        }
    }
    if(flag)
        printf("%d\n",n);
    }
}*/
{
    int n=2,j;
    int c=0;
    while(c<4)
    {
        int flag=1;
        for(j=2;j<n;j++)
        {
            if(n%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf("%d\n",n);
            c++;
        }
    }
}
