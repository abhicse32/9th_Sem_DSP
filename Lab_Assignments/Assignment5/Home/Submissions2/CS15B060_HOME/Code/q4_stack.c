#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
//#include"stack_using_queue.h"
#define BUFF_SIZE 20



void main()  // main() follows same i/o oprns like stack
                 { queue *q=queue_new();
                   queue *p=queue_new();
                    
                   int c,n;
               
                
                char str[BUFF_SIZE];
	
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			
			 p=push(q,data);
             queue_print(p);
			
			
			}
            else if(!strcmp(temp,"pop"))
			{ 
			  if(!queue_is_empty(q))
			 { p=pop(q);
             //queue_print(p);
             int pp=fpp();
             printf("%d",pp);
              reverseq(q,p);}
              else
              printf("-1");
              }
              
              else if(!strcmp(temp,"size"))
			printf("%d",queue_size(q));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",queue_is_empty(q));
              
              
              
              
              
		printf("\n");
	}
       
       
       }         
                
                
