#include "EmptyContainerException.h"


EmptyContainerException::EmptyContainerException(const char *msg)
{
    _msg=new char[strlen(msg)+1];
    strcpy(_msg,msg);
}

char *EmptyContainerException::what()
{
    return _msg;
}
