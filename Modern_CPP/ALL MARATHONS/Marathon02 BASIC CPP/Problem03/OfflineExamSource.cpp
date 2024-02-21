#include "OfflineExam.h"

OfflineExam::OfflineExam(): Exam(), examTopic(CPP), examLocation("TBD") {}

OfflineExam::OfflineExam(etype examType, std::string examCode, int examDuration, ettype examTopic, std::string examLocation):
Exam(examType, examCode, examDuration), examTopic{examTopic}, examLocation{examLocation} {}

void OfflineExam::display() {
    enum etype tempet = getExamType();
    enum ettype tempett = getExamTopic();
    if(tempet == UNIT_TEST) {
        std::cout<<"Exam Type: UNIT_TEST"<<std::endl;
    } else if(tempet == MID_TERM) {
        std::cout<<"Exam Type: MID_TERM"<<std::endl;
    } else if(tempet == END_SEM) {
        std::cout<<"Exam Type: END_SEM"<<std::endl;
    }
    std::cout<<"Exam Code: "<<getExamCode()<<std::endl;
    std::cout<<"Exam Duration: "<<getExamDuration()<<std::endl;
    if(tempett == CPP) {
        std::cout<<"Exam Topic: CPP"<<std::endl;
    } else if(tempett == DS) {
        std::cout<<"Exam Topic: DS"<<std::endl; 
    } else if(tempett == JAVA) {
        std::cout<<"Exam Topic: JAVA"<<std::endl;
    }
}

void OfflineExam::accept() {
    int option;
    std::string temps;
    std::cout<<"\nSelect an option for Exam Type\n";
    std::cout<<"1->UNIT TEST\n2->MID TERM\n3->END SEM"<<std::endl;
    std::cin>>option;
    if(option == 1) {
        setExamType(UNIT_TEST);
    } else if(option == 2) {
        setExamType(MID_TERM);
    } else if(option == 3) {
        setExamType(END_SEM);
    }

    std::cout<<"Enter the exam code: ";
    std::cin>>temps;
    setExamCode(temps);

    std::cout<<"Enter the time duration of the exam (in minutes): ";
    std::cin>>option;
    setExamDuration(option);

    std::cout<<"Select one of the below options for Exam Topic: \n";
    std::cout<<"1->CPP\n2->DS\n3->JAVA"<<std::endl;
    std::cin>>option;

    if(option == 1) {
        setExamTopic(CPP);
    } else if(option == 2) {
        setExamTopic(DS);
    } else if(option == 3) {
        setExamTopic(JAVA);
    }
}

void OfflineExam::changeLocation(std::string newLocation) {
    this->examLocation = newLocation;
}