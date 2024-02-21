#include<iostream>
#include"header.h"
#include<cstring>

void acceptOnline(OnlineExam &oe)
{
    oe.setEP();
    oe.setEC();
    oe.setExamCode();
    oe.setTimeDuration();
}

void acceptOffline(OfflineExam &ofe)
{
    ofe.setET();
    ofe.setExamLocation();
    ofe.setEC();
    ofe.setExamCode();
    ofe.setTimeDuration();
}
int main()
{
    int n;
    std::cout<<"enter nuber of objects for online exam "<<std::endl;
    std::cin>>n;
    int arr[5]={89,50,90,79,71};
    OnlineExam oe[n];
    // oe[1]={TEAMS,UNIT_TEST,"A001",120};
    for(int i=0;i<n;i++)
    {
        acceptOnline(oe[i]);
    }

    int num;
    std::cout<<"enter nuber of objects for offline exam "<<std::endl;
    std::cin>>num;
    OfflineExam ofe[num];

    for(int i=0;i<num;i++)
    {
        acceptOffline(ofe[i]);
    }

    for(int i=0;i<n;i++)
    {
        oe[i].Display();
    }
    for(int i=0;i<num;i++)
    {
        ofe[i].Display();
    }

}
