#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    printf("enter name:\n");
    string s=get_string();
    printf("%c", toupper(s[0]));
    for(int i=0;i<strlen(s);++i)
    {
        if(s[i]==' ')
        {
          printf("%c", toupper(s[i+1]));
        }
    }

    printf("\n");
}
