#include<iostream>
#include<cstring>
#include"header.h"
Book::Book()
{
    Bookid=12875;
    strcpy(bookname,"Test your c skills");
    strcpy(authorname,"viswanth");
    price=1200;
    NumberofdaysUsed=12;
}
// Book::Book(int id,char nm[],char anm[],int p,int used)
// {
//     Bookid=id;
//     strcpy(bookname,nm);
//     strcpy(authorname,anm);
//     price=p;
//     NumberofdaysUsed=used;
// }

void Book::calculateFine()
{
    int fine=0;
    if(NumberofdaysUsed>10 && NumberofdaysUsed<=20)
    {
        fine=100;
        std::cout<<"fine of the book is: "<<fine<<std::endl;
    }
    else if(NumberofdaysUsed>20 && NumberofdaysUsed<=30)
    {
        fine=200;
        std::cout<<"fine of the book is: "<<fine<<std::endl;
    }
    else if(NumberofdaysUsed>30 && NumberofdaysUsed<=40)
    {
        fine=300;
        std::cout<<"fine of the book is: "<<fine<<std::endl;
    }
    else if(NumberofdaysUsed>40)
    {
        fine=500;
        std::cout<<"fine of the book is: "<<fine<<std::endl;
    }
}

void Book::accept()
{
    std::cout<<"enter book id: "<<std::endl;
    std::cin>>Bookid;
    std::cout<<"enter book name: "<<std::endl;
    std::cin>>bookname;
    std::cout<<"enter author name: "<<std::endl;
    std::cin>>authorname;
    std::cout<<"enter book price: "<<std::endl;
    std::cin>>price;
    std::cout<<"enter number of days used: "<<std::endl;
    std::cin>>NumberofdaysUsed;
}

void Book::display()
{
    std::cout<<"Book id: "<<Bookid<<std::endl;
    std::cout<<"Book name: "<<bookname<<std::endl;
    std::cout<<"Author name: "<<authorname<<std::endl;
    std::cout<<"Price: "<<price<<std::endl;
    std::cout<<"Number of days used: "<<NumberofdaysUsed<<std::endl;
}

void Book::showAuthor()
{
    if(authorname[0]=='A')
        std::cout<<"Books having Author name starts with 'A'"<<bookname<<std::endl;
}

void Book::showPrice()
{
    if(price<=2500)
        std::cout<<"price less than 2500 "<<bookname<<std::endl;
}
