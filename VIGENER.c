#include<cs50.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

int main(int arg, string args[])
{

    if(arg!=2)
    {
        printf("invalid arguments\n");
        return 1;
    }
    else
    {
        printf("enter plaintext:\n");
        string s=get_string();
        int g=0;
        for(int i=0;i<strlen(s);++i)
        {
            g = g % strlen(args[1]);
            if(isalpha(args[1][g])==0)
            {
            printf("invalid arguments");
            return 1;
            }
            else
            {
                if(s[i]==' ')
                continue;
                else
                {
                if(isupper(s[i]) && isupper(args[1][g]))
                printf("%c", (((s[i]-65)+(args[1][g]-65))%26)+65);
                else if(islower(s[i]) && islower(args[1][g]))
                printf("%c", (((s[i]-97)+(args[1][g]-97))%26)+97);
                else if(isupper(s[i]) && islower(args[1][g]))
                printf("%c", (((s[i]-65)+(args[1][g]-97))%26)+65);
                else if(islower(s[i]) && islower(args[1][g]))
                printf("%c", (((s[i]-97)+(args[1][g]-65))%26)+97);
                               }
                               ++g;
            }
        }

    }
    printf("\n");
}
