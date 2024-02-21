#include<stdio.h>
#define size 5
void rev(int []);
int main()
{
    int a[size]={7,8,55,7,70};
    rev(a);
    return 0;
}
void rev(int *c)
{
    int i=0,j=size-1,temp;
    //for(int i=0;i<size;i++)
        //printf("\n%d",*(c+i));
    while(i<j)
    {
        temp=c[i];
        c[i]=c[j];
        c[j]=temp;
        i++;
        j--;
    }
    for(int k=0;k<size;k++)
        printf("%d",*(c+k));
}