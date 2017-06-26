/*PROGRAM FINDS THE COMMON PRIME FACTORS OF TWO NUMBERS.
DATE: 14TH AUGUST 2016
AUTHOR: GIRIDHAR S, CS15B016*/

#include<stdio.h>
#include<math.h>


//FUNCTION COMPUTES THE GREATEST COMMON DIVISOR OF TWO NUMBERS BY RECURSIVELY EXECUTTING EUCLID'S ALGORITHM
//INPUT: the two numbers
//OUTPUT: gcd

unsigned long gcd(unsigned long x, unsigned long y){

  if(x>y)
    {
      return gcd(x-y,y);
    }
  else if(x==y)
    {
      return x;
    }
  else
    {
      return gcd(y-x,x);
    }

}



//FUNCTION TESTS WHETHER A NUMBER IS PRIME. 
//INPUT: n-integer to be tested.
//OUTPUt: RETURNS 1 IF prime, ELSE RETURNS 0.
int isprime(unsigned long n){
  if(n==1)
    {
      return 0;
    }

  unsigned long i=2;
  for(i=2;i<sqrt(n);i++){
    if (n%i==0) return 0;
  }
  return 1;
}




int main(){
  unsigned long num1, num2;           //stores the two inputs
  scanf("%lu %lu",&num1,&num2);       //reads input
  unsigned long hcf=gcd(num1,num2);  
  unsigned long i; 
  if(isprime(hcf))
    {
      printf("%lu ",hcf);
	    return 1;
    }
  for(i=2;i<sqrt(hcf);i++)
    {
      if((hcf%i==0)&&(isprime(i)))
	     { printf("%lu ",i); }
    }

}


