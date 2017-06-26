#include<stdio.h>
#include<stdlib.h>

int main(){
	 float m,n;
 float num;
 n=0.0001;  
 //printf("enter the number\n ");
 scanf("%f",&num);
 
 for(m=0;m<num;m=m+n)
 {
  if((m*m)>num)
  {
   m=m-n;         
   break;      
  }              
 }
 printf("%.15f",m);

}
