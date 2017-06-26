#include"stack_using_queue.h"


queue *stack_new()
{
        return queue_new() ;
}

//Reverse Q with recursion
//1)deQ & store 2)Recursive call 3)enQ
void reverse_Q(queue *Q)
{
        if(queue_is_empty(Q) == false)
        {
                int x = dequeue(Q) ;
                reverse_Q(Q) ;
                enqueue(Q,x) ;
        }        
}

//Check empty
bool stack_is_empty(queue *Q)
{
        return queue_is_empty(Q) ;
}

//For simulating push(insertion at front)
//1)reverse 2)enQ 3)Reverse 
void *stack_push(queue *Q,int element)
{                
        reverse_Q(Q);
        enqueue(Q,element);                
        reverse_Q(Q);
}

//Pop = Dequeue
int stack_pop(queue *Q)
{
        return dequeue(Q) ;
}


int stack_size(queue *Q)
{
        return queue_size(Q) ;
}

void stack_print(queue *Q)
{
        queue_print(Q) ;                
}

