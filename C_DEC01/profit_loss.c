#include<stdio.h>
int main()
{
    int selling_price,cost_price,amount;
    printf("enter cost price: ");
    scanf("%d",&cost_price);
    printf("enter selling price: ");
    scanf("%d",&selling_price);
    if(selling_price>cost_price)
    {
        amount=selling_price-cost_price;
        printf("prifit = %d",amount);
    }
    else if(cost_price>selling_price)
    {
        amount=cost_price-selling_price;
        printf("loss = %d",amount);
    }
    else
    {
        printf("no profit no loss");
    }
    return 0;
}