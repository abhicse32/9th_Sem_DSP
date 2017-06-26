#include<stdio.h>

void main()
{
  int n;
  scanf("%d",&n);
  double sqrt=1;

  while((sqrt*sqrt-n)>0.00000000001 || (n-sqrt*sqrt)>0.00000000001){
     sqrt=(sqrt+(n/sqrt))/2;
     }
  printf("%0.15f ",sqrt);
}  
  
  
