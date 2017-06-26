#include "List.h"
#include "List.c" 
#include "queue.h"
#include "queue.c" 

#include <stdio.h>

void main()
{
	int choice;	

	queue *q1 = queue_new();
	queue *q2 = queue_new();
	int queueinuse = 1;
	int ele, size;

	printf("Press -1 to exit, 1 to push, 2 to pop, 3 to get size, 4 to print stack : ");
	scanf("%d", &choice);
	while(choice != -1)
	{
		switch(choice)
		{
			case 1: scanf("%d", &ele);
					if(queueinuse == 1)
					{
						enqueue(q2, ele);
						while(!queue_is_empty(q1))
						{
							ele = dequeue(q1);
							enqueue(q2, ele);
						}
						queueinuse = 2;
					}
					else
					{
						enqueue(q1, ele);
						while(!queue_is_empty(q2))
						{
							ele = dequeue(q2);
							enqueue(q1, ele);
						}
						queueinuse = 1;
					}
					break;

			case 2:	if(queueinuse == 1)
						ele = dequeue(q1);
					else
						ele = dequeue(q2);
					printf("%d popped\n", ele);
					break;

			case 3: if(queueinuse == 1)
						size = queue_size(q1);
					else
						size = queue_size(q2);
					printf("Size : %d\n", size);
					break;

			case 4: if(queueinuse == 1)
						queue_print(q1);
					else
						queue_print(q2);
					printf("\n");
					break;

			case -1: break;
			default : printf("Invalid Choice");
					  break;
		}

		printf("Press -1 to exit, 1 to push, 2 to pop, 3 to print, 4 to get size of stack : ");
		scanf("%d", &choice);

	}	
}