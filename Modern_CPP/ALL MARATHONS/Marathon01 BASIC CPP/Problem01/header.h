#ifndef HEADER_H
#define HEADER_H

#include<cstring>

class Book {
    
    int bookId;
    char bookName[50];    
    char authorName[50];
    int price;
    int numberOfDaysUsed;

    public:

        // Declaration of default constructor.
        Book();

        // Getters and Setters of the Data members.
        int getBookId() const { return bookId; }
        void setBookId(int bookId_) { bookId = bookId_; }

        char *getBookName() { return bookName; }
        void setBookName(char *bookName_) { strcpy(bookName, bookName_); }

        char *getAuthorName() { return authorName; }
        void setAuthorName(char *authorName_) { strcpy(authorName, authorName_); }

        int getPrice() const { return price; }
        void setPrice(int price_) { price = price_; }

        int getNumberOfDaysUsed() const { return numberOfDaysUsed; }
        void setNumberOfDaysUsed(int numberOfDaysUsed_) { numberOfDaysUsed = numberOfDaysUsed_; }

        // User defined functions

        int calculateFine();
        void accept();
        void display();

        
};

#endif // HEADER_H
