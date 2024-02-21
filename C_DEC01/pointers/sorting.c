#include<stdio.h>
int sort(int *x,int s)
{
    int temp;
    for(int i=0;i<s;i++)
    {
        for(int j=i+1;j<s;j++)
        {
            if(x[i]>x[j])
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
    for(int i=0;i<s;i++)
        printf("%d  ",*(x+i));
}
int main()
{
    int n;
    printf("enter n value: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,n);
}