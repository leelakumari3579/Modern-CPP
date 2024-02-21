#include<iostream>
#include<cstring>
//using namespace std;
//istream -class
//ostream-class 
//cout---- object of ostream class
//cin ---- object of istream class 
// <<  insertion operator 
// >>  extraction operator
int h=10;
int& fun2()
{
    int c=80;
    return h;
}
int& fun3(int *s)
{
    return *s;
}
int main()
{
    

    int j=10;
    j = fun3(&j);

   // int f=fun2();


    int a=10,b=20;
    int &r1=a;
    int &r2=b;
    int c = r1+ r2;

   
    //std::cout<<"y = "<<y<<std::endl;
    int n=10;
    int *arr= new int[n];  //(int *)malloc(n*sizeof(int));

    char *cptr= new char[20];  // (char*)malloc(20*sizeof(char));

    char str[30]="learning cpp at kpit";
    int len = strlen(str);
    std::cout<<"\n len= "<<len<<std::endl;

    int num1,num2;
    std::cout<<"Enter 2 numbers "<<std::endl;
    std::cin>>num1>>num2;//casceding effect
    int sum=num1+num2;
    std::cout<<"\n addition of 2 numbers = "<<sum<<std::endl;
    delete []arr;//use delete to avoid memory leakage 
    delete []cptr;
    
    return 0;
}



