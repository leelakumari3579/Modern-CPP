#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<cstring>
class student
{
private:
    int id;
    char name[20];
    int marks[3];
    
public:
    student(int,const char*,int*);
    student();
    ~student();
    
    int getId() const { return id; }
    void setId(int id_) { id = id_; }

    char *getName() { return name; }
    void setName(char *name_) { strcpy(name,name_); }

    int *getMarks() { return marks; }
    void setMarks(int *marks_)
    {
        for(int i=0;i<3;i++)
        {
            marks[i]=marks_[i];
        }
    }
    void display()const;
    float avg();
};

#endif