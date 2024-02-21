#include<iostream>
#include "header.h"

void nameStartingWithA(Book book[], int size) {
    for(int i=0; i<size; i++) {
        if(book[i].getAuthorName()[0] == 'A') {
            book[i].display();
        }
    }
}

void priceOfBookLT2500(Book book[], int size) {
    for(int i=0; i<size; i++) {
        if(book[i].getPrice() < 2500) {
            book[i].display();
        }
    }
}

int main() {
    Book bookShelf[3];
    for(int i=0; i<3; i++) {
        bookShelf[i].accept();
    }
    for(int i=0; i<3; i++) {
        bookShelf[i].display();
    }
    std::cout<<"\n\nBooks whose author names start from 'A': "<<std::endl;
    nameStartingWithA(bookShelf, 3);
    std::cout<<std::endl;
    std::cout<<"Books whose price is less than 2500: "<<std::endl;
    priceOfBookLT2500(bookShelf, 3);
}