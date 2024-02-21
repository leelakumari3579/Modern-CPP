#include "OnlineExam.h"

OnlineExam::OnlineExam(): Exam(), examPlatform(MEET) {}

OnlineExam::OnlineExam(etype examType, std::string examCode, int timeDuration, eptype examPlatform):
Exam(examType,examCode, timeDuration), examPlatform{examPlatform} {}

OnlineExam::OnlineExam(OnlineExam &oe): Exam(oe.getExamType(), oe.getExamCode(), oe.getExamDuration()) {
    this->examPlatform = oe.examPlatform;
}

void OnlineExam::display() {
    enum etype tempet = getExamType();
    enum eptype tempep = getExamPlatform();
    if(tempet == UNIT_TEST) {
        std::cout<<"Exam Type: UNIT_TEST"<<std::endl;
    } else if(tempet == MID_TERM) {
        std::cout<<"Exam Type: MID_TERM"<<std::endl;
    } else if(tempet == END_SEM) {
        std::cout<<"Exam Type: END_SEM"<<std::endl;
    }
    std::cout<<"Exam Code: "<<getExamCode()<<std::endl;
    std::cout<<"Exam Duration: "<<getExamDuration()<<std::endl;
    if(tempep == MEET) {
        std::cout<<"Exam Platform: MEET"<<std::endl;
    } else if(tempep == TEAMS) {
        std::cout<<"Exam Platform: TEAMS"<<std::endl; 
    } else if(tempep == ZOOM) {
        std::cout<<"Exam Platform: ZOOM"<<std::endl;
    }
}

void OnlineExam::accept() {
    int option;
    std::string temps;

    std::cout<<"Enter the exam code: " << std::endl;
    std::cin>>temps;
    setExamCode(temps);

    std::cout<<"Enter the time duration of the exam (in minutes): ";
    std::cin>>option;
    setExamDuration(option);

    std::cout<<"\nSelect an option for Exam Type"<<std::endl;
    std::cout<<"1->UNIT TEST\n2->MID TERM\n3->END SEM"<<std::endl;
    std::cin>>option;
    if(option == 1) {
        setExamType(UNIT_TEST);
    } else if(option == 2) {
        setExamType(MID_TERM);
    } else if(option == 3) {
        setExamType(END_SEM);
    }

    std::cout<<"Select one of the below options for Exam Platform: \n";
    std::cout<<"1->MEET\n2->TEAMS\n3->ZOOM"<<std::endl;
    std::cin>>option;

    if(option == 1) {
        setExamPlatform(MEET);
    } else if(option == 2) {
        setExamPlatform(TEAMS);
    } else if(option == 3) {
        setExamPlatform(ZOOM);
    }

    std::cout<<"\nRecord Added Successfully!!\n";
}

void OnlineExam::averageMarks(int *p) {
    float sum;
    for(int i=0; i<5; i++) {
        sum += p[i];
    }
    std::cout<<"Average marks of the student is: "<<(sum/5.0f)<<std::endl;
}