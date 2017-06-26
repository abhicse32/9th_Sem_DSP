#include"queue_using_stack.h"

stack *queue_new()
{
        return stack_new() ;
}

//Check empty
bool queue_is_empty(stack *S)
{
        return stack_is_empty(S) ;
}

//Return size
int queue_size(stack *S)
{       
        return stack_size(S) ;
}

//Print queue
void queue_print(stack *S)
{
        stack_print(S) ;
}

//For simulating enqueue(insertion at last
//If empty push element 
//Else 1)Pop recursively 2)Push
void enqueue(stack *S,int element)
{
        if(stack_is_empty(S) == true)
        {
                stack_push(S,element) ;
        }
        else
        {
                int x = stack_pop(S) ;
                enqueue(S,element) ;
                stack_push(S,x);
        }
}

//Dequeue = Pop
int dequeue(stack *S)
{
        return stack_pop(S) ;
}
