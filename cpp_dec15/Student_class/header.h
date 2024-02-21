#ifndef HEADER_H
#define HEADER_H

#include<cstring>
class Student
{
    //bydefault private: -->data members /instance fields of class.
    private:
        //copy is created per object
        int rollno;
        char name[30];
        double marks;
        int sub[3];

        //static data member
        static int x; //->stored in data section  //only single copy exist
    
    public:
        //accessor methods

        Student(int,const char*,int []);
        float calAvg();
        //void search();
        void accept();
        void display()const;
        Student(); //default constructor
        Student(int,const char*,double); //perameterised constructor

        int getRollno() const { return rollno; }
        void setRollno(int rollno_) { rollno = rollno_; }

        double getMarks() const { return marks; }
        void setMarks(double marks_) { marks = marks_; }

        static void showX(); //static function cannot access non static variables/members.
        //this pointer will never passed to static function
        
};

/* Constructor function
--has same name like class name
--no return type(not even void)
--***it is called implicitly only when object is created.
--to initialize attributes/ data members.
*/

#endif // HEADER_H
