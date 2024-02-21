#ifndef INDEXOUTBOUNDEXEC_H
#define INDEXOUTBOUNDEXEC_H

#include<exception>
#include<cstring>

class IndexOutBoundExec : public std::exception  //Custom Exceptions.........
{
private:
   char* _msg;
public:

    IndexOutBoundExec(const char* msg)
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    
    IndexOutBoundExec() =delete;
    IndexOutBoundExec(const IndexOutBoundExec& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        
    }
    IndexOutBoundExec(IndexOutBoundExec&& rhs)
    {

         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

    }
    IndexOutBoundExec& operator=(const IndexOutBoundExec& rhs)
    {


        this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;

    }
    IndexOutBoundExec& operator=(IndexOutBoundExec&& rhs)
    {
         this->_msg = new char[strlen(rhs._msg)+1];
        strcpy(this->_msg,rhs._msg);

        return *this;
    }
    ~IndexOutBoundExec()
    {
        delete []_msg;
    }

    char* what()
    {
        return _msg;
    }


};


#endif // INDEXOUTBOUNDEXEC_H
