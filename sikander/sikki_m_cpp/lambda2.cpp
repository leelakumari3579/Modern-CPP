#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
//  int main()
//  {
//     int arr[]={5,10,12,14,15};
//     // for(int ele:arr) -->//will not modified the array
//     for(int &ele:arr)  //will modify the array by using reference(&)
//         ele=ele+2;
//     for(int ele:arr)
//         std::cout<<ele<<" ";  
//  }

// bool order(int a,int b)
// {
//    return a>b;
// }
// int main()
// {
//     int arr[]={20,1,32,40,23};
//     std::sort(arr,arr+5,order);
//     for(int ele:arr)
//     std::cout<<ele<<std::endl;
// }

// void myfunc()
// {
//     std::cout<<"my func "<<std::endl;
// }
// int main()
// {
//     void (*fptr)()=myfunc;
//     fptr();
//     fptr();
//     void (*lambda)()=[]{std::cout<<"lambda func"<<std::endl;};
//     lambda();
//     lambda();
// }

// void myfunc(int x)
// {
//     std::cout<<"my func "<<x<<std::endl;
// }
// int main()
// {
//     void (*fptr)(int)=myfunc;
//     fptr(3);
//     fptr(7);
//     void (*lambda)(int)=[](int x){std::cout<<"lambda func"<<x<<std::endl;};
//     lambda(10);
//     lambda(70);
// }

// int add(int x,int y)
// {
//     return x+y;
// }
// int main()
// {
//     int (*fptr)(int,int)=add;
//     int x=fptr(3,7);
//     std::cout<<x<<" "<<std::endl;
//     int (*lambda)(int,int)=[](int x,int y)->int{return x+y;};
//     int y=lambda(10,20);
//     std::cout<<y<<" "<<std::endl;
// }

// int main()
// {
//     int arr[]={10,32,12,12,34,5,6,78,34};
//     std::cout<<"even numbers "<<std::count_if(arr,arr+9,[](int n){return n%2==0;});
// }

// int main()
// {
//     int arr[]={10,32,12,2,34,5,6,7,34};
//     std::cout<<"prime numbers "<<std::count_if(arr,arr+9,[](int n){int i;
//                                                         for(i=2;i<n;i++)
//                                                             if(n%i==0)
//                                                             break;
//                                                             return(i==n);});
// }

// int main()
// {
//     int a=5;
//     int b=10;
//     //auto lambda = [](){std::cout<<a<<std::endl;std::cout<<b;}; //gives error
//     // auto lambda = [=](){
//     //                     a++;
//     //                     std::cout<<a<<std::endl;std::cout<<b;}; //invalid -> cannot modify read-only variable
//     //auto lambda = [=](){std::cout<<a<<std::endl;std::cout<<b;};
//     auto lambda = [&](){a++;b++;};
//     std::cout<<"before call "<<a<<" "<<b<<std::endl;
//     lambda();
//     std::cout<<"after call "<<a<<" "<<b<<std::endl;
// }

// int main()
// {
//     int arr[]={10,32,12,12,34,5,6,78,34};
//     int key = 12;
//     int c = std::count_if(std::begin(arr),std::end(arr),[key](int ele){return ele>=key;});
//     std::cout<<"number of elements > "<<key<<":"<<c<<std::endl;
// }

int main()
{
    //generic lambda function that addas two values of any type
    auto add = [](auto a,auto b){return a+b;};
    //using the generic lambda function
    int a=5,b=10;
    std::string s1="programming";
    std::string s2="leela";
    std::cout<<"sum (int): "<<add(a,b)<<std::endl;
    std::cout<<"concatinate (string): "<<add(s1,s2)<<std::endl;
}