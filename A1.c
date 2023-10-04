#include<math.h>
#include<stdio.h>
int main()
{
    double n,m,a;
    double  d,b,c;
    scanf("%lf %lf %lf",&n,&m,&a);
    if (((n/a)-(int)(n/a))==0)
    {
    b = (int)(n/a);
    }
    else 
    {
    b = (int)(n/a)+1;   
    }
    if (((m/a)-(int)(m/a))==0)
    {
    c = (int)(m/a);
    }
    else 
    {
    c = (int)(m/a)+1;   
    }
    d = b*c;
    printf("%0.lf ", d);
    return 0;
}