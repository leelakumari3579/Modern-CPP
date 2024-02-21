#include <iostream>
#include "Exam.h"
#include "OnlineExam.h"
#include "OfflineExam.h"

int main() {
    int numberOfOnlineExams, numberOfOfflineExams;
    std::cout<<"Enter the number of online exam objects to be created: ";
    std::cin>>numberOfOnlineExams;

    std::cout<<"Enter the number of offline exam objects to be created: ";
    std::cin>>numberOfOfflineExams;

    OnlineExam onlineExams[numberOfOnlineExams];
    OfflineExam offlineExams[numberOfOfflineExams];

    std::cout<<"Enter the details for online exams: \n";

    for(int i=0; i<numberOfOnlineExams; i++) {
        onlineExams[i].accept();
    }

    std::cout<<"Enter the details for offline exams: \n";

    for(int i=0; i<numberOfOfflineExams; i++) {
        offlineExams[i].accept();
    }

    for(int i=0; i<numberOfOnlineExams; i++) {
        onlineExams[i].display();
    }

    std::cout<<"------------------------------------"<<std::endl;

    for(int i=0; i<numberOfOfflineExams; i++) {
        offlineExams[i].display();
    }


}