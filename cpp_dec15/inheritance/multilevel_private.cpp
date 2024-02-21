#include<iostream>
class Base
{
    private :int x;    public:int y;    protected :int z;
    public:
        void show()
        {
            /*
                x,y,z
            */
        }

};
class Der1:private Base{

    //private int y,z;
 public:
        void show()
        {
            //x=10;//no
            y=10;//yes
            z=20;//yes
        }


};
class Der2:public Der1{

 public:
        void show()
        {
           //x=10; no
          // y=10;//no
           //z=20;//no
        }

};
int main()
{
    Base b1;
    b1.y=30;// yes
    //b1.40;//no;

    Der1 dr1;
    //dr1.y=30;//no

}