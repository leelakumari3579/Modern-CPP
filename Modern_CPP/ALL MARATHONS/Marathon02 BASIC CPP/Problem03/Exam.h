#ifndef EXAM_H
#define EXAM_H

#include <iostream>

enum etype {
    UNIT_TEST,
    MID_TERM,
    END_SEM
};

class Exam {
    enum etype examType;
    std::string examCode;
    int examDuration;

    public:
        Exam();
        Exam(enum etype, std::string, int);

        // Getters and Setters
        enum etype getExamType() const { return examType; }
        void setExamType(const enum etype &examType_) { examType = examType_; }

        std::string getExamCode() const { return examCode; }
        void setExamCode(const std::string examCode_) { examCode = examCode_; }

        int getExamDuration() const { return examDuration; }
        void setExamDuration(int examDuration_) { examDuration = examDuration_; }   

        virtual void display()=0;
};

#endif // EXAM_H
