#include "player.h"
#include<cstring>
// default;
player::player(){ 
    pid=1;
    pname=new char[10];
    strcpy(pname,"default");
    for(int i=0;i<3;i++){
        match[i]=0;
    }
    
}
//constructor: parameteric
player::player(int p, const char *name, int m[])
{   
    pid=p;
    pname=new char[strlen(name)+1];
    strcpy(pname,name);
    for(int i=0;i<3;i++){
        match[i]=m[i];
    }
}
// copy constructor;
player::player(player &p)
{
    pid=p.pid;
    pname=new char[strlen(p.pname)+1];
    strcpy(pname,p.pname);
    for(int i=0;i<3;i++){
        match[i]=p.match[i];
    }

}

// destructor
player::~player()
{
    delete[] pname;
}
// Avg
float player::calculateAverageScores()
{   
    float avg=0;
    for(int i=0;i<3;i++){
        avg+=match[i];
    }
    return avg/3.0;// TODO: insert return statement here
}
// input
void player::accept()
{
    std::cout<<"enter the playerid:"<<std::endl;
    std::cin>>pid;
    std::cout<<"enter the playername:"<<std::endl;
    pname=new char[20];
    std::cin>>pname;
    std::cout<<"enter the match marks:"<<std::endl;
    for(int i=0;i<3;i++){
        std::cin>>match[i];
     }
}
// display
void player::display()
{
    std::cout<<"playerid:";
    std::cout<<pid<<std::endl;
    std::cout<<"playername:"<<pname<<std::endl;
    std::cout<<"match marks:"<<std::endl;
    for(int i=0;i<3;i++){
        std::cout<<match[i];
     }
}
// equal
bool player::operator==(player &p)
{   
    if(strcmp(pname,p.pname)==0) return true;
    return false;
}
// less than
bool player::operator<(player &p)
{   
    if(calculateAverageScores()<p.calculateAverageScores()) return true;
    return false;
}
// subscript;
char &player::operator[](int ind)
{   
    return pname[ind];
    
}
//print;
void operator<<(std::ostream &os, player &p)
{
    p.display();
}
