#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H
#include<exception>
#include<cstring>

class EmptyContainerException : public std::exception  //Custom Exceptions.........
{
private:
   char* _msg;
public:

    EmptyContainerException(const char* msg)
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    
    EmptyContainerException() =delete;
    EmptyContainerException(const EmptyContainerException& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        
    }
    EmptyContainerException(EmptyContainerException&& rhs)
    {

         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

    }
    EmptyContainerException& operator=(const EmptyContainerException& rhs)
    {


        this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;

    }
    EmptyContainerException& operator=(EmptyContainerException&& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;
    }
    ~EmptyContainerException()
    {
        delete []_msg;
    }

    char* what()
    {
        return _msg;
    }


};

#endif // EMPTYCONTAINEREXCEPTION_H
