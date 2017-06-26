#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stackDT{
	int Arr[1000];
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
void push(stkArr *s,int elm){
	if(!isFull(s)){
		s->top++;
		s->Arr[s->top]=elm;	//adding an element at the last+1 place
	}
	return;
}

//function to pop out the top element
int pop(stkArr *s){
	int x;
	if(!isEmpty(s)){
		x=s->Arr[s->top];
		s->top--;	//extracting the top element and decrementing the top pointer 
	}
	return x;
}

int top(stkArr *s){
	int x;
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
	int s[1000];
	stkArr *stk = createStack();
	stkArr *ans = createStack();
	int x;
	for(i=0;i<t;i++){
		scanf("%d",&l);
		for(j=0;j<l;j++){
			scanf("%d",&s[j]);
		}
		for(j=l-1;j>=0;j--){
			if(isEmpty(stk)){
				push(stk,s[j]);	//pushing into stk the present element and -1 into ans stack
				push(ans,-1);
			}
			else if(s[j] < top(stk)){
				push(ans,top(stk));	//adding the new element as it continues the descending order of the stack
				push(stk,s[j]);
			}
			else{
				while(s[j] >= top(stk)){
					pop(stk);	//decreasing the stack's top till it reaches a place where it continues the decreasing order
					if(isEmpty(stk)){ push(ans,-1);
							break; }
				}
				if(isEmpty(stk)){ push(stk,s[j]);
						continue; }
				push(ans,top(stk));
				push(stk,s[j]);
			}
		}
		while(!isEmpty(ans)){
			printf("%d ",pop(ans));	//printing the ans stack
		}
		while(!isEmpty(stk)){
			pop(stk);	//clearing the stk stack
		}
		printf("\n");
	}
	return 0;
}
