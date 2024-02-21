#include<stdio.h>
/*void show(int *k,int *t) //int *k=&a , int *t=&b
{
    *k=40;
    *t=70;
    //++*k;
    //++*t;
}
int* fun()
{
    int y=20;
    return &y; //-->warning returs address of local varibale
}
int main()  //calling function - a function which calls another function
*/
/*{
    int b,c,a=10;
    int arr[20];
    int *p1=arr;  //-->array itself contains address so we have not used '&' here.
    
    arr[5]={40,60,70,55}
    int *p=a
    printf("%d",*++p)-->60
    *p++ -->p points to next element
    ++*p -->40 as 41
    ++(*p) -->40 as 41
    printf("%d",(*p)++) -->(a[0])++ ->41
    //constant pointer to non constant data/element.

    int *p=&a;
    //++*p  -->directly increment the value of 'a'.
    //b=a++;
    //printf("%d %d",a,b);
    c=(*p)++;
    printf("%d %d",a,c);

}*/
/*{
    int a=10,b=20;
    show(&a,&b);
    printf("%d %d\n",a,b);

    int *p=fun();
    printf("%d",*p);
    return 0;
}*/
#define ASCII_SIZE 256 // Considering ASCII characters

char getMaxOccurringChar(char* str) 
{
    int count[ASCII_SIZE] = {0}; // Initialize an array to store character counts

    int maxCount = 0; // Initialize maximum count
    char maxChar; // Initialize character with maximum count

    // Iterate through the string to count occurrences of each character
    int i = 0;
    while (str[i] != '\0') {
        count[(int)str[i]]++;
        if (count[(int)str[i]] > maxCount) {
            maxCount = count[(int)str[i]];
            maxChar = str[i];
        }
        i++;
    }
    return maxChar;
}

int main() {
    char str[] = "Hello, World!";
    char result = getMaxOccurringChar(str);
    printf("The character '%c' occurs maximum times in the string.\n", result);
    return 0;
}
