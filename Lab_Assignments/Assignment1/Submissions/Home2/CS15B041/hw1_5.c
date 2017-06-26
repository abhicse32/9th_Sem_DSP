

#include <stdio.h>

double abso(double x)
{
if(x<0)
x=-x;
return x;
}

double square(double x)
{double guess=1;
while(abso(guess*guess-x)>= 0.00000000001)
guess=((x/guess)+guess)/2;

return guess;
}
int main(void)
{double f;
scanf("%lf",&f);
printf("%.15lf\n",square(f));
return 0;
}



