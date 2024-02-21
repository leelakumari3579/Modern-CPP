#include "header.h"
#include<iostream>

Book::Book() {
    bookId = 0;
    strcpy(bookName, "Not Defined");
    strcpy(authorName, "Anonymous");
    price = 0;
    numberOfDaysUsed = 0;
}

int Book::calculateFine() {
    if(numberOfDaysUsed > 10 && numberOfDaysUsed <= 20)
        return 100;
    else if(numberOfDaysUsed > 20 && numberOfDaysUsed <= 30)
        return 200;
    else if(numberOfDaysUsed > 30 && numberOfDaysUsed <= 40)
        return 300;
    else if(numberOfDaysUsed > 40)
        return 500;
    return 0;
}

void Book::accept() {
    std::cout<<"Enter the Book ID: ";
    std::cin>>bookId;

    std::cout<<"Enter the Book Name: ";
    std::cin>>bookName;

    std::cout<<"Enter the Author Name: ";
    std::cin>>authorName;

    std::cout<<"Enter the price of the book: ";
    std::cin>>price;

    std::cout<<"Enter number of days the book was used: ";
    std::cin>>numberOfDaysUsed;

    std::cout<<"\n\t\t***Record read successfully***\n\n";

}

void Book::display() {
    std::cout<<"Book ID: "<<getBookId()<<"* Book Name: "<<getBookName()<<"* Author Name: "<<getAuthorName()<<"* Price of the Book: "<<getPrice()<<"* Number of Days book used: "<<getNumberOfDaysUsed()<<"* Fine: Rs."<<this->calculateFine()<<std::endl;
}