#include<stdio.h>
int main()
{
    int start;
    printf("enter the starting point");
    scanf("%d",&start);
    int end;
    printf("enter the ending point");
    scanf("%d",&end);
    int d=0,rem=0;
    int count=0;
    for(int i=start;i<=end;i++)
    {
        int j=i;
        while(j!=0)
        {
            d=j%10;
            count +=1;
            j = j/10;
            //printf("%d ",d);
        }
    }
    int arr[count],k=0;
    for(int i=start;i<=end;i++)
    {
        int j=i;
        while(j!=0)
        {
            rem=j%10;
            arr[k]=rem;
           // printf("%d ",rem);
            //printf("%d ",arr[k]);
            j=j/10;
            k++;
        }
    }
    int x=0;
    int c0=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0;
    while(x<=count)
    {
        if(arr[x]==0)
            c0 +=1;
        else if(arr[x]==1)
            c1 +=1;
        else if(arr[x]==2)
            c2 +=1;
        else if(arr[x]==3)
            c3 +=1;
        else if(arr[x]==4)
            c4 +=1;
        else if(arr[x]==5)
            c5 +=1;
        else if(arr[x]==6)
            c6 +=1;
        else if(arr[x]==7)
            c7 +=1;
        else if(arr[x]==8)
            c8 +=1;
        else
            c9 +=1;
        x++;        
    }
    if(c0>=c1 && c0>=c2 && c0>=c3 && c0>=c4 && c0>=c5 && c0>=c6 && c0>=c7 && c0>=c8 && c0>=c9)
        printf("0 has count %d",c0);
    else if(c1>=c0 && c1>=c2 && c1>=c3 && c1>=c4 && c1>=c5 && c1>=c6 && c1>=c7 && c1>=c8 && c1>=c9)
        printf("1 has count %d",c1);
    else if(c2>=c1 && c2>=c0 && c2>=c3 && c2>=c4 && c2>=c5 && c2>=c6 && c2>=c7 && c2>=c8 && c2>=c9)
        printf("2 has count %d",c2); 
    else if(c3>=c1 && c3>=c2 && c3>=c0 && c3>=c4 && c3>=c5 && c3>=c6 && c3>=c7 && c3>=c8 && c3>=c9)
        printf("3 has count %d",c3);  
    else if(c4>=c1 && c4>=c2 && c4>=c3 && c4>=c0 && c4>=c5 && c4>=c6 && c4>=c7 && c4>=c8 && c4>=c9)
        printf("4 has count %d",c4); 
    else if(c5>=c1 && c5>=c2 && c5>=c3 && c5>=c4 && c5>=c0 && c5>=c6 && c5>=c7 && c5>=c8 && c5>=c9)
        printf("5 has count %d",c5);
    else if(c6>=c1 && c6>=c2 && c6>=c3 && c6>=c4 && c6>=c5 && c6>=c0 && c6>=c7 && c6>=c8 && c6>=c9)
        printf("6 has count %d",c6);
    else if(c7>=c1 && c7>=c2 && c7>=c3 && c7>=c4 && c7>=c5 && c7>=c6 && c7>=c0 && c7>=c8 && c7>=c9)
        printf("7 has count %d",c7);
    else if(c8>=c1 && c8>=c2 && c8>=c0 && c8>=c4 && c8>=c5 && c8>=c6 && c8>=c7 && c8>=c0 && c8>=c9)
        printf("8 has count %d",c8);
    else
        printf("9 has count %d",c9);    
}