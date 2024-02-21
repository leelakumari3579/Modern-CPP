#ifndef EMPTYCONTAINER_H
#define EMPTYCONTAINER_H

#include<exception>
#include<cstring>

class EmptyContainer : public std::exception  //Custom Exceptions.........
{
private:
   char* _msg;
public:

    EmptyContainer(const char* msg)
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    
    EmptyContainer() =delete;
    EmptyContainer(const EmptyContainer& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        
    }
    EmptyContainer(EmptyContainer&& rhs)
    {

         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

    }
    EmptyContainer& operator=(const EmptyContainer& rhs)
    {


        this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;

    }
    EmptyContainer& operator=(EmptyContainer&& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;
    }
    ~EmptyContainer()
    {
        delete []_msg;
    }

    char* what()
    {
        return _msg;
    }


};


#endif // EMPTYCONTAINER_H