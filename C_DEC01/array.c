#include<stdio.h>
//#define SIZE 7
void f1(int [],int); //f1(array,size)
//int k[4];
int main()
{
    //int a[SIZE]={7,8,55,7,70};
    //f1(a);
    int a[5]={7,8,55,77,70};
    f1(a,5); 
    printf("%d",a[2]);
    return 0;
}
//void f1(int *c)
void f1(int *c,int size) //int c[5]
{
    //for(int i=0;i<SIZE;i++)
        //printf("%d",*(c+i));
    //++k -->array cannot be incremented ==>for that ,instead of array we use pointers
    for(int i=0;i<size;i++)
        printf("%d",c[i]);  //printf("%d",*c); -->printf("%d",*(c+i));
    //printf("%d",sizeof(c));
    c[2]=100; // any changes in c , will effect to array a.
}