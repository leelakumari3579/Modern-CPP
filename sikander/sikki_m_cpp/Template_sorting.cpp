#include<iostream>
#include<cstring>
template<class T>
void sort(T arr[],int size)
{
    T temp=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    std::cout<<"sorted elements = ";
    for(int i=0;i<size;i++)
    {
        std::cout<<arr[i]<<"\t";
    }
    std::cout<<std::endl;
}
int main()
{
    int arr[]={20,50,39,10,70};
    sort(arr,5);

    float arr2[]={0,3.5,10.90,70.5,50.3};
    sort(arr2,5);

    char arr3[]={'A','H','D','C','G'};
    sort(arr3,5);
}