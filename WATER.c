#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("enter number if minutes spent in shower:\n");
    int minutes = get_int();
    printf("Minutes:%i\n", minutes);
    printf("Bottles:%i\n",(minutes*12));
}
