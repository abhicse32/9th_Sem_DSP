#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printchar(int i)
{
	if(i==2) printf("* ");
	if(i==3) printf("/ ");
	if(i==4) printf("%c ",'%');
	if(i==5) printf("+ ");
	if(i==6) printf("- ");
	if(i==7) printf("& ");
	if(i==8) printf("^ ");
	if(i==9) printf("| ");
}

void main()
{
	int x,y,i,j,k;

	for(j = 0; j < 10; j ++)
	{

	char a[1000];
	fgets(a,1000,stdin);
	stack* temps = stack_new();
	Node* temphead = temps->top->head;
	a[strlen(a)-1] = '\0';
	for(i = 0; a[i] != '\0'; i++)
	{
		if(a[i] == ' ' && a[i+1] == ' ') break;
		if(a[i] == ' ') continue;
		if(a[i] == '(') 
		{
			stack_push(temps, 1);
			temphead = temps->top->head;
			continue;
		}
		else if(a[i] == '*' || a[i] == '/' || a[i] == '%')
		{
			if(a[i] == '*') y = 2;
			if(a[i] == '/') y = 3;
			if(a[i] == '%') y = 4;
			if(temphead == NULL)
			{
				stack_push(temps, y);
				temphead = temps->top->head;
				continue;
			}
			else if(temphead->data <= 4)
			{
				while(temphead->data <= 4)
				{
					if(temphead->data == 1) break;
					x = stack_pop(temps);
					printchar(x);
					temphead = temps->top->head;
					if(temphead == NULL) break;
				}
				stack_push(temps, y);
				temphead = temps->top->head;
				continue;
			}
			else 
			{
				stack_push(temps, y);
				temphead = temps->top->head;
			}
		}
		else if(a[i] == '+' || a[i] == '-')
		{
			if(a[i] == '+') y = 5;
			if(a[i] == '-') y = 6;

			if(temphead == NULL)
			{
				stack_push(temps, y);
				temphead = temps->top->head;
				continue;
			}
			else if(temphead->data <= 6)
			{
				while(temphead->data <= 6)
				{
					if(temphead->data == 1) break;
					x = stack_pop(temps);
					printchar(x);
					temphead = temps->top->head;
					if(temphead == NULL) break;
				}
				stack_push(temps, y);
				temphead = temps->top->head;
				continue;
			}
			else 
			{
				stack_push(temps, y);
				temphead = temps->top->head;
			}
		}
	
		else if(a[i] == '&')
		{
			
			if(temphead == NULL)
			{
				stack_push(temps, 7);
				temphead = temps->top->head;
				continue;
			}
			else if(temphead->data <= 7)
			{
				while(temphead->data <= 7)
				{
					if(temphead->data == 1) break;
					x = stack_pop(temps);
					printchar(x);
					temphead = temps->top->head;
					if(temphead == NULL) break;
				}
				stack_push(temps, 7);
				temphead = temps->top->head;
				continue;
			}
			else 
			{
				stack_push(temps, 7);
				temphead = temps->top->head;
			}
		}
		else if(a[i] == '^')
		{
			if(temphead == NULL)
			{
				stack_push(temps, 8);
				temphead = temps->top->head;
				continue;
			}
			else if(temphead->data <= 8)
			{
				while(temphead->data <= 8)
				{
					if(temphead->data == 1) break;
					x = stack_pop(temps);
					printchar(x);
					temphead = temps->top->head;
					if(temphead == NULL) break;
				}
				stack_push(temps, 8);
				temphead = temps->top->head;
				continue;
			}
			else 
			{
				stack_push(temps, 8);
				temphead = temps->top->head;
			}
		}
		else if(a[i] == '|')
		{
			if(temphead == NULL)
			{
				stack_push(temps, 9);
				temphead = temps->top->head;
				continue;
			}
			else if(temphead->data <= 9)
			{
				while(temphead->data <= 9)
				{
					if(temphead->data == 1) break;
					x = stack_pop(temps);
					printchar(x);
					temphead = temps->top->head;
					if(temphead == NULL) break;
				}
				stack_push(temps, 9);
				temphead = temps->top->head;
				continue;
			}
			else 
			{
				stack_push(temps, 9);
				temphead = temps->top->head;
			}
		}
		else if(a[i] == ')')
		{
			
				while(temphead->data != 1)
				{
					x = stack_pop(temps);
					printchar(x);
					temphead = temps->top->head;
				}
				stack_pop(temps);
				temphead = temps->top->head;
				continue;
			
		}
		else 
		{
			if(i == strlen(a)-1) printf("%c ", a[i]);
			else if(a[i+1] != ' ')
			printf("%c", a[i]);
			else printf("%c ", a[i]);
			continue;
		}
	

	}
	

	while(temphead != NULL)
	{
		x = stack_pop(temps);
		printchar(x);
		temphead = temps->top->head;
	}

	printf("\n");

	}



}

