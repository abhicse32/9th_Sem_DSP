#include "List.h"
#include "List.c" 
#include "stack.h" 
#include "stack.c" 

#include <stdio.h>

void main()
{
	int choice;

	stack *s = stack_new();
	stack *temps = stack_new();
	int ele, size;

	printf("Press -1 to exit, 1 to enqueue, 2 to dequeue, 3 to get size, 4 to print queue : ");
	scanf("%d", &choice);
	while(choice != -1)
	{
		switch(choice)
		{
			case 1: scanf("%d", &ele);
					
					while(!stack_is_empty(s))
					{
						push(temps, pop(s));
					}
					push(s, ele)
					while(!stack_is_empty(temps))
					{
						push(s, pop(temps));
					}
					break;
				
			case 2:	ele = pop(s);
					printf("%d dequeued\n", ele);
					break;

			case 3: size = stack_size(s);
					printf("Size : %d\n", size);
					break;

			case 4: stack_print(s);
					printf("\n");
					break;

			case -1: break;
			default : printf("Invalid Choice");
					  break;
		}

		printf("Press -1 to exit, 1 to enqueue, 2 to dequeue, 3 to get size, 4 to print queue : ");
		scanf("%d", &choice);

	}	
}