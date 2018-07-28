#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int sum=0;
    printf("enter change:");
    float ch=get_float();
    do
    {
        if(ch<0)
        ch=get_float();
        else
        break;
    }while(ch<0);
    ch=ch*100;
    int temp=ch;
    int r=temp/25;
    sum+=r;
    temp=temp - (r*25);
    r=temp/10;
    sum+=r;
    temp= temp - (r*10);
    r=temp/5;
    sum+=r;
    temp= temp - (r*5);
    r=temp/1;
    sum+=r;
    printf("the coins in change are %i\n", sum);
    }
