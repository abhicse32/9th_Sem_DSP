 
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
//#include"stack_using_queue.h"
#define BUFF_SIZE 20
                 void main()          //main fn to implement queue oprns just like format in prev question
                  { stack *q=stack_new();
                   stack *p=stack_new();
                    
             
                int n;
                char str[BUFF_SIZE];
	
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"enqueue")){
			int data=atoi(strtok(NULL," "));
			
                        p=enqueue(q,data);
                        stack_print(p);
                         q=revstk(p);

		}else if(!strcmp(temp,"size"))
			printf("%d",stack_size(q));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",stack_is_empty(q));
		else if(!strcmp(temp,"dequeue"))
			{//printf("%d", dequeue(que));
			if(!stack_is_empty(q))
			{p=dequeue(q);
                        //stack_print(p);
                        int pp=fpp();
                        printf("%d",pp);
                        q=revstk(p);}
                        else
                        printf("-1");
			}
		printf("\n");
	}
                
                
                
                
                
                
                } 
           
