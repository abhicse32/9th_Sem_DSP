#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stackDT{
	char Arr[1000];
	int top;
}stkArr;

//creating a stack
stkArr *createStack(){
	stkArr *s;
	s=(stkArr *)malloc(sizeof(stkArr));
	s->top = -1;
	return s;
}

//checking if stack is empty
int isEmpty(stkArr *s){
	if(s->top==-1){
		return 1;	//return 1 if top points to -1 else 0
	}
	else{
		return 0;
	}
}

//checking if stack is full
int isFull(stkArr *s){
	if(s->top==999){
		return 1;	//returns 1 if top points to the max-1 element
	}
	else{
		return 0;
	}
}
//function to push to the stack
void push(stkArr *s,char elm){
	if(!isFull(s)){
		s->top++;
		s->Arr[s->top]=elm;	//adding an element at the last+1 place
	}
	return;
}

//function to pop out the top element
char pop(stkArr *s){
	char x;
	if(!isEmpty(s)){
		x=s->Arr[s->top]; //extracting the top element and decrementing the top point
		s->top--;
	}
	return x;
}

char top(stkArr *s){
	char x=0;
	if(!isEmpty(s)){
		x=s->Arr[s->top];	//extracting the top element without changing top pointer
	}
	return x;
}

int main(){
	int t;
	scanf("%d",&t);
	int i=0,j=0;
	int l;
	char s[1000];
	stkArr *stk = createStack();
	int count;
	int len;
	for(i=0;i<t;i++){
		scanf("%s",s);
		l=strlen(s);
		count=0;
		for(j=0;j<l;j++){
			if( s[j]=='{' ){
				push(stk,s[j]);
			}
			else if( s[j] == '}' ){
					if( top(stk) == '{') pop(stk);	//popping if it is a matching bracket
					else if(isEmpty(stk)){
						push(stk,'{');		//else reversing  the bracket and inc the counter of reversls
						count++;
					}
			}
		}
		len=0;
		while(!isEmpty(stk)){
			pop(stk);
			len++;
		}
		if(len%2 ==1){
			printf("-1\n");
		}
		else{
			printf("%d\n",count+ (len/2));	//if the rem are even in number they can be matched by n/2 reversals
		}
	}
	return 0;
}
