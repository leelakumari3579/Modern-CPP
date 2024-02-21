#ifndef BOOK_H
#define BOOK_H

#include <cstring>
#include <ostream>
// creation of class Book:
class Book{
    private:
        int Bookid;
        char bookname[20];
        char authorname[20];
        int price;
        int NumberofdaysUsed;
    public:
        static int cnt;
        Book(); // constructor
        void accept();
        void display();
        int calculateFine();
        // getter and settter methods:
        int getBookid() const { return Bookid; }
        void setBookid(int bookid) { Bookid = bookid; }

        const char* getBookname() const { return bookname; }
        void setBookname(const char* bookname_) { strcpy(bookname,bookname_); }

        const char* getAuthorname() const { return authorname; }
        void setAuthorname(const char* authorname_) { strcpy(authorname,authorname_); }

        int getPrice() const { return price; }
        void setPrice(int price_) { price = price_; }

        int numberofdaysUsed() const { return NumberofdaysUsed; }
        void setNumberofdaysUsed(int numberofdaysUsed) { NumberofdaysUsed = numberofdaysUsed; }

        friend std::ostream &operator<<(std::ostream &os, const Book &rhs);
        
};

#endif // BOOK_H
