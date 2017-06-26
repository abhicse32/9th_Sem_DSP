/* Program that converts an infix expression into post form
	G.Pranav	CS15B015	18-9-2016	*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "List.h"
int main(){
	int xyz;
	for(xyz=0;xyz<10;xyz++){		//running the program 10 times
	char arr;
	arr=getchar();					//inputting the expression in the form of characters
	stack *stackptr=stack_new();	//declaring a stack
	while(1){
		if(isalnum(arr)){			//checking whether the character is alphabet or number
			do{
				printf("%c",arr);
				arr=getchar();
			}while(isalnum(arr));	//checking whether the next character is alphabet or number
			printf(" ");
		}
		else if(arr=='('){
			stack_push(stackptr,'(');
		}
		else if(arr==')'){
			if(!stack_is_empty(stackptr)){
				char temp=stack_pop(stackptr);	//popping and printing the elements of the stack till ) is encountered
				while(temp!='('){
					printf("%c ",temp);
					temp=stack_pop(stackptr);
				}
			}
		}
		else{		//this part checks whether the character is an operator and arranges them 
					//in the decreasing order of precedence in the stack
			
			if((arr=='*')||(arr=='/')||(arr=='%')){

				if(!stack_is_empty(stackptr)){
					int xyz=0;
					char temp=stack_pop(stackptr);

					while((temp=='*')||(temp=='/')||(temp=='%')){	//popping and printing if the character 
																			//in the stack has same precedence
						printf("%c ",temp);
						if(stack_is_empty(stackptr)){
							xyz=1;
							break;
						}
						else temp=stack_pop(stackptr);
					}
					if(xyz!=1) stack_push(stackptr,temp);
				}
				stack_push(stackptr,arr);
			}
			else if((arr=='+')||(arr=='-')){
				
				if(!stack_is_empty(stackptr)){
					int xyz=0;
					char temp=stack_pop(stackptr);
					while((temp=='*')||(temp=='/')||(temp=='%')||(temp=='+')||(temp=='-')){
						printf("%c ",temp);
						if(stack_is_empty(stackptr)){
							xyz=1;
							break;
						}
						else temp=stack_pop(stackptr);
					}
					if(xyz!=1) stack_push(stackptr,temp);
				}
				stack_push(stackptr,arr);
			}
			
			else if(arr=='&'){
				
				if(!stack_is_empty(stackptr)){
					int xyz=0;
					char temp=stack_pop(stackptr);
					while((temp=='*')||(temp=='/')||(temp=='%')||(temp=='+')||(temp=='-')||(temp=='&')){
						printf("%c ",temp);
						if(stack_is_empty(stackptr)){
							xyz=1;
							break;
						}
						else temp=stack_pop(stackptr);
					}
					if(xyz!=1) stack_push(stackptr,temp);
				}
				stack_push(stackptr,arr);
			}

			else if(arr=='^'){
				
				if(!stack_is_empty(stackptr)){
					int xyz=0;
					char temp=stack_pop(stackptr);
					while((temp=='*')||(temp=='/')||(temp=='%')||(temp=='+')||(temp=='-')||(temp=='&')||(temp=='^')){
						printf("%c ",temp);
						if(stack_is_empty(stackptr)){
							xyz=1;
							break;
						}
						else temp=stack_pop(stackptr);
					}
					if(xyz!=1) stack_push(stackptr,temp);
				}
				stack_push(stackptr,arr);
			}

			else if(arr=='|'){
				
				if(!stack_is_empty(stackptr)){
					int xyz=0;
					char temp=stack_pop(stackptr);
					while((temp=='*')||(temp=='/')||(temp=='%')||(temp=='+')||(temp=='-')||(temp=='&')||(temp=='^')||(temp=='|')){
						printf("%c ",temp);
						if(stack_is_empty(stackptr)){
							xyz=1;
							break;
						}
						else temp=stack_pop(stackptr);
					}
					if(xyz!=1) stack_push(stackptr,temp);
				}
				stack_push(stackptr,arr);
			}
		}
		if((arr=='\0')||(arr=='\n')) break;	
		arr=getchar();
		if((arr=='\0')||(arr=='\n')) break;		//terminating the loop when \n is encountered	
	}
	int size=stack_size(stackptr);		//printing the residual elements in the stack
	int j;
	for(j=0;j<size;j++){
		char temp=stack_pop(stackptr);
		printf("%c ",temp);
	}
	printf("\n");
	}
	return 0;
}                             