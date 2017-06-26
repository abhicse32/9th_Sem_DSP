/*Finds minimum no. of reversals
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

//this counts min no of reversals required and prints it
void reversals_count(stack *s){
	int count1 = 0;		//count1 calculates no of times { has occured
	int count2 = 0;		//count2 calculates no of times } has occured
	int result;
	char x;	
	while(s -> top >= 0){
		x = pop(s);
		if(x == '{') count1++;
		else if(x == '}') count2++;	
	}
	if((count1 + count2)%2 != 0) printf("-1\n");	//if sum is odd u cannot balance	
	else if(count1 % 2 == 0){
		result = (count1 + count2)/2;
		printf("%d\n",result);				//if count1 is even result is (count1 + count2) / 2
	}
	else{
		result = (count1 + count2)/2 + 1;	//if count1 is odd result is (count1 + count2) / 2 + 1
		printf("%d\n",result);
	}
}

int main(){
	int T,i;
	scanf("%d",&T);		//stores no of testcases
	char c = getchar();		//this extra getchar() is to nullify a new line character
	for(i = 0;i < T;i++){		//implements 'for' loop for multiple testcases
		char x;
		stack *s = new(); 
		while((c = getchar()) != '\n'){	 //reads character by character and terminates when a newline is entered 
			if(c == '{') push(s,c);	
			else if(c == '}'){
				if(s -> top >= 0){
					x = pop(s);
					if(x != '{'){
						push(s,x);
						push(s,'}');
					}	
				}
				else{
					push(s,'}');	
				}				
			}						
		}
		reversals_count(s);		//calls this function after removing all the valid parts of the string
	}
}
