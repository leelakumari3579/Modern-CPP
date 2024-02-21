#include <iostream>
#include<cstring>
//user defined exception class 
class OverflowException:public std::exception
{
    char message[100];
    public:
        OverflowException()
        {
            strcpy(message,"stack overflow ");
        }
         OverflowException(const char *s)
        {
            strcpy(message,s);
        }
        char * what()
        {
            return message;
        }
};
class UnderflowException:public std::exception
{
    char message[100];
    public:
        UnderflowException()
        {
            strcpy(message,"stack underflow ");
        }
         UnderflowException(const char *s)
        {
            strcpy(message,s);
        }
        char * what()
        {
            return message;
        }
};
class cStack
{
    int top, size;
    int *arr;

public:
    cStack();
    cStack(int);
    bool isFull();
    bool isEmpty();
    void push(int);
    int pop();  // returns and removes top element
    int peek(); // returns top element
};
int cStack::pop()
{
    if (isEmpty())
    {
        throw  UnderflowException(" stack is empty ");
    }

    return arr[top--];
}
int cStack::peek()
{
    if (isEmpty())
    {
        throw   OverflowException("stack underflow ");
    }

    return arr[top];
}
bool cStack::isEmpty()
{
    return top == -1;
}
void cStack::push(int ele)
{
    if (isFull())
        throw "stack overflow";

    std::cout << "\n push ele";
    arr[++top] = ele;
}
bool cStack::isFull()
{
    return top == size - 1;
}

cStack::cStack()
{
    top = -1;
    size = 2;
    arr = new int[size];
}
cStack::cStack(int s)
{
    top = -1;
    size = s;
    arr = new int[size];
}

int main()
{
    cStack s1;

    try
    {
        s1.push(10);
        s1.push(20);
        s1.push(30);
    }
    catch ( OverflowException obj)
    {
        std::cout <<"\n"<< obj.what() << "\n";
    }
    catch(std::exception  e )// generic handler
    {
        std::cout<<e.what();
    }

    try
    {
        std::cout << "\n " << s1.pop();
        std::cout << "\n " << s1.pop();
        std::cout << "\n " << s1.pop();
    }
    catch (UnderflowException obj)
    {
        std::cout << obj.what() << "\n";
    }
}