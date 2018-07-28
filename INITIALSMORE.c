#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    printf("enter string:");
    string s=get_string();
    if(s[0]==' ')
    {
    for(int i=0;i<strlen(s);++i)
    {
        if(s[i]==' ')
        {
            if((s[i+1]>='A' && s[i+1]<='Z') || (s[i+1]>='a' && s[i+1]<='z'))
            printf("%c", toupper(s[i+1]));
        }
    }
    }
    else
    {
        printf("%c", toupper(s[0]));
        for(int i=1;i<strlen(s);++i)
    {
        if(s[i]==' ')
        {
            if((s[i+1]>='A' && s[i+1]<='Z') || (s[i+1]>='a' && s[i+1]<='z'))
            printf("%c", toupper(s[i+1]));
        }
    }
    }
    printf("\n");
}
