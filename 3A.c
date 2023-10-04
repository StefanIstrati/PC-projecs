#include<stdio.h>
#include<math.h>
int main()
{
    char s[2], t[2];
    scanf("%c %c",&s[1], &s[2]);
    scanf("%c %c",&t[1], &t[2]);
    while((s[1]!=t[1])&&(s[2]!=t[2]))
    {
        if ((s[1]<t[1])&&(s[2]<t[2]))
        {
            printf("RU");
            s[1]=s[1]+1;
            s[2]=s[2]+1;
        }
        if ((s[1]<t[1])&&(s[2]>t[2]))
        {
            printf("LU");
            s[1]=s[1]-1;
            s[2]=s[2]+1;
        }
        if ((s[1]>t[1])&&(s[2]<t[2]))
        {
            printf("RD");
            s[1]=s[1]+1;
            s[2]=s[2]-1;
        }
        if ((s[1]>t[1])&&(s[2]>t[2]))
        {
            printf("LD");
            s[1]=s[1]-1;
            s[2]=s[2]-1;
        }
        if ((s[1]<t[1])&&(s[2]==t[2]))
        {
            printf("L");
             s[1]=s[1]-1;
        }
        if ((s[1]>t[1])&&(s[2]==t[2]))
        {
            printf("R");
             s[1]=s[1]+1;
        }
        if ((s[1]==t[1])&&(s[2]<t[2]))
        {
            printf("U");
             s[2]=s[2]+1;
        }
        if ((s[1]==t[1])&&(s[2]>t[2]))
        {
            printf("D");
             s[2]=s[2]-1;
        }
    }
    return 0;
}