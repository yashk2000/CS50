#include<cs50.h>
#include<stdio.h>

int main(void)
{
    printf("enter number of lines:");
    int lines=get_int();
    int c=2;
    for(int i=1;i<=lines;++i)
    {
        for(int j=lines+1;j>=1;--j)
        {
            if(j>c)
            {
                printf(" ");
            }
            else
            printf("#");

        }
        ++c;
        printf("\n");

    }
}
