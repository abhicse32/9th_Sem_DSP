#include <stdio.h>
#include "List.c"
#include "bu_suq.c"
#include "List.h"
#include "bu_suq.h"

int main(){
	queue *s;
	int x;
	s=queue_new();
	//stack_push(s, 1);
/*	printf("x");
	printf("t");
	printf("y");
	printf("xe");
	printf("\n%dq",(-8912)/(-12));*/

//	enqueue(s,6);
//	if(stack_is_empty(s))
//		printf("yes");
	int option=1;
	do{
		scanf("%d",&option);
		switch(option){
			case 1: scanf("%d", &x); stack_push(s, x); stack_print(s); break;
			case 2: printf("%d\n", stack_pop(s)); break;
			case 4: printf("%d\n", stack_size(s)); break;
			case 3: printf("%d\n", stack_is_empty(s)); break; 
			case 5: queue_print(s); break;
			case 0: break;
			default: break;

		}
	}while(option);

}



