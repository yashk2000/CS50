#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int c=1;
    int height=0;
    printf("enter positive number upto 23:");
    do
    {
     height=get_int();
     if(height>=0 && height<=23)
     break;
    }while(height<0 || height>23);
    for(int i=1;i<=height;++i)
    {
        for(int j=height+1;j>=1;--j)
        {
            if(j>c)
            printf(" ");
            else
            printf("#");
        }
        printf(" ");
        for(int k=1;k<=c;++k)
            printf("#");
        printf("\n");
        ++c;
    }
}
