/*Checks whether parenthesis are valid
Y BHARGAVA SAI CS15B042 16-09-16*/
#include <stdio.h>
#include <stdlib.h>
#define max 1001

//definition of stack
typedef struct Stack{
	char arr[max];
	int top;
}stack;

//creates new stack and returns pointer to a stack
stack * new(){
	stack * s = (stack *)malloc(sizeof(stack));
	s -> top = -1;
	return s;
}

//pushes char c into stack
void push(stack *s,char c){
	if(s -> top < max - 1){
		s -> top++;
		s -> arr[s -> top] = c;
	}			
}

//pops out a character and returns it 
char pop(stack *s){
	if(s -> top >= 0){
		char x = s -> arr[s -> top];
		s -> top--;
		return x;
	}
}

int main(){
	int T,i;
	scanf("%d",&T);			//stores no of testcases
	char c = getchar();
	for(i = 0;i < T;i++){	//implements 'for' loop for multiple testcases
		char x;
		int flag = 1;
		stack *s = new(); 
		
		while((c = getchar()) != '\n'){		//this extra getchar() is to nullify a new line character
			if((c == '{')||(c == '(')||(c == '[')) {
				push(s,c);		//pushes if a bracket is opened
			}		
			else if(c == ')'){
				if(s -> top >= 0){		//if a bracket is closed pops the top most parenthesis and check if matches										
					x = pop(s);			//otherwise flag is set to 0
					if(x != '('){	
						flag = 0;
					}	
				}
				else{
					flag = 0;
				}				
			}
			else if(c == '}'){
				if(s -> top >= 0){
					x = pop(s);
					if(x != '{'){
						flag = 0;
					}	
				}
				else{
					flag = 0;
				}				
			}
			else if(c == ']'){
				if(s -> top >= 0){
					x = pop(s);
					if(x != '['){
						flag = 0;
					}	
				}
				else{
					flag = 0;
				}				
			}						
		}
		if(flag) printf("1");	//initially flag is 1 
		else printf("0");		//flag is set to zero if parenthesis are wrongly matched
		printf("\n");	
	}
}
