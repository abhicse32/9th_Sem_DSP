#include<stdio.h>
/*
  To find the square root of a number
*/
int main()
{
  double n;
  scanf("%lf",&n);           //Taking the number as input
  int i;
  double low = 1;
  double high = n;
  double avg;
  for(i=0;i<100;i++)         //Iterating many times so as to increase accuracy
  {
    avg = (low + high)/2;
    if((avg*avg)>n)
      high = avg;
    else if((avg*avg)<n)
      low = avg;
    else
      break;
  }
  printf("%.15lf",avg);      //Printing the output
  return 0;
}
      
