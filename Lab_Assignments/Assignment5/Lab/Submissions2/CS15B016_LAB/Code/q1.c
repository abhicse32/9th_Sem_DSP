/*PROGRAM TO FID NEXT MAX OF EACH NUMBER IN THE ARRAY
AUTHOR: GIRIDHAR S 
ROLL NUMBER: CS15B016
DATE 16 SEPT*/

#include<stdio.h>
#include "List1.h"
#include "stack1.h"
#include "List1.c"
#include "stack1.c"
#include<string.h>
#include<stdlib.h>

//stack used to check the brackets input
//if the next in line at each instant closes the top of the stack, or opens a new brace; and if at the end the resultant stack is empty, then the
//sequence is valid.

int main(){
  char brackets[1000];
  stack *temp;
  temp=stack_new();
  int test,flag=1;
  scanf("%d",&test);
  while(test--){
    //  printf("o");
    temp=stack_new();
    flag=1;
    scanf("%s",brackets);
    int len=strlen(brackets);
    int i=0;
    char top;
    while(i<len&&flag){
      switch(brackets[i]){
      case '{':
      case '(':
      case '[': stack_push(temp, brackets[i]);
	break;

      case '}': if(stack_is_empty(temp))
	flag=0;
	else{
	  top=stack_pop(temp);
	  if(top!='{'){
	    flag=0;
	  }
	}
	break;

      case ')': if(stack_is_empty(temp))
	flag=0;
	else{
	  top=stack_pop(temp);
	  if(top!='('){
	    flag=0;
	  }
	}
	break;

      case ']': if(stack_is_empty(temp))
	flag=0;
	else{
	  top=stack_pop(temp);
	  if(top!='['){
	    flag=0;
	  }
	}
	break;
      }

      
      i++;
    }

    if(!stack_is_empty(temp))
      flag=0;
    
    printf("%d\n", flag);
  }
}
