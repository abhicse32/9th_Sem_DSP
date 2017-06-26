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
int stack_size(char arr[SIZE]){//To get the size of the stack arr
	if(top==-1) return 0;
	return (top+1);
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
	int t;//Number of test cases
	char s[SIZE];//Holds input parenthesis sequence
	char arr[SIZE];//Stack implemented as an array
	scanf("%d",&t);
	
	while(t--){
		top=-1;//Setting top to -1
		scanf("%s",s);//Reading in the input string
		int ans=0;//Holds the number of reversals required
		int n=strlen(s);//Holds the length of the input string
		int i;

		for(i=0;i<n;i++){
			if(s[i]=='{')//Push open parenthesis into stack 
				stack_push(arr,s[i]);
			else{//if s[i] is '}'
				if(top==-1) {//No '{' so reverse s[i] to '{' and push it
					ans++;
					stack_push(arr,'{');
				}
				else{//Pop the '{' which is there in the stack
					stack_pop(arr);
				}
			}
		}
		int extra=stack_size(arr);//extra holds the number of extra '{' present in the stack
		//half of these extras need to be converted to '}'
		if(extra%2==1) {//cannot convert to '}' Always unbalanced
			printf("-1\n");
			continue;
		}
		ans=ans+(extra/2);
		printf("%d\n",ans);//Printing ans
	}
	return 0;
}
