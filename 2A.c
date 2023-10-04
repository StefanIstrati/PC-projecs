#include<stdio.h>
#include<math.h>
int main()
{
    float w;
    scanf("%f",&w);
    if (((w/2)-(int)(w/2)==0) && (w!=2))
    {
        printf("YES");
    }
    else 
    {
        printf("No");
    }
    return 0;
}