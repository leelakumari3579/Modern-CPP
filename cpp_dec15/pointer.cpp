int main()
{
    int a=0;
    const int *p=&a; //non constant pointer to constant integer
    int b=20;
    p=&b;
    //*p=20;//error

    //int a=10;
    // int *const p=&a;//const pointer to non constant integer
    //int b=20;
    //p=&b; //error
    //*p=10; //error

    int a=10,b=20;
    //const int* const p=&a;//constant pointer to const ineger
    //p=&b; //error
    //*p=20; //error

}