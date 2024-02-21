#include "book.h"
#include<iostream>

// assign the static variable;
int Book::cnt=100;
Book::Book()
{
   // std::cout<<"default constructor !!!"<<std::endl;
    // assign default values;
    setBookid(cnt++);
    strcpy(bookname,"Sample");
    strcpy(authorname,"varma");
    price=0;
    NumberofdaysUsed=0;
}

void Book::accept()
{
    // taking input from user:
    std::cout<<"enter the Book Name"<<std::endl;
    std::cin>>bookname;
    std::cout<<"enter the Author Name"<<std::endl;
    std::cin>>authorname;
    std::cout<<"enter the Price of Book"<<std::endl;
    std::cin>>price;
     std::cout<<"enter the Number of days"<<std::endl;
    std::cin>>NumberofdaysUsed;
    
}

void Book::display()
{
    std::cout<<"-------------------------------------------------------"<<std::endl;
    std::cout<<"Book Id :"<<Bookid<<std::endl;
    std::cout<<"Book Name:"<<getBookname()<<std::endl;
    std::cout<<"Author Name:"<<getAuthorname()<<std::endl;
    std::cout<<"Price :"<<getPrice()<<std::endl;
    std::cout<<"NumberofdaysUsed :"<<numberofdaysUsed()<<std::endl;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    
}

int Book::calculateFine()
{   
    // fine;
    if(numberofdaysUsed()<10){
        return 0;
    }
    int days=numberofdaysUsed();
    if(days>=10 && days<20){
        return 100;
    }
    if(days>=20 && days<30){
        return 200;
    }
    if(days>=30 && days<40){
        return 300;
    }
    if(days>=40){
        return 500;
    }
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Book &rhs) {
    os << "Bookid: " << rhs.Bookid
       << " bookname: " << rhs.bookname
       << " authorname: " << rhs.authorname
       << " price: " << rhs.price
       << " NumberofdaysUsed: " << rhs.NumberofdaysUsed;
    return os;
}
