#include<stdio.h>
/*int fun(int *p)
{
    scanf("%d",p);
}
int main()
{
    int a;
    int c=fun(&a);
    printf("%d",c);
    return 0;
}
*/
int calculation()
{
    //calculate sum of first 10 even numbers and sum of first 10 odd numbers using fun called . 
    //calculate (...) display result in  main()
    int i=0,sum=0,count=0;
    while(i>=0)
    {
         i++;
        if(i%2==0)
        {
            sum +=i;
            count +=1;
        }
        if(count==10)
            break;
    }
    printf("%d",sum);
}
int main()
{
    calculation();
}