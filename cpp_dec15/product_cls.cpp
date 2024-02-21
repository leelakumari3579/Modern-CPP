#include<iostream>
#include<cstring>

class Product
{
    int procode;
    char *name;
    public:
        Product()
        {
            procode=1111;
            name=new char[10];
            strcpy(name,"laptop");
        }
        void show()
        {
            std::cout<<name;
        }
        ~Product()
        {  std::cout<<"\n ~Product() called ";
            delete []name;//avoid memory leakage
        }
        Product(int pcode,const char *nm)
        {
            procode=pcode;
            name= new char[strlen(nm)+1];
            strcpy(name,nm);
        }
        Product(Product &p)// copy ctor - avoid dangling pointer 
        {
            //this pointer points to p3
            procode = p.procode;
            name = new char[strlen(p.name)+1];
            strcpy(name,p.name);            
            name = p.name;
        }
};

void f1(Product &p4)// photo copy
{
    p4.show();
}

class Student
{
    int rollno;
    public :int  *m;
    public:
        Student()
        {
            rollno=1;
            m=new int[2];
            m[0]=0;
            m[1]=0;
        }
        Student(int r,int n,int mk[])
        {
            rollno=r;
            m=new int[n];
            for(int i=0;i<n;i++)
            {
                m[i]=mk[i];
            }
        }
        ~Student()
        {
            std::cout<<"\n ~Student() called ";
            delete [] m;
        }
};
int main()
{
    //Product p1;
    //p1.show();
    Product p2(555,"Television");
    Product p3(p2);

    Product *p=new Product[20];
    delete []p; //memory leakge / request to call destructor

    Product *p=new Product;
    delete p; //memory leakge / request to call destructor

    // p2.show();
    // f1(p2);

    // Student s1;

    // Student *s2=new Student();  
    // delete s2;
}
