#include"header.h"
#include<stdio.h>
int main()
{
    int n;
    printf("enter n value: ");
    scanf("%d",&n);
    int rev_num=reverse(n);
    printf("%d",rev_num);
    return 0;
}