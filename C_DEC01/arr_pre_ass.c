#include<stdio.h>
int main()
{
    int arr[]={10,20,11,29,30,40,71,70,45};
    int size=sizeof(arr)/sizeof(arr[0]);
    int temp=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int k=0;k<size;k++)
        printf("%d ",arr[k]);
    printf("\n");
    int even=0,odd=0;
    int i=0;
    while(i<size)
    {
        if(arr[i]%2==0)
        {
            even +=1;
        }
        else
        {
            odd +=1;
        }
        i++;
    }
    printf("%d\n",even);
    printf("%d\n",odd);
    int arr1[even],arr2[odd];
    int a=0,b=0,c=0;
    while(a<size)
    {
        if(arr[a]%2==0)
        {
            arr1[b]=arr[a];
            b++;
        }
        else
        {
            arr2[c]=arr[a];
            c++;
        }
        a++;
    }
    for(int z=0;z<even;++z)
    {
        printf("%d ",arr1[z]);
    }
    printf("\n");
    for(int z=0;z<odd;++z)
    {
        printf("%d ",arr2[z]);
    }
    printf("\n");
    int z=0,x=0,y=0;
    while(x<even && y<odd)
    {
        arr[z]=arr1[x];
        z++;
        arr[z]=arr2[y];
        z++;
        x++;
        y++;
    }
    while(x<even);
    {
        arr[z]=arr1[x];
        x++;
        z++;
    }
    while(y<odd);
    {
        arr[z]=arr2[y];
        y++;
        z++;
    }
    for(int k=0;k<size;k++)
        printf("%d ",arr[k]);
}