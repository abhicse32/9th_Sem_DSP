#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
stack* stack_new()
{
   stack*ps=(stack*)malloc(sizeof(stack));
   ps->arr=(int*)malloc(1000*sizeof(int));
   ps->top=-1;
   return ps;
}
void stack_push(stack*ps, int data)
{
   (ps->top)++;
   ps->arr[ps->top]=data;
}
int stack_pop(stack*ps)
{
   if(ps->top==-1) return 0;
   int x=ps->arr[ps->top];
   (ps->top)--;
   return x;
}
bool stack_is_empty(stack*ps)
{
   if(ps->top==-1) return 1;
   else return 0;
}
bool stack_is_full(stack*ps)
{
   if(ps->top==size-1) return 1;
   else return 0;
}
int stack_size(stack*ps)
{
    int c=0;
    if(stack_is_empty(ps)==1) return 0;
    stack *t=stack_new();
    while(stack_is_empty(ps)!=1)
    {
        c++;
        stack_push(t,stack_pop(ps));
    }
    while(stack_is_empty(t)!=1)
    {
        stack_push(ps,stack_pop(t));
    }
    return c;
}
void stack_print(stack *ps)
{
    stack *t=stack_new();
    while(stack_is_empty(ps)!=1)
    {
        int x=stack_pop(ps);
        printf("%d ",x);
        stack_push(t,x);
    }
    while(stack_is_empty(t)!=1)
    {
        stack_push(ps,stack_pop(t));
    }
}
/*int main()
{
    int n;
    scanf("%d",&n);
    stack*ps=stack_new();
    printf("akhil\n");
    int i,x;
    for(i=0;i<n;i++)
    {
       scanf("%d",&x);
       stack_push(ps,x);
    }
    stack_print(ps);
    printf("%d\n",stack_size(ps));
}*/
