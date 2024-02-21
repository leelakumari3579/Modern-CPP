#include"header.h"
#include<stdio.h>
int even_odd(int e_o[],int size)
{
    int e_add=0,o_add=0;
    for(int i=0;i<size;i++)
    {
        if(e_o[i]%2==0)
            e_add+=e_o[i];
        else
            o_add+=e_o[i];
    }
    printf("even sum = %d\n",e_add);
    printf("odd sum = %d",o_add);
}