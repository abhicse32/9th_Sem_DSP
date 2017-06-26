//Program written by B.Nikhil Baba on Sept 16th,2016-Lab assignment 5
//Code written to find nextlarger element of each element in an array of elements.

#include<stdio.h>
#include"stack.h"
#include<stdlib.h>
#include"stack.c"
#include"List.h"
#include"List.c"
#include<limits.h>
//Calling all the necessary header files.

//Next larger function.
void NextLarger(int* array,int n)
 {
  stack* element = stack_new();
  stack* index   = stack_new();
  stack_push(element,array[0]);
  stack_push(index,0);
  int i,sol[n];
  for(i = 1;i < n;i++)
  { 
    int temp =array[i];//Initialising a temporary element
    if(element->top->head->data < temp)//Comparing present element with the stack.
     {
      	while(temp > element->top->head->data)
         {
          stack_pop(element);
          sol[stack_pop(index)] = temp;
          if(stack_is_empty(element) == 1)
           {
            break;//terminate if stack is empty
           }
         }
         stack_push(element,temp);//push the current element to go to next iteration
         stack_push(index,i);
    }
    else
     {
       stack_push(element,temp);
       stack_push(index,i);
     }
  }
  while(stack_is_empty(element) != 1)//Finally make all the remaining element's answers -1
  {
    sol[stack_pop(index)] = -1;
    stack_pop(element);
  }
  for(i = 0;i < n;i++)
  {
   printf("%d ",sol[i]);//Printing all the elements
  }
  printf("\n");
 }
//Mainfunction
int main()
{
 int t,i;
 scanf("%d",&t);
 for(i = 0;i < t;i++)
 {
        int n,j;
        scanf("%d",&n);
  	int array[n];
        
  	for(j = 0;j < n;j++)
        {
            
          scanf("%d",&array[j]);
	                
        }
        //Calling the function
        NextLarger(array,n);
 } 
 
 return 0;
}
 
 
 
 
 
  
