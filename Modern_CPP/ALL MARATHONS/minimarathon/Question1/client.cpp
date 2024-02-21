#include "book.h"
#include<iostream>
int main(int argc, char const *argv[])
{   
    int n=3; // length of the array;
    Book arr[n]; //create array 3 objects-->1
    //accept book details ->2
    for(int i=0;i<n;i++){
        std::cout<<"enter the "<<i+1<<"book details"<<std::endl;
        arr[i].accept();
    }
    // display book details ->3
    std::cout<<"display book details"<<std::endl;
    for(int i=0;i<n;i++){
       arr[i].display();
     // std::cout<<arr[i];
    }
    // calculate fine and display:->4
     std::cout<<"calculate fine and display"<<std::endl;
    for(int i=0;i<n;i++){
        int fine=arr[i].calculateFine();
        std::cout<<"The fine for book :"<<arr[i].getBookname()<<" is "<<fine<<std::endl;
    }
    // show books whose author name starts with 'A';->5.
    std::cout<<"Book Author name starts with A"<<std::endl;
    for(int i=0;i<n;i++){
        if(arr[i].getAuthorname()[0]=='A'){
         //  arr[i].display();
           std::cout<<arr[i];
        } 
    }
    // show books whose price is less than 2500;->6;
     std::cout<<"Show books whose price is less than 2500"<<std::endl;
    for(int i=0;i<n;i++){
        if(arr[i].getPrice()<2500){
          // arr[i].display();
                    std::cout<<arr[i];

        } 
    }



    return 0;
}
