#include<iostream>
#include "loan.h"
int maxInd=-1;
float maxLoan=0;
void Add(Loan *l,int ind){
    l[ind].insertRecord();
    if(l[ind].getInterestNo()>maxLoan){
        maxLoan=l[ind].getInterestNo();
        maxInd=ind;
    }
}
void Show(Loan *arr,int len){
    std::cout<<"Showing all the records"<<std::endl;
    for(int i=0;i<len;i++)
        arr[i].printRecord();
}
void doSearch(Loan *arr,int len,int id){
    for(int i=0;i<len;i++){
        if(arr[i].getLoanNo()==id){
            arr[i].printRecord();
            return;
        }
    }
    throw "RECORD NOT FOUND";
}
void Search(Loan *arr,int len){
    try{
        std::cout<<"enter the id to be search \n";
        int id;
        std::cin>>id;
        doSearch(arr,len,id);
    }catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
}
void CountCustomers(Loan *arr){
  if(maxInd==-1){
    std::cout<<"There is no Customers !!!!"<<std::endl;
  }else{
     std::cout<<"Customers having high interest amount"<<std::endl;
    arr[maxInd].printRecord();
  }
}
void printMenu(){
    std::cout<<"*****************************************"<<std::endl;
    std::cout<<"1. ADD ONE RECORD IN AN ARRAY"<<std::endl;
    std::cout<<"2. SHOW ALL RECORDS "<<std::endl;
    std::cout<<"3. SEARCH A RECORD "<<std::endl;
    std::cout<<"4. COUNT THE HIGHEST LOAN CUSTOMERS"<<std::endl;
    std::cout<<"5. TO EXIT"<<std::endl;
    std::cout<<"*****************************************"<<std::endl;
}
int main(int argc, char const *argv[])
{
    int n=10000;
    Loan *arr = new Loan[n]; // Loan objects in heap: -->(1);
    int curr=0;
    while(1){
        printMenu();
        int option;
        std::cin>>option;
        if(option==5){
            break;
        }
        switch (option)
        {
        case 1: // add();
            Add(arr,curr++);
            break;
        case 2:
            //std::cout<<"option 2"<<std::endl;
            Show(arr,curr);
            break;
        case 3:
            Search(arr,curr);
            break;
        case 4:
            CountCustomers(arr);
            break;
        default:
            break;
        }




    }
    // Add(arr[0]);
    // Show(arr[0]);
    // Search(arr,1,101);
    delete []arr;
    return 0;
}
