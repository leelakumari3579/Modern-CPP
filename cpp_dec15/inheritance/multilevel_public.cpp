#include<iostream>

class Base
{
    private : int x;
    public  : int y;
    protected :int z;
    public:
        void show()
        {
            /*
                x,y,z
            */
        }

};
class Der1:public Base{
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
           y=10;//yes
           z=20;//yes
        }

};
int main()
{
    Base b1;
    b1.y=30;// yes
    //b1.40;//no;

    Der1 d1;
    d1.y=40;
    //d1.z=40;

}