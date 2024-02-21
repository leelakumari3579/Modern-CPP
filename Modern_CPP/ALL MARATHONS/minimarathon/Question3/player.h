#ifndef PLAYER_H
#define PLAYER_H

#include<cstring>
#include<iostream>
class player{
    private:
        int pid;
        char *pname;
        int match[3];
    public:
        player();
        player(int,const char *,int[]);
        player(player&);
        ~player();
        int getPid() const { return pid; }
        void setPid(int pid_) { pid = pid_; }

        const char *getPname() const { return pname; }
        void setPname(const char *pname_) { 
            pname=new char[strlen(pname)+1];
            strcpy(pname,pname_);
         }
        float calculateAverageScores();
        void accept();
        void display();
        friend void operator<<(std::ostream &os,player &p);
        bool operator==(player&);
        bool operator<(player&);
        char& operator[](int);
};

#endif // PLAYER_H
