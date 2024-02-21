#include<stdio.h>
int main()
/*{
    int i;
    for(i=1;i<=10;i++);  //terminates after completing iteration and executes next statements
        printf("%d\n",i);  //not a body of for loop(independent statement)
    //printf("%d",i);
    return 0;
}*/
/*{
    int i=1;
    for( ; ; )
    {
        if(i>10)
            break;
        printf("%d\n",i);
        i++;
    }
}*/
/*{
    int i=1;
    do
    {
        printf("%d\n",i);
        i++;
    }
    while (i<=10);
    return 0;
}*/
/*{
    int i=1;
    do
        printf("%d\n",i);
    while (i++<=10);
    return 0;
    
}*/
/*{
    int i,sum=0;
    for(i=1;i<=5;i++)
        sum +=i;
    printf("sum of first 5 numbers: %d",sum);
}*/
/*{
    int i=1,sum=0;
    while(i<=10)
    {
        sum +=i;
        i++;
    }
    printf("%d",sum);
    return 0;
}*/
/*{
    int i=1,prod=1;
    do
    {
        prod *=i;
        i++;
    } while (i<=10);
    printf("product of 1 to 10 numbers: %d",prod);
    
}*/
/*{
    int n=12342;
    int sum=0,rem;
    while(n>0)
    {
        rem=n%10;
        sum +=rem;
        n /=10;
    }
    printf("sum of digits in number: %d",sum);
}*/
/*{
    int n=12342;
    int rev=0,rem;
    while(n>0)
    {
        rem=n%10;
        rev = rev*10+rem;
        n /=10;
    }
    printf("reverse of a number is: %d",rev);
}*/
/*{   
    //multiplication table
    int n=8;
    for(int i=1;i<=10;i++)
        printf("%d * %d = %d\n",n,i,n*i);
}*/
/*{
    //prime numbers
    int i,num=132,flag=1;
    for(i=2;i<num;i++)
    {
        if(num%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag)
        printf("%d is a prime number.",num);
    else
        printf("%d is not a prime number.",num);

}*/
/*{
    //squares of some range of  numbers
    int l_limit,u_limit,i,sq=1;
    printf("enter lower limit: ");
    scanf("%d",&l_limit);
    printf("enter upper limit: ");
    scanf("%d",&u_limit);
    for(i=l_limit;i<=u_limit;i++)
    {
        sq =i*i;
        printf("%d\t",sq);
    }
    return 0;
}*/
/*{
    //finacci series.
    int n,i,f3,f1=0,f2=1;
    printf("enter n value: ");
    scanf("%d",&n);
    printf("%d\n",f1);
    printf("%d\n",f2);
    for(i=2;i<=n;i++)
    {
        f3=f1+f2;
        printf("%d\n",f3);
        f1=f2;
        f2=f3;
    }
}*/
/*{
    //patterns
    int i,j;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
}*/
{
    //*#*#
    //*#*# pattern

}
