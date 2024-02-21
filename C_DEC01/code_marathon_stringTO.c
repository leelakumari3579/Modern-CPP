#include<stdio.h>
#include<string.h>
int main()
{
    char* name;
    printf("enter string ");
    scanf("%s",name);
    char *p=name;
    int n=strlen(name);
    for(int i=0;i<n;i++)
    {
        if(p[i]=='a')
            p[i]='1';
        else if(p[i]=='e')
            p[i]='2';
        else if(p[i]=='i')
            p[i]='3';
        else if(p[i]=='o')
            p[i]='4';
        else if(p[i]=='u')
            p[i]='5';
        else
            p[i] +=1;
    }
    for(int i=0;i<n;i++)
        printf("%c ",*(p+i));
}