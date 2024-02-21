#include<iostream>
#include<cstring>
void fun(int a,int b=0); //inialization can be done in declaration
int main()
{
    //fun(10,20);
    //fun(10);
    char *s1="leela"; //it is a non constant pointer to non constant string
    char *s2="kumari";
    char *s3=strcat(s1,s2);
    return 0;
}
void fun(int a,int b) //intialization is optional in definition part
{

}