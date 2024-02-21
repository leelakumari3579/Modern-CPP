#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char arr[7]="kpit";
    /*
    int i=0;
    while(str[i]!='\0')
        i++;
    printf(" length = %d",i);
    */
    printf("%s",arr);
    char *p=arr;
    //p += 2;
    printf("\n %c",++*p);
    printf("\n %c",*++p);
    printf("\n %c",*p++);
    printf("\n %c",*p);
    printf("\n %c",++(*p));
    printf("\n str = %s",arr);
    return 0;
}