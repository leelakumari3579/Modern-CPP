#include<iostream>
#include<cstring>
#include "loan.h"
int Loan::cnt=100;
// default;
Loan::Loan(){
    loanNo=cnt++;
    amount=0.0f;
    strcpy(name,"deault");
    interestAmount=0.0;
}
// Parameter:
Loan::Loan(int amt,char n[],float rate){
    amount=amt;
    strcpy(name,n);
    interestAmount=rate;
}

//accept:
void Loan::insertRecord(){
    std::cout<<"enter the Amount you have"<<std::endl;
    std::cin>>amount;
    std::cout<<"enter the  Name"<<std::endl;
    std::cin>>name;
    calculateInterest();
}

//display:
void Loan::printRecord(){
    std::cout<<"------------------------*******-----------------------------"<<std::endl;
    std::cout<<"Loan Number :"<<getLoanNo()<<std::endl;
    std::cout<<"Amount:"<<getAmount()<<std::endl;
    std::cout<<"Name:"<<getName()<<std::endl;
    std::cout<<"Interest Amount :"<<getInterestNo()<<std::endl;
    std::cout<<"-----------------------*******------------------------"<<std::endl;

}
// Interst caluclate;
 void Loan::calculateInterest(){
    float amt=getAmount();
    if(amt<100000){
        setInterestNo(amount*0.02);
    }else if(amt>100000 && amt<=500000){
        setInterestNo(amount*0.05);
    }else if(amt>500000 && amt<=1500000){
        setInterestNo(amount*0.10);
    }else{
        std::cout<<"enter the correct amount"<<std::endl;
    }
 }
