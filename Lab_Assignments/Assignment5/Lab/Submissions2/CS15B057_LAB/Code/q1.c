/*
	Author: G.Kavitha
	Roll No. CS15B057
	Date: 16-09-16
*/
#include <stdio.h>
#include <string.h>
const int SIZE=1005;
int top=-1;
char stack_top(char arr[SIZE]){//To get the top element in the stack
	if(top==-1) return 'a';
	return arr[top];
}	
void stack_push(char arr[SIZE], char ch){//To push an element in stack arr
	if(top==SIZE-1) return;
	top++;
	arr[top]=ch;
}
void stack_pop(char arr[SIZE]){//To pop the top most element in stack arr
	if(top==-1) return;
	top--;
}
int main(){
	char s[SIZE];//To hold the input string
	int t;//No. of test cases
	scanf("%d",&t);
	while(t--){
		char arr[SIZE];//Stack implemented as an array
		top=-1;//Setting top to -1
		scanf("%s",s);//Reading in the input string
		int i;
		int ok=1;//ok is 1 if the string is valid, 0 otherwise
		int n=strlen(s);//n is length of the input string

		for(i=0;i<n;i++){
			if(s[i]=='('||s[i]=='['||s[i]=='{')//Push in open parenthesis 
				stack_push(arr,s[i]);
			else{
				char check;//check holds what the top element of the stack arr should ideally be for balanced string
				if(s[i]==')') check='(';
				else if(s[i]==']') check='[';
				else check='{';
				if(stack_top(arr)!=check) {//Not valid string
					ok=0;
					break;
				}
				stack_pop(arr);//If valid till here, then pop that corresponding open bracket
			}
		}
		if(top!=-1) {//Then there are some extra open parenthesis, so invalid string
			ok=0;
		}
		printf("%d\n",ok);
	}
	return 0;
}

