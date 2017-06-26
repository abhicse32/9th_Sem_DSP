//CS15B013 SQUAREROOT

#include<stdio.h>


 int main()
 {
 float i,j;
 float num;
 j=0.0001;


 printf("ENTER ANY NUMBER : ");
 scanf("%f",&num);

 for(i=0;i<num;i=i+j)
 {
  if((i*i)>num)
  {
   i=i-j;
   break;
  }
 }
 printf("%.15f",i);

 return 1;
 }
