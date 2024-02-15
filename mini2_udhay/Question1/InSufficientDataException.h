#ifndef INSUFFICIENTDATAEXCEPTION_H
#define INSUFFICIENTDATAEXCEPTION_H

#include<exception>
#include<cstring>

class InSufficientDataException : public std::exception  //Insufficient Data Exception
{
private:
   char* _msg;
public:

    InSufficientDataException(const char* msg)
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    
    InSufficientDataException() =delete;
    InSufficientDataException(const InSufficientDataException& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        
    }
    InSufficientDataException(InSufficientDataException&& rhs)
    {

         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

    }
    InSufficientDataException& operator=(const InSufficientDataException& rhs)
    {


        this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;

    }
    InSufficientDataException& operator=(InSufficientDataException&& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;
    }
    ~InSufficientDataException()
    {
        delete []_msg;
    }

    char* what()
    {
        return _msg;
    }


};

#endif // INSUFFICIENTDATAEXCEPTION_H
