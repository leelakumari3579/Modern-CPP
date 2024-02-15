#include"Functionalities.h"
#include<iostream>



void FillingVector(std::vector<int>& v)
{
    int n;
    std::cout<<"Enter the size of the vector"<<std::endl;

        std::cin>>n;
        for(int i=0;i<n;i++)
        {
            int k;
            std::cin>>k;
            v.push_back(k);
        }
}

void MakeLambda(Container& data)
{

    std::function<int(std::vector<int>&)> fn1 = [](std::vector<int>& v)->int{

            if(v.empty())
            {
                throw EmptyContainerException("Data is Empty!!");

            }

            int sum=0;
            for(int i=0;i<v.size();i++)
            {
                if(v[i]%2!=0)  // odd logic
                {
                    if(v[i]%3==0) // divisible by 3 logic
                    {
                        sum = sum + v[i];
                    }
                }
            }

            return sum;
    };

    std::function<int(std::vector<int>&)> fn2 = [](std::vector<int>& v)->int{

        if(v.empty())
        {
            throw EmptyContainerException("Data is Empty!!");
        }

        int low = v[0];

        for(int i=1;i<v.size();i++)
        {
            if(low>v[i])
            {
                low=v[i];
            }
        }

        return low;

    };

    std::function<int(std::vector<int>&)> fn3 = [](std::vector<int>& v)->int{


        if(v.empty())
        {
            throw EmptyContainerException("Data is Empty!!");
        }

        if(v.size()<3)
        {
            throw InSufficientDataException("Container should have atleast Three Values!!");
        }

        int max = v[0];

        for(int i=0;i<3;i++)
        {
            if(max<v[i])
            {
                max=v[i];
            }
        }

        return max;

    };

    data.push_back(fn1);
    data.push_back(fn2);
    data.push_back(fn3);


}

void Operation(Container& data,std::vector<int>& v)
{
        if(v.empty()||data.empty())
        {
            throw EmptyContainerException("Data is Empty!!");
        }

        for(FunType& fn : data)
        {
            try{

                std::cout<<fn(v)<<std::endl;

            }
            catch(EmptyContainerException& emp)
            {

                std::cout<<emp.what()<<std::endl;

            }
            catch(InSufficientDataException& insuff)
            {

                std::cout<<insuff.what()<<std::endl;

            }
        }

}