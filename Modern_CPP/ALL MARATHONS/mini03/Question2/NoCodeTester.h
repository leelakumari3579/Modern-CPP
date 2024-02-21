#ifndef NOCODETESTER_H
#define NOCODETESTER_H

#include<exception>
#include<cstring>

class NoCodeTester : public std::exception  //Custom Exceptions.........
{
private:
   char* _msg;
public:

    NoCodeTester(const char* msg)
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    
    NoCodeTester() =delete;
    NoCodeTester(const NoCodeTester& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        
    }
    NoCodeTester(NoCodeTester&& rhs)
    {

         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

    }
    NoCodeTester& operator=(const NoCodeTester& rhs)
    {


        this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;

    }
    NoCodeTester& operator=(NoCodeTester&& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;
    }
    ~NoCodeTester()
    {
        delete []_msg;
    }

    char* what()
    {
        return _msg;
    }


};



#endif // NOCODETESTER_H
