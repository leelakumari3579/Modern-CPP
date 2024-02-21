#include "Functionalities.h"
#include "EmptyContainer.h"
#include "ValueNotFound.h"
fnType oddSumDivBy3=[](DataContainer& data){
        // if there is no data available in the container;
        if(data.empty()) throw EmptyContainer("No data in the Container");
        int total=0;
        for(int& val:data){
            if(val%3==0 && val%2!=0){  // divisible by 3 and it is odd number;
                total+=val;
            }
        }
        if(total==0){
        throw ValueNotFound("NO Odd multiples of 3 numbers are there in the Conatiner");
         }
        return total;
};

fnType lowestEven=[](DataContainer& data){
    // if there is no data available in the container;
    if(data.empty()) throw EmptyContainer("No data in the Container");
    int even=-1;
    for(int& val:data){
        if(val%2==0 && even==-1){
            even=val;
        }
       else if(val%2==0 && val<even){  // lowest Even;
            even=val;
        }
    }
    if(even%2!=0){
        throw ValueNotFound("NO even Numbers in the Conatiner");
    }
    return even;
};

fnType FindMaxAmongThree=[](DataContainer& data){
    // if there is no data available in the container;
    if(data.empty()) throw EmptyContainer("No data in the Container");
    if(data.size()<3) throw ValueNotFound("Container doesnot Contains 3 values");
    
    int Maxi=data[0];
    for(int i=1;i<3;i++){
        if(Maxi<data[i]){
            Maxi=data[i];
        }
    }
    return Maxi;
};


void PerformOperation(DataContainer &data, fnType func)
{
    std::cout<<"--------------Perform Operation ----------------"<<std::endl;
    try
    {
       std::cout<<func(data)<<std::endl;;
    }
    catch(ValueNotFound& e){
        std::cout << e.what() << '\n';
    }
    catch(EmptyContainer& e){
        std::cout << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"------------------------------"<<std::endl;
}
