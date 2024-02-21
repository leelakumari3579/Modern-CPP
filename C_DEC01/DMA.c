#include<stdio.h>
void accept(int[],int);
void display(int[],int);
int main()
{
    int n;
    printf("enter size : ");
    scanf("%d",&n);
    int *ptr = (int*)malloc(n*sizeof(int));  //=(int*)calloc(2,sizeof(int))
    //printf("%d",ptr[0]);
    accept(ptr,n);
    display(ptr,n);

    /*for realloc
    int n1;
    printf("how many subjects he fail. ");
    scanf("%d",&n1);
    ptr = (int*)realloc(ptr,(n+n1)*sizeof(int));
    for(i=n;i<(n+n1);i++)
    {
        printf("\n enter element ");
        scanf("%d",&ptr[i]);
    }
    display(ptr,n+n1);
    */

    free(ptr);
    //int b=20;
    //ptr = &b;
    return 0;
}
void accept(int *b,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n enter element ");
        scanf("%d",&b[i]);
    }
}
void display(int *b,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("\n element %d",b[i]);
}