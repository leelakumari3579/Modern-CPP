#ifndef HEADER_H
#define HEADER_H
class Email
{
private:
    char sender[50];
    char receiver[50];
    char message[50];
    //int mailCount;
    static int emailCount;
public:
 Email(char [],char [],char []);
     Email();
     ~Email();
     void Display();
     void Send();
     void Receive();
     void Delete();
     static int getCount();
};
#endif
