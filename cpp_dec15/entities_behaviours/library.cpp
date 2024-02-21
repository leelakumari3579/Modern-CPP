#include<iostream>
class library
{
private:
    std::string books[50];
    int bookCount;
public:
    library(){
        bookCount=0;
    }
    void addBook(std::string bookTitle)
    {
        if(bookCount<50)
        {
            books[bookCount]=bookTitle;
            std::cout<<"added '"<<bookTitle<<"' to the library."<<std::endl;
            bookCount++;
        }
        else
        {
            std::cout<<"library is full. cannot add '"<<bookTitle<<std::endl;
        }
    }
    void displayBooks()
    {
        std::cout<<"books in the library: "<<std::endl;
        for(int i=0;i<bookCount;i++)
        {
            std::cout<<"- "<<books[i]<<std::endl;
        }
    }
    void lendBook(std::string bookTitle)
    {
        bool found=false;
        for(int i=0;i<bookCount;i++)
        {
            if(books[i]==bookTitle)
            {
                std::cout<<"lending '"<<bookTitle<<"' to user."<<std::endl;
                found=true;
                for(int j=i;j<bookCount-1;j++)
                {
                    books[j]=books[j+1];
                }
                bookCount--;
                break;
            }
        }
        if(!found)
        {
            std::cout<<"book '"<<bookTitle<<"' not found in the library."<<std::endl;
        }
    }
};

int main()
{
    library myLibrary;
    myLibrary.addBook("introduction to c++");
    myLibrary.addBook("python for beginners");
    myLibrary.addBook("data structures and algorithams");
    myLibrary.displayBooks();
    myLibrary.lendBook("introduction to c++");
    myLibrary.displayBooks();
    return 0;
}