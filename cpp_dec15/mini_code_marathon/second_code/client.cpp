#include<iostream>
#include<cstring>
#include"header.h"

void Add(Loan *l,int j)
{
    l[j].InserRecord();
    // std::cout<<"enter loan number: "<<std::endl;
    // std::cin>>l_number;
    // std::cout<<"enter amount: "<<std::endl;
    // std::cin>>amount;
    // std::cout<<"enter name: "<<std::endl;
    // std::cin>>name;
}

void show(Loan *l)
{
    for(int i=0;i<3;i++)
        l[i].PrintRecord();
    // std::cout<<"loan number= "<<l.loanNumber<<std::endl;
    // std::cout<<"Amount= "<<l.Amount<<std::endl;
    // std::cout<<"Name= "<<l.Name<<std::endl;
    //std::cout<<"interest amount= "<<Loan::CalculateInterest()<<std::endl;
}

void search(Loan *l,int l_number)
{
    for(int i=0;i<3;i++){
    if(l[i].getLoanNumber()==l_number)
        show(l);
    else if(i==3)
        std::cout<<"Record not found: "<<std::endl;
}
}
int CountCustomers(float amnt)
{
    int count=0;
    while(amnt>500000 && amnt<=1500000)
        count +=1;
    return count;
}

int main()
{
    int j=0;
    int n;
    std::cout<<"Enter the number of objects: ";
    std::cin>>n;
    Loan *l=new Loan[n];
    Add(l,j);
    j++;
   // l[0].InserRecord();
    // for(int i=0;i<j;i++)
    // {
    //     l[i].PrintRecord();
    // }
    show(l);
    std::cout<<"enter loan number: "<<std::endl;
    int l_number;
    std::cin>>l_number;
    search(l,l_number);
    int amnt=l->amount();
    std::cout<<"count of heighest loan interest amount: "<<CountCustomers(amnt)<<std::endl;
    delete []l;
}