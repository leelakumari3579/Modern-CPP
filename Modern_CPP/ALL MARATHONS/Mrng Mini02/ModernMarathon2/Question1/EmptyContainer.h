#ifndef EMPTYCONTAINER_H
#define EMPTYCONTAINER_H

#include<exception>
#include<cstring>
#include<iostream>
class EmptyContainer : public std::exception
{
private:
     char* _msg;
public:
    EmptyContainer() =delete;
    explicit EmptyContainer(const char* msg){
      std::cout<<"Exception called in para "<<std::endl;
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    EmptyContainer(const EmptyContainer& obj)
    {
        (*this)._msg = new char[strlen(obj.msg())+1];
        strcpy((*this)._msg,obj.msg());
        
    }
    EmptyContainer& operator=(const EmptyContainer&)=default;
    EmptyContainer(EmptyContainer&&)=default;
    EmptyContainer& operator=(EmptyContainer&&)=delete;
    ~EmptyContainer()
    {
        delete _msg;
    }

    virtual char* what()
    {
        return _msg;
    }

    char* msg() const { return _msg; }
    
};

#endif // EMPTYCONTAINER_H
