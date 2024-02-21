#include<algorithm> 
#include<iostream>
#include<string>
// template<class T>
// T mymax_element(T arr[],int n)
// {
//     T max=0;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]>max)
//         {
//             max=arr[i];
//         }
//     }
//     // std::cout<<"max element "<<max<<std::endl;
//     return max;
// }
// int main()
// {
//     int arr[]={8,1,24,53,2,12,0};
//     std::cout<<"max element "<<mymax_element(arr,7)<<std::endl;
// }

template<class T>
T mymax_element(T start_ptr,T end_ptr)
{
    T ptrMax=start_ptr;
    while(start_ptr!=end_ptr)
    {
        if(*start_ptr>*ptrMax)
        {
            ptrMax=start_ptr;
        }
        ++start_ptr;
    }
    return ptrMax;
}
int main()
{
    int arr[]={8,1,24,53,2,12,0};
    int *ptrMax=mymax_element(std::begin(arr),std::end(arr));
    std::cout<<"max element "<<*ptrMax<<std::endl;
    std::cout<<"\naddress "<<ptrMax<<std::endl;
    std::cout<<"\nindex position "<<ptrMax-arr<<std::endl;
}