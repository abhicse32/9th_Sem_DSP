#include <stdio.h>

#define DIF 0.00000000001

double absolute (double);
double test (double, double);



int main (void)
{
int i;

double num, x;

scanf("%lf", &num);

x = num / 2;

for (i = 0;(absolute(test(num , x*x)) > DIF)||i<52; i++)

{

x = x - (x*x - num)/(2*x);

    
}
printf("%0.15lf\n", x);

return 0;

}



double absolute (double x)

{

if(x < 0)

x = -x;

return x;

}



double test (double num, double y)

{

double x;

x = num - y;

return x;

}
