#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char *argv[])
{
    if(argc==2)
    {
        printf("plaintext:");
        string s=get_string();

        printf("ciphertext:");
        int k=atoi(argv[1]);
        for(int i=0;i<strlen(s);++i)
        {
            if(s[i]>='A' && s[i]<='Z')
               printf("%c", (65 + (s[i]+k-65)%26));
            else if(s[i]>='a' && s[i]<='z')
               printf("%c", (97 + (s[i]+k-97)%26));
            else
            printf("%c", s[i]);
        }
        printf("\n");
        return 0;
    }
    else
    {
    printf("no valid arguments\n");
    return 1;
}
}
