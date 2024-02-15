#ifndef VALIDDATANOTFOUNDEXCEPTION_H
#define VALIDDATANOTFOUNDEXCEPTION_H

#include<exception>
#include<cstring>

class ValidDataNotFoundException : public std::exception  //Custom Exceptions.........
{
private:
   char* _msg;
public:

    ValidDataNotFoundException(const char* msg)
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    
    ValidDataNotFoundException() =delete;
    ValidDataNotFoundException(const ValidDataNotFoundException& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        
    }
    ValidDataNotFoundException(ValidDataNotFoundException&& rhs)
    {

         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

    }
    ValidDataNotFoundException& operator=(const ValidDataNotFoundException& rhs)
    {


        this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;

    }
    ValidDataNotFoundException& operator=(ValidDataNotFoundException&& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;
    }
    ~ValidDataNotFoundException()
    {
        delete []_msg;
    }

    char* what()
    {
        return _msg;
    }


};

#endif // VALIDDATANOTFOUNDEXCEPTION_H
