#include<stdio.h>

void main()
{ int n;
  scanf("%d",&n);
  int array[100];
  int i = 0, min, max =0;
 
 for(i=0; i<n; i++)
  { 
    scanf("%d",&array[i]);
  }
 
 min = array[0];
 for(i=0; i<n; i++)
  { 
    if(max<array[i])max = array[i];
    if(min>array[i])min = array[i];
  }

 printf("%d %d", max, min);
}
