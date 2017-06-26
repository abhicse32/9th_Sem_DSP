//converting a infix expression to postfix expression by Raghavan S CS15B034 Lab Assignment 5
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 120
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
/*the following functions whether the given character is a valid listed operator
*/
int checkop(char a)
{
  if(a==37||a==38||a==42||a==43||a==45||a==47||a==94||a==124)
  return 1;
  else
  return 0;
}
/*
the following functions takes a string expression and index t and returns 1 if
the expression is valid near t
*/
int check(char *a,int t)
{
  int ret=1;
  if(a[t]=='\0')
    return 1;
  else if(a[t]==32)
    return 2;
  else if(!isalnum(a[t])&&a[t]!=42&&a[t]!=41&&a[t]!=40&&a[t]!=43&&a[t]!=45&&a[t]!=47&&a[t]!=37&&a[t]!=38&&a[t]!=94&&a[t]!=124)
    return 0;
  else if(a[t]=='-'&&isalnum(a[t+1])&&(t==0||a[t-1]==' '))
    return 3;
  return ret;
}
/*the following function takes 2 characters c1,c2 as arguments and returns 1 if
c1 is of equal or higher precedence than c2 in which case it is popped
*/
int prec(char c1,char c2)
{
  if(c1=='(')
    return 0;
  switch(c2)
  {
    case '%':
    case '*':
    case '/': if(c1=='%'||c1=='*'||c1=='/')
              return 1;
              else
              return 0;
    case '+':
    case '-': if(c1=='+'||c1=='-'||c1=='%'||c1=='*'||c1=='/')
              return 1;
              else
              return 0;
    case '&': if(c1!='|'&&c1!='^')
              return 1;
              else
              return 0;
    case '^': if(c1!='|')
              return 1;
              else
              return 0;
    case '|': return 1;
  }
}
int main()
{
  stack *s;
  char ch,ch2;
  char *in;
  char *pos;
  int flag;
  int p,t,i;
  char cs[20];
  int j;
  pos=(char *)malloc(max);
  in=(char *)malloc(max);
while(fgets(in,120,stdin))
{
  s=stack_new();
  flag=1;
  i=strlen(in);
  in[i-1]='\0';
  i=0;
  t=0;
  j=-1;
  do
  {
    ch=in[t++];
    if(!check(in,t-1))
    {
        printf("incorrect expression!!\n");
        flag=0;
        break;
    }
    else if(check(in,t-1)==3||isalnum(ch))
    {
        pos[i++]=ch;
        j++;
        continue;
    }
    else if(check(in,t-1)==2)
    {
      if(j!=-1)
      {
        pos[i++]=ch;
      }
      j=-1;
      continue;
    }
    if(ch=='\0')
      break;
    else if(ch==40)
      stack_push(s,ch);
    else if(ch==41)
    {
      do
      {
        if(stack_is_empty(s))
        {
            printf("incorrect expression!!\n");
            flag=0;
            break;
        }
        ch2=stack_pop(s);
        if(ch2!=40)
        {
          pos[i++]=ch2;
          pos[i++]=' ';
        }
      } while(ch2!=40);
    }
    else
    {
      if(stack_is_empty(s))
      {
        stack_push(s,ch);
        continue;
      }
      ch2=s->top->head->data;
      if(ch2==40)
      stack_push(s,ch);
      else
      {
        while(prec(ch2,ch))
        {
          ch2=stack_pop(s);
          pos[i++]=ch2;
          pos[i++]=' ';
          if(stack_is_empty(s))
            break;
          ch2=s->top->head->data;
        }
        stack_push(s,ch);
      }
    }
  } while(flag);
  if(!flag)
  {
      continue;
  }
  if(j!=-1)
  pos[i++]=' ';
  while(!stack_is_empty(s))
  {
    ch=stack_pop(s);
    if(ch==40)
    {
      printf("incorrect expression!!\n");
      flag=0;
      break;
    }
    else
    pos[i++]=ch;
    pos[i++]=' ';
  }
  if(!flag)
  {
      continue;
  }
  pos[i]='\0';
  fputs(pos,stdout);
  printf("\n");
  free(s);
  }
  return 0;
}
