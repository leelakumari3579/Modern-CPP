#ifndef NOINSTANCEFOUNDEXCEPTION_H
#define NOINSTANCEFOUNDEXCEPTION_H

#include<exception>
#include<cstring>

class NoInstanceFoundException : public std::exception  //Custom Exceptions.........
{
private:
   char* _msg;
public:

    NoInstanceFoundException(const char* msg)
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    
    NoInstanceFoundException() =delete;
    NoInstanceFoundException(const NoInstanceFoundException& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        
    }
    NoInstanceFoundException(NoInstanceFoundException&& rhs)
    {

         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

    }
    NoInstanceFoundException& operator=(const NoInstanceFoundException& rhs)
    {


        this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;

    }
    NoInstanceFoundException& operator=(NoInstanceFoundException&& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;
    }
    ~NoInstanceFoundException()
    {
        delete []_msg;
    }

    char* what()
    {
        return _msg;
    }


};


#endif // NOINSTANCEFOUNDEXCEPTION_H
