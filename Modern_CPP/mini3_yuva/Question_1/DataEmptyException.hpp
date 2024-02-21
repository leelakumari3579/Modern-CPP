#ifndef DATAEMPTYEXCEPTION_HPP
#define DATAEMPTYEXCEPTION_HPP

#include<stdexcept>
#include<cstring>

class DataEmptyException:public std::exception
{
private:
    char* _msg;
public:
    DataEmptyException()=delete;
    DataEmptyException(const DataEmptyException& rhs)
    {
        _msg=new char[strlen(rhs._msg)+1];
        strcpy(_msg,rhs._msg);
    }
    DataEmptyException(DataEmptyException&&)=delete;
    DataEmptyException& operator=(const DataEmptyException& rhs)
    {
        _msg=new char[strlen(rhs._msg)+1];
        strcpy(_msg,rhs._msg);
        return *this;
    }
    DataEmptyException& operator=(DataEmptyException&&)=delete;
    ~DataEmptyException()
    {
        delete _msg;
    }

    DataEmptyException(const char* msg)
    {
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    virtual const char* what()
    {
        return _msg;
    }

};

#endif // DATAEMPTYEXCEPTION_HPP
