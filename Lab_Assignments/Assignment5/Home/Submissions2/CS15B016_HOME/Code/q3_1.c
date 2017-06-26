#include <stdio.h>
#include "stack.h"
#include "List.h"
//#include "stack.c"
//#include "List.c"
#include <string.h>

int main(int* argc, char* argv[]){
	void pass_through(char s[], int size);
	int check_op(char*s, int size, int idx); //checks if character from idx till next space is encountered is a number
	int return_char(char *s, int size, int idx, char *s2); //returns the number at idx to next space
	int ICPprior(char ch); //returns precedence value of an operation
	int ISPprior(char ch);
//	void tester();

	char s[100];
	while(fgets(s,100,stdin)!=NULL){
	
		
		int len=strlen(s);
		s[len-1]='\0';
		pass_through(s,len-1);
		printf("\n");
	}

}




int check_op(char* s, int size, int idx) //checks if character from idx till next space is encountered is a number
{
	int k=idx;
	
	switch(s[k]){
		case '+':
		case '-':
		case '/':
		case '*':
		case '^':
		case '&':
		case '|':
		case '%':
		case '(':
		case ')': return 1;
		default: return 0;

	}
}



int return_char(char *s, int size, int idx, char *s2) //returns the number at idx to next space
{
	int k=0;
	while((s[idx]!=' ')&&(idx!=size)){
		s2[k++]=s[(idx)++];
	}
	if(s[idx]==' ')
		(idx)++;
	s2[k]='\0';
	return idx;
}


int ICPprior(char ch){
	switch(ch){
		case '+': return 1+2;
		case '-': return 1+2;
		case '/': return 3+2;
		case '*': return 3+2;
		case '&': return 0+2;
		case '%': return 5;
		case '^': return 1;
		case '|': return 0;
		case '(': return -1;
		case ')': return -1;
	}
}



int ISPprior(char ch){
	switch(ch){
		case '+': return 1+2;
		case '-': return 1+2;
		case '/': return 3+2;
		case '*': return 3+2;
		case '&': return 0+2;
		case '%': return 3+2;
		case '^': return -1+2;
		case '|': return -2+2;
		case '(': return -1;
		case ')': return -1;
	}
}	



void print(int x){
char ch=x;
char s[2];
s[0]=ch;
s[1]='\0';
printf("%s ", s);
}




void pass_through(char s[], int size){
	int i=0;
	int flag;
	int j;
	stack *ops=stack_new();
	while(i<size){
		char temp[10];
		j=i;
		i=return_char(s,size,i,temp);
		flag=check_op(temp, i-j-1, 0);
		if(!flag){
			printf("%s ",temp);
		}
		if (flag)
		{ 	//printf("%c ",temp[0]);
			if(stack_is_empty(ops)) stack_push(ops, temp[0]);
			else if (temp[0]=='(')
			{
				stack_push(ops, temp[0]);

			}
			else if (temp[0]==')')
			{
				int top=stack_pop(ops);
				char ch=top;
				while(top!='('){
					print(top);
					top=stack_pop(ops);
					ch=top;
				}
				//top=stack_pop(ops);
			}
			else{
				int top=stack_pop(ops);
				char* ch=top;
				if(top=='('){
					stack_push(ops, top);
					stack_push(ops, temp[0]);
				}
				else if(ICPprior(temp[0])>ISPprior(top)){
					stack_push(ops, top);
					stack_push(ops, temp[0]);
				}
				else if (ICPprior(temp[0])<=ISPprior(top))
				{
					while(ICPprior(temp[0])<=ISPprior(top)){
						print(top);
						top=stack_pop(ops);
						ch=top;
						//printf("x");
					}
					stack_push(ops, top);
					stack_push(ops, temp[0]);
				}


			}
		}
	}
	while(!stack_is_empty(ops)){
		print(stack_pop(ops));
	}
}
