#include "functionalities.h"
#include<algorithm>
#include<numeric>
#include<iostream>

void MakeLambda(funContainer& fn){
    std::function<int(std::vector<int>&)> SumofSquare=[](std::vector<int>& data){
        std::cout<<"The sum of squares are\n";
        int total=0;
        for_each(data.begin(),data.end(),[&](int &num)
        {total+=num*num;});
        return total;

    };
  std::function<int(std::vector<int>&)>   PrimeNumber=[](std::vector<int>&data){
    std::cout<<"The number of prime numbers are\n";
    int count=0;
        for(auto ele:data){
            bool isprime=true;
            for(int i=2;i<ele;i++){
                if(ele==1) isprime=false;
                else if(ele%i ==0) {
                    isprime=false;
                }
            }
            if(isprime){
                std::cout<<ele<<"\n";
                count++;            }
        }
       return count ;

    };
fn.emplace_back(SumofSquare);
fn.emplace_back(PrimeNumber);
}
void PerformOpearations(funContainer fn,std::vector<int>& data){
    for(auto function:fn){
       std::cout<< function(data);
    }

}

