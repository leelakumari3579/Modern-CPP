#include"header.h"
#include<stdio.h>
int main()
{
    struct candidate c[3];
    for(int i=0;i<3;i++)
    {
        printf("enter candidate scores\n");
        scanf("%d %d %d",&c[i].scores[0],&c[i].scores[1],&c[i].scores[2]);
    }
    selection(c);
}