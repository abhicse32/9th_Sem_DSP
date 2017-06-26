#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
#include "List.h"
#include "stack.h"

/*typedef struct Node_ Node;
struct Node_ {
    char data;
    Node* next;
};

typedef struct LList_ {
    Node* head;
} LList;

Node* node_new(char data){
        Node* new = (Node*) malloc(sizeof(Node));
        if(new==NULL) return;
        else{
                new->data=data;
                new->next=NULL;
        }
        return new;
}

LList* llist_new(){
        LList* list;
        list=(LList*)malloc(sizeof(LList));
        list->head=NULL;
        return list;
}

char llist_get( LList* lst, int idx ){
        if(idx<0) return INT_MIN;
        int i=0;
        Node* temp=lst->head;
        if(temp==NULL) return;
        if(temp->next==NULL&&idx==1) return temp->data;
        while(temp->next!=NULL){
                if(i==idx) return temp->data;
                else{
                        temp=temp->next;
                        i++;
                }
        }
        if(temp->next==NULL&&i==idx) return temp->data;
        if(temp->next==NULL&&i!=idx) return INT_MIN;

}

void llist_prepend( LList* lst, char data ){
        Node* new = (Node*) malloc(sizeof(Node));
        new->data=data;
        new->next=lst->head;
        lst->head=new;               
}

void llist_remove_first( LList* lst ){
        if(lst->head==NULL) return;
        Node* temp=lst->head;
        lst->head=(lst->head)->next;
        free(temp);
}
void llist_print( LList* lst ){
        Node* temp;
        temp=lst->head;
        if(temp==NULL) return;
        while(temp!=NULL){
                printf("%c ",temp->data);
                temp=temp->next;
        }
        //printf("\n");        
}

typedef struct Stack{
	LList* top;
}stack;

stack* stack_new(){
	stack* S = (stack*)malloc(sizeof(stack));
	S->top = llist_new();
	return S;
}


void stack_push(stack* S,char data){
	llist_prepend(S->top,data);

}

char stack_pop(stack* S){
	char topdata = llist_get(S->top,0);
	llist_remove_first(S->top);
	return topdata;
}

bool stack_is_empty(stack* S){
	if((S->top)->head == NULL) return true;
	else return false;
}


void stack_print(stack* S){
	llist_print(S->top);
}*/
char gettop(stack* S){
	return llist_get(S->top,0);
}


int precedence(char operator){
	switch(operator){
		case '*':
		case '/':
		case '%':
		return 4;
		break;
		case '+':
		case '-':
		return 3;
		break;
		case '^':
		return 1;
		break;
		case '&':
		return 2;
		break;
		case '|':
		return 0;
		break;	
	}
	return -1;
}

bool isOperator(char c){
	switch(c){
		case '*':
		case '/':
		case '%':
		case '+':
		case '-':
		case '^':
		case '&':
		case '|':
		case '(':
		case ')':
		return true;
	}
	 return false;
}

void infixToPostfix(){
	char c=getchar();
	char out[100];
	int i;
	for(i=0;i<99;i++) out[i]='#';
	int j=0;
	char pop;
	stack* S=stack_new();
	i=0;
	while(c!='\n'){
		while(!isOperator(c)){ 
			//printf("%c",c);
			out[i]=c;
			i++;
			c=getchar();
			if(c=='\n') 
			{	j=1;
				break;
			}	
			//printf("s");
			if(i==100) return;
		}	
			if(j==1) break;
			if(stack_is_empty(S)==true){
				stack_push(S,c);
				c=getchar();
				continue;
			}	
			else if(c =='('){ 
				stack_push(S,c);
				c=getchar();
				continue;
			}	
			else if(c == ')'){
				while(gettop(S)!='('){
					pop=stack_pop(S);
					out[i]=' ';
					out[++i]=pop;
					i++;
					if(i==100) return;		
				}
				stack_pop(S);
				c=getchar();
				continue; 
			}
			else if(precedence(c)>precedence(gettop(S))){
				stack_push(S,c);
				c=getchar();
				continue;

			}
			else if(precedence(c)<=precedence(gettop(S))){
				while(precedence(c)<=precedence(gettop(S)) && !stack_is_empty(S)){
						out[i]=' ';
						out[++i]=stack_pop(S);
						i++;
						if(i==100) return;	
				}
				stack_push(S,c);
				c=getchar();
				continue;
			}
			
	
	}
		//stack_print(S);	
		while(!stack_is_empty(S)){
			out[i]=' ';
			out[i+1]=stack_pop(S);
			i+=2;
	}
	printf("%c",out[0]);
	for(i=1;out[i]!='#';i++){
		if(out[i]==' '&&out[i-1]==' '); 
		else printf("%c",out[i]);

	}
	return;
		
}

int main(){
	int t=10;
	while(t--){
		infixToPostfix();
		printf("\n");
	}
	return 0;

}





