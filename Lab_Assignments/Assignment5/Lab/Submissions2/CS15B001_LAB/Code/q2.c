/*
This program finds out the minimum number of bracket reversals required 
to make a given bracket sequence valid

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>

int main()
{

int test;	//Holds the number of test cases
char a[2000],stack[2000]; 	//Using array for stack implementation
int top=-1,check;		//Stack variables
char cl='{';		//The variables store the brackets


scanf("%d",&test);	//Input the number of test cases

int i,j;	//Loop variables

for(i=0;i<test;++i)
{
scanf("%s",a);	//Input the string

top=-1;

for(j=0;a[j]!='\0';++j)
{

	if(a[j]==cl)		//If left bracket is encountered, add it to the stack
	{
		top=top+1;
		stack[top]=a[j];
	}

	else
	{

		if(top!=-1)
		{	if(stack[top]==cl)
			{
				top=top-1;
			}
			else
			{
				top=top+1;
				stack[top]=a[j];
			}
		}
		else
		{
			top=top+1;
			stack[top]=a[j];
		}

	}

		

}	//Inner for loop ends

check=top+1;

if(check%2)	//If there are odd number of elements then not possible
{
	printf("-1\n");
}

else
{

	for(check=0;(stack[check]!=cl)&&(check<=top);++check)
	{
	}

	if(check%2==0)
	{
		printf("%d\n",(top+1)/2);
	}
	else
	{
		printf("%d\n",(top+3)/2);
	}



}

}	//Outer for loop ends


return 0;

}	//Program ends



