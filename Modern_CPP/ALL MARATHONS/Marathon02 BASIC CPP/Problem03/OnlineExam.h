#ifndef ONLINEEXAM_H
#define ONLINEEXAM_H

#include "Exam.h"

enum eptype {
    MEET,
    ZOOM,
    TEAMS
};


class OnlineExam : public Exam {
    enum eptype examPlatform;

    public:
        //Constructors
        OnlineExam();
        OnlineExam(enum etype, std::string, int, enum eptype);
        OnlineExam(OnlineExam &);

        // Getters and Setters.
        enum eptype getExamPlatform() const { return examPlatform; }
        void setExamPlatform(const enum eptype &examPlatform_) { examPlatform = examPlatform_; }

        // User-Defined
        void display();
        void accept();
        void averageMarks(int *);        
};

#endif // ONLINEEXAM_H
