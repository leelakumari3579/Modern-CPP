#include <iostream>

class Shape // abstract class
{
    std::string color;

public:
    Shape()
    {
        color = "black";
    }
    Shape(std::string c)
    {
        color = c;
    }
    void fillcolor()
    {
        std::cout << "filling color " << color;
    }
    virtual void calarea()= 0;//pure virtual function
};
class Circle :public Shape
{
    double radius;
    public:
        Circle()
        {
            radius=2;
        }
        Circle(double r,std::string cl):Shape(cl)
        {
            radius=r;
        }
        void calarea()
        {
            std::cout<<"\n Area of circle = "<<3.14*radius*radius;
        }

};

int main()
{
    Shape *s = new Circle;
    s->calarea();
    s->fillcolor();

    Shape *s1=new Circle(3,"Red");
    s1->calarea();
    s1->fillcolor();

    Circle c;
    c.calarea();
}