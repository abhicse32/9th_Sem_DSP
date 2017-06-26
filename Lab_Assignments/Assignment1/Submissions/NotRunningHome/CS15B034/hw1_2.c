//Homework Assignment 1.2 by Raghavan S CS15B034: conversion of user input decimal to hexadecimal
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*a function taking integer input<16 and returns a character hexadecimal digit
*/
char conv(int i)
{
  char c;
  if(i<10)
  c=48+i;
  else
  c=87+i;
  return c;
}
int main()
{
  int j=9;                          //counter
  int n;                            //input number
  int rem;                          //remainder
  char str[11];                     //string output
  str[0]='0';                       //initial assignment
  str[1]='x';
  for(int i=2;i<10;i++)
    str[i]='0';
  str[10]='\0';
  scanf("%d",&n);                   //scanning input
//the following loop performs division by 16 iteratively and using remainder to find the hexadecimal character
  while(n>0)
  {
    rem=n%16;
    str[j]=conv(rem);
    n=n/16;
    j--;
  }
  printf("%s",str);                 //printing the hexadecimal string
return 0;
}
