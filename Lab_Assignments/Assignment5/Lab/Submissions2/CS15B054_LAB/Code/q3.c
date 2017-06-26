#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "List.c"
#include "stack.h"
#include "stack.c"
int main()
{
   int T,i;
   scanf("%d",&T);
   for(i=0;i<T;i++)  // going into loop for T test cases
   {
       int N,j,k;
       scanf("%d",&N);
       int A[N];
       for(k=0;k<N;k++)
       {
           scanf("%d",&A[k]);
       }
       stack* st = stack_new();  // creating new stack in each loop
       stack_push(st,-1);
       for(j = N-2;j >= 0;j--)  // for array with N>=2
       {
            if(A[j+1] > A[j]) stack_push(st,A[j+1]);  // comparing adjacent elements in array
            else
            {
                Node* n;
                n = st->top->head;
                for(;n->data != -1;n = n->next)   //pushing the required elements into stack
                {
                    if(n->data > A[j])
                    {
                        stack_push(st,n->data);
                        break;
                    }
                }
                if(n->data == -1) stack_push(st,-1);
            }
       }
       stack_print(st);
    }
    return 0;
}                     
