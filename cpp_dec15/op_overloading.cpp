#include<iostream>

class Point
{
    int x,y;
    public:
        Point(){x=y=0;}
        Point(int x1,int y1){x=x1;y=y1;}
        void display()
        {
            std::cout<<"x= "<<x<<std::endl;
            std::cout<<"y= "<<y<<std::endl;
        }
        Point operator+(Point &p2)
        {
            Point sumobj;
            sumobj.x=this->x+p2.x;
            sumobj.y=this->y+p2.y;
            return sumobj;
        }
        Point operator-(Point &p1)
        {
            Point subobj;
            subobj.x=this->x-p1.x;
            subobj.y=this->y-p1.y;
            return subobj;
        }
};
int main()
{
    Point p1(1,2),p2(3,4);
    Point p3=p1+p2; //p1.operator + (p2)
    p3.display();

    Point p4=p2-p1; //p2.operator - (p1)
    p4.display();
    
    return 0;
}