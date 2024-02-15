#ifndef DATAEMPTYEXCEPTION_H
#define DATAEMPTYEXCEPTION_H

#include<stdexcept>
#include<cstring>

class EmptyContainerException:public std::exception
{
    private:
        char* _msg;
    public:
        EmptyContainerException()=delete;
        EmptyContainerException(const EmptyContainerException&rhs)
        {
            _msg=new char[strlen(rhs._msg)+1];
            strcpy(_msg,rhs._msg);
        }
        EmptyContainerException(EmptyContainerException&&)=delete;
        EmptyContainerException& operator=(EmptyContainerException&&)=delete;
        EmptyContainerException& operator=(const EmptyContainerException&rhs)
        {
            _msg=new char[strlen(rhs._msg)+1];
            strcpy(_msg,rhs._msg);
            return *this;
        }
        ~EmptyContainerException(){
            delete _msg;
        }
        EmptyContainerException(const char* msg)
        {
            _msg=new char[strlen(msg)+1];
            strcpy(_msg,msg);
        }
        virtual const char* what()
        {
            return _msg;
        }
};

#endif // DATAEMPTYEXCEPTION_H
