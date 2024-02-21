#include<iostream>
#include"header.h"
#include<cstring>

Exam::Exam()
{
    EC=UNIT_TEST;
    examCode="A002";
    timeDuration=120;
}

Exam::Exam(Exam_category ec, std::string ecode, int td)
{
    EC=ec;
    examCode=ecode;
    timeDuration=td;
}

Exam::~Exam()
{
}

OnlineExam::OnlineExam()
{
    EP=TEAMS;
    EC=UNIT_TEST;
    examCode="A002";
    timeDuration=120;
}

OnlineExam::OnlineExam(Exam_platform ep,Exam_category ec, std::string ecode, int td):Exam(ec,ecode,td)
{
    EP=ep;
}

OnlineExam::~OnlineExam()
{
}

void OnlineExam::copyConstructor()
{
}

void OnlineExam::Display()
{
    std::cout<<"exam type = "<<EC<<std::endl;
    std::cout<<"exam code = "<<examCode<<std::endl;
    std::cout<<"time duration = "<<timeDuration<<std::endl;
    std::cout<<"exam platform = "<<EP<<std::endl;
}

float OnlineExam::AverageMarks(int arr[])
{
    int sum=0;
    for(int i=0;i<5;i++)
    {
        sum += arr[i];
    }
    return sum/5.0f;
}

OfflineExam::OfflineExam()
{
    EC=UNIT_TEST;
    examCode="A002";
    timeDuration=120;
    ET=CPP;
    examLocation="pune";
}

OfflineExam::OfflineExam(Exam_Topic et, std::string el,Exam_category ec, std::string ecode, int td):Exam(ec,ecode,td)
{
    ET=et;
    examLocation=el;
}

void OfflineExam::Display()
{
    std::cout<<"exam type = "<<EC<<std::endl;
    std::cout<<"exam code = "<<examCode<<std::endl;
    std::cout<<"time duration = "<<timeDuration<<std::endl;
    std::cout<<"exam topic = "<<ET<<std::endl;
    std::cout<<"exam location = "<<examLocation<<std::endl;
}

void OfflineExam::ChangeLocation(std::string newloc)
{
    examLocation=newloc;
}

