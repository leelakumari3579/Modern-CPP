#include<iostream>

//int* ptr = NULL
void MoreMagic(int *ptr){
    std::cout<<ptr<<".......\n";
}
void Magic(int val){
    std::cout<<val*val<<"\n";
}

void Magic2(int* n1)   //-->pass reference & value & pointer
{
    std::cout<<"address "<<&n1<<std::endl;
    std::cout<<"address stored in n1 varible "<<n1<<std::endl;
    std::cout<<"before value "<<*n1<<std::endl;
    *n1=99;
    std::cout<<"after value "<<n1<<std::endl;
}

// void display()
// {
//     int n1=10;
//     int *ptr = &n1;
//     int **sptr = &ptr;

//     std::cout<<ptr<<"\n"; //0x123H
//     std::cout<<&n1<<"\n"; //0x123H
//     std::cout<<sptr<<"\n"; //0x789
//     std::cout<<&ptr<<"\n"; //0x789
//     std::cout<<*ptr<<"\n"; //access -->one(*) jump  //10
//     std::cout<<*sptr<<"\n"; //0x123H
//     std::cout<<**sptr<<"\n"; //access -->two(**) jumps  //10
//     std::cout<<&sptr<<"\n";
// }

int main()
{
    int n1=10;
    const int n2 = 20;
    // int *ptr = NULL;
    int *ptr = nullptr;  //nullptr is a literal of type std::nullptr_t   (pointer with nothing)
    Magic(10);
    Magic(n1);
    Magic(n2);
    //Magic(ptr);
    MoreMagic(0);  //implicit type convertion  -->0 to NULL 
    MoreMagic(ptr);

    //int n1=100;
    std::cout<<"main address "<<&n1<<std::endl;
    std::cout<<"value main before calling magic "<<n1<<std::endl;
    Magic2(&n1);
    std::cout<<"value main after after magic called "<<n1<<std::endl;  //value changes with pointer and reference

    // display();
}

/*

    int n1 = 0
            0x100H [0000  0000     ]
            0x101H [0000  0000     ]
            0x102H [0000  0000     ]
            0x103H [0000  0000     ]

    int* ptr = NULL
            0x100H [  0000  0000   ]
            0x101H [ 0000  0000    ]
            0x102H [ 0000  0000     ]
            0x103H [  0000  0000   ]
*/