#include<stdio.h>
#include"header.h"
int main()
{
    int s1,s2;
    printf("enter size of first array ");
    scanf("%d",&s1);
    int a[s1];
    for(int i=0;i<s1;i++)
        scanf("%d",&a[i]);
    printf("enter size of second array ");
    scanf("%d",&s2);
    int b[s2];
    for(int i=0;i<s2;i++)
        scanf("%d",&b[i]);
    merge_sorted(a,b,s1,s2);
}