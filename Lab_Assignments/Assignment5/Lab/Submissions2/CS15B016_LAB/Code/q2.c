/*PROGRAM TO FID NEXT MAX OF EACH NUMBER IN THE ARRAY
AUTHOR: GIRIDHAR S 
ROLL NUMBER: CS15B016
DATE 16 SEPT*/

#include<stdio.h>
#include "List.h"
#include "stack.h"
#include "List.c"
#include "stack.c"
#include<string.h>
#include<stdlib.h>

#define SIZE 1000

//First, using similar stack as used in question 1, all the complete braces, are valid braces, which form a substring of the input array are 
//removed. So the removing array must have the form }}}}}}}.....{{{{{{. else, More complete braces can be removed. Now depending on the number of }
//and { it is easy to compute the minimum number of flips.

int main(){
  char brackets[SIZE];
  stack *temp;
  temp=stack_new();
  int test,count;
  char x;
  scanf("%d",&test);
  while(test--){

    temp=stack_new();
    // printf("w");
    scanf("%s",brackets);
    //printf("x");
    int len=strlen(brackets);
    int i=0;
    char top;
    while(i<len){
      //printf("y");
      switch(brackets[i]){
      case '{':
	stack_push(temp, brackets[i]);
	break;

      case '}': if(stack_is_empty(temp))
	  {stack_push(temp, brackets[i]);}
	else{
	  top=stack_pop(temp);
	  if(top!='{'){
	    stack_push(temp,top);
	    stack_push(temp, brackets[i]);
	  }
	}
	break;
      }
      //stack_print(temp);
      //printf("\n");
      i++;
    }
    //stack_print(temp);
    count=0;
    int stacklen=stack_size(temp);
    int hs=stacklen/2;
    //printf("%d...%d",stacklen,hs);
    if(stacklen==0){
      printf("0\n");
      
    }
    
    else if(stacklen%2==1)
      {printf("%d\n",-1);}
    
    else{
      x=stack_pop(temp);
      while(x!='}'){
	//printf("z");
	//printf("...%d\n",x);
	count++;
	if(stack_is_empty(temp))
	  break;
	x=stack_pop(temp);
      }
      //if(stack_is_empty(temp))
	//	count++;
      // printf("!!%d!!",count);
      if(count%2==0){
	printf("%d\n",hs);
      }
      else{
	printf("%d\n",(hs+1));
      }
    }
    
      
  }
}
