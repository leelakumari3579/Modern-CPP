#include<iostream>
#include<cstring>
#include"header.h"

Loan::Loan()
{
    loanNumber=0000000;
    Amount=50000.0f;
    strcpy(Name,"leela");
    interestAmount=0;
}

Loan::Loan(long int ln, float a, char n[], float i)
{
    loanNumber=ln;
    Amount=a;
    strcpy(Name,n);
    interestAmount=i;
}

Loan::~Loan()
{
}


void Loan::CalculateInterest()
{
    interestAmount=0;
    if(Amount>500000 && Amount<=1500000)
    {
        interestAmount=Amount*0.10;
        std::cout<<"ineterest = "<<interestAmount<<std::endl;
    }
    else if(Amount>100000 && Amount<=500000)
    {
        interestAmount=Amount*0.05;
        std::cout<<"ineterest = "<<interestAmount<<std::endl;
    }
    else if(Amount<=100000)
    {
        interestAmount=Amount*0.02;
        std::cout<<"ineterest = "<<interestAmount<<std::endl;
    }
}

void Loan::InserRecord()
{
    std::cout<<"enter loan number: "<<std::endl;
    std::cin>>loanNumber;
    std::cout<<"enter amount: "<<std::endl;
    std::cin>>Amount;
    std::cout<<"enter name: "<<std::endl;
    std::cin>>Name;
}

void Loan::PrintRecord()
{
    std::cout<<"loan number= "<<loanNumber<<std::endl;
    std::cout<<"Amount= "<<Amount<<std::endl;
    std::cout<<"Name= "<<Name<<std::endl;
}
