/* KOMMURU ALEKHYA REDDY 
        CS15B059
        30AUG2016
        OPEARTIONS ON QUEUE USING A LINKED LIST 
*/ 
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

//to create a new queue
queue* queue_new()
{
        queue * que=(queue *)malloc(sizeof(queue));//allotting space using malloc
        que->front=llist_new();
        que->rear=llist_new();//making both pointer heads NULLs
        return que;
}

//adding an element to a queue
void enqueue(queue* que, int elm)
{
        Node* newnode=node_new(elm);
        if(que->front->head==NULL)//if its the first element to be added
        {
                que->front->head=newnode;
                que->rear->head=newnode;//make both front and rear point to it
        }
        else
        {
                que->rear->head->next=newnode;//point to the prev first element
                que->rear->head=newnode;//make head point to the new element
        }
}

//to return the value of the first element after dequeuing the queue
int dequeue(queue* que)
{
        int x;
        Node * temp;//temporary variable to free the node
        if((que->front->head==que->rear->head)&&(que->rear->head !=NULL))
        {
                temp=que->front->head;
                x=temp->data;
                que->front->head=NULL;
                que->rear->head=NULL;
        }
        
        else if(que->front->head!=NULL && que->front->head!=que->rear->head)
        {
                x=que->front->head->data; //get the value       
                temp=que->front->head;//get the first node
                que->front->head=temp->next;//redirect the front pointer
                free(temp);//free the node
        }
        else
                x=INT_MIN;
        return x;        
}

//to check if the queue is empty
bool queue_is_empty(queue* que)
{
        if(que->front->head==NULL && que->rear->head==NULL)
                return true;
        else
                return false;        
}


//to find the size of the queue
int queue_size(queue* que)
{
        int size=0;
        if(que->front->head == NULL && que->rear->head==NULL)
                return 0;//empty queue
        else
        {        
        size=1;
        Node * temp=que->front->head;//temporary node
        while(temp!=que->rear->head)
        {
                size++;
                temp=temp->next;//till we dont reach the rear pointer
        }  
                return size;//returns the size
        }      
}

//to print all the elements of a queue
void queue_print(queue* que)
{
        int x;
        queue* tempqueue=queue_new();       
        while(que->front->head !=NULL && que->rear->head !=NULL)
        {
                x=dequeue(que);
                printf("%d ",x);
                enqueue(tempqueue,x);   //dequeue all the elements and store them in a temporary queue                             
        }
        
        while(tempqueue->front->head !=NULL && tempqueue->rear->head !=NULL)
        {
                x=dequeue(tempqueue);
                enqueue(que,x);//store them back into the queue
        } 
}






