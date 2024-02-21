#include<iostream>
#include<cstring>
#include"header.h"

int main()
{
    // Book b1;
    // b1.display();
    // b1.calculateFine();
    Book b[3];
    // Book *book=new Book[3];
    for(int i=0;i<3;i++)
    {
        b[i].accept();
    }
    std::cout<<std::endl;
    for(int i=0;i<3;i++)
    {
        std::cout<<"displaying the book details with fine for each:"<<std::endl;
        b[i].display();
        b[i].calculateFine();
    }
    std::cout<<std::endl;
    // for(int i=0;i<3;i++)
    // {
    //     std::cout<<"fine of book "<<b[i].getBookname()<<" is "<<b[i].calculateFine()<<std::endl;
    // }    
    for(int i=0;i<3;i++)
    {
        b[i].showAuthor();
    }
    for(int i=0;i<3;i++)
    {
        b[i].showPrice();
    }
    // delete []book;
}