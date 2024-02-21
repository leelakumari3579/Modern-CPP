#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include<cstring>

enum Exam_category
{
    UNIT_TEST,
    MID_TERM,
    END_SEM
};
class Exam
{
    protected:
    enum Exam_category EC;
    std::string examCode;
    int timeDuration;
    public:
        Exam();
        Exam(enum Exam_category,std::string,int);
        ~Exam();
        virtual void Display()=0;

        std::string getExamCode()  { return examCode; }
        void setExamCode( std::string &examCode_) { examCode = examCode_; }

        int getTimeDuration()  { return timeDuration; }
        void setTimeDuration(int timeDuration_) { timeDuration = timeDuration_; }

        enum Exam_category eC()  { return EC; }
        void setEC( enum Exam_category &eC) { EC = eC; }
};

enum Exam_platform
{
    MEET,
    TEAMS,
    ZOOM
};
class OnlineExam:public Exam
{
    enum Exam_platform EP;
    public:
        OnlineExam();
        OnlineExam(enum Exam_platform ep,enum Exam_category,std::string,int);
        ~OnlineExam();
        void copyConstructor();
        virtual void Display();
        float AverageMarks(int []);

        enum Exam_platform eP() { return EP; }
        void setEP( enum Exam_platform &eP) { EP = eP; }
};

enum Exam_Topic
{
    CPP,
    DS,
    JAVA
};
class OfflineExam:public Exam
{
    enum Exam_Topic ET;
    std::string examLocation;
    public:
        OfflineExam();
        OfflineExam(enum Exam_Topic et,std::string,enum Exam_category,std::string,int);
        void Display();
        void ChangeLocation(std::string);

        enum Exam_Topic eT()  { return ET; }
        void setET( enum Exam_Topic &eT) { ET = eT; }

        std::string getExamLocation()  { return examLocation; }
        void setExamLocation( std::string &examLocation_) { examLocation = examLocation_; }
};

#endif // HEADER_H