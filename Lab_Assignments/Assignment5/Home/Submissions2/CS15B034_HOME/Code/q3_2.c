//Evaluating a postfix expression by Raghavan S CS15B034 Lab Assignment 5
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 100
/*  0-9     48-57
    a-z     97-122
    A-Z     65-90
    %       37
    &       38
    ()      40,41
    *       42
    +       43
    -       45
    /       47
    ^       94
    |       124
    <space> 32
*/
/*
the following functions takes a string expression and index t and returns 1 if
the expression is valid near t
*/
int check(char *a,int t)
{
  if(a[t]==' ')
  return 2;
  else if(a[t]=='\0')
  return 1;
  else if(isdigit(a[t+1])&&a[t]=='-')
  return 3;
  else if(!isdigit(a[t])&&a[t]!=42&&a[t]!=43&&a[t]!=45&&a[t]!=47&&a[t]!=37&&a[t]!=38&&a[t]!=94&&a[t]!=124)
  return 0;
  else return 1;
}
/*
the following function calculates x operator y value for operator c
*/
int calc(int x,int y,char c)
{
  int p=0;
  switch(c)
  {
    case '*':p=x*y; break;
    case '/':p=x/y; break;
    case '-':p=x-y; break;
    case '+':p=x+y; break;
    case '^':p=x^y; break;
    case '&':p=x&y; break;
    case '|':p=x|y; break;
    case '%':p=x%y;
  }
  return p;
}
int main()
{
  stack *s;
  char ch,ch2;
  char *in;
  char *pos;
  int p,t,i,j;
  int x,y;
  char cs[7];
  int is;
  pos=(char *)malloc(max);
  in=(char *)malloc(max);
while(fgets(in,100,stdin)!=NULL)
  {
  s=stack_new();
  i=strlen(in);
  in[i-1]='\0';
  i=-1;
  j=1;
  t=0;
  do
  {
    ch=in[t++];
    if(!check(in,t-1))
    {
        printf("incorrect expression!!");
        continue;
    }
    else if(check(in,t-1)==3)
    {
      j=-1;
      continue;
    }
    else if(check(in,t-1)==2)
    {
      if(i!=-1)
      {
        cs[i+1]='\0';
        is=atoi(cs);
        stack_push(s,is*j);
        i=-1;
        j=1;
        continue;
      }
      else
      continue;
    }
    if(ch=='\0')
    {
      if(i!=-1){
      cs[i+1]='\0';
    is=atoi(cs);
    stack_push(s,is*j);
    i=-1;
    j=1;
    }
    break;
    }
    else if(isalnum(ch))
    {
      i++;
      cs[i]=ch;
    }
    else
    {
      if(stack_size(s)<2)
      {
        printf("%d",t-1);
        printf("incorrect expression!!");
        continue;
      }
      x=stack_pop(s);
      y=stack_pop(s);
      stack_push(s,calc(y,x,ch));
    }
  } while(1);
if(stack_size(s)!=1)
  {
    printf("incorrect expression!!");
    continue;
  }
printf("%d",s->top->head->data);
printf("\n");
free(s);
}
  return 0;
}
