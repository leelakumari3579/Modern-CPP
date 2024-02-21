#ifndef OFFLINEEXAM_H
#define OFFLINEEXAM_H

#include<iostream>
#include "Exam.h"

enum ettype {
    CPP,
    DS,
    JAVA
};

class OfflineExam : public Exam {
    enum ettype examTopic;
    std::string examLocation;

    public:
        OfflineExam();
        OfflineExam(enum etype, std::string, int, enum ettype, std::string);

        void display();
        void accept();
        void changeLocation(std::string);

        enum ettype getExamTopic() const { return examTopic; }
        void setExamTopic(const enum ettype &examTopic_) { examTopic = examTopic_; }

        std::string getExamLocation() const { return examLocation; }
        void setExamLocation(const std::string &examLocation_) { examLocation = examLocation_; }
};

#endif // OFFLINEEXAM_H
