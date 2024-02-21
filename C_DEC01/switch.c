#include<stdio.h>
int main()
{
    int ch;
    printf("enter character: ");
    scanf("%d",&ch);
    switch(ch)
    {
        default: printf("no");
                //break;
        //case 'A':printf("A"); //gives duplicate
               // break; 
        case 65:printf("65");
                break;
        case 7:printf("seven"); 
                break;
                //break;
        case 8:printf("eight");
               break;
        case 9:printf("nine");
               break;
        //default: printf("no");
        
    }
}