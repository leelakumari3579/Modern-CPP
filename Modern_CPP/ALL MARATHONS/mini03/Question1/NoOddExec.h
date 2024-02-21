#ifndef NOODDEXEC_H
#define NOODDEXEC_H

#include<exception>
#include<cstring>

class NoOddExec : public std::exception  //Custom Exceptions.........
{
private:
   char* _msg;
public:

    NoOddExec(const char* msg)
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    
    NoOddExec() =delete;
    NoOddExec(const NoOddExec& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        
    }
    NoOddExec(NoOddExec&& rhs)
    {

         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

    }
    NoOddExec& operator=(const NoOddExec& rhs)
    {


        this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;

    }
    NoOddExec& operator=(NoOddExec&& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;
    }
    ~NoOddExec()
    {
        delete []_msg;
    }

    char* what()
    {
        return _msg;
    }


};


#endif // NOODDEXEC_H
