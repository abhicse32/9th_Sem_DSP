/*D TEJA VARDHAN REDDY CS15B014  18/9/16*/
/* EVALUATING POSTFIX */

#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	char ch;
	int ewh=10;
	while(ewh--){
		ch=getchar();
		stack*st=stack_new();
		
		while(ch!='\n'){
			

			
			int i=0,h=-1;
			char arr[30];


			if(('0'<=ch && ch<='9') || ch=='-'){
				
				if(ch!='-'){
					h=1;
					arr[i]=ch;
					i++;

				}
				ch=getchar();
				if(ch!=' ' && ch!='\n')
				{
					
					while(ch!=' '){
						arr[i]=ch;
						i++;
						ch=getchar();
					}
					arr[i]='\0';
					int k=atoi(arr);

					k*=h;
					stack_push(st,k);


					
				}
				
				else
				{
					if(h==-1)
					{
						int data2=stack_pop(st);
						int data1=stack_pop(st);
						stack_push(st,data1-data2);
					}
					else{
						arr[i]='\0';
						int k= atoi(arr);
						//printf("%d ",k);

						stack_push(st,k);

						
					}
					

				}

			}
			else
			{
				int data2=stack_pop(st);
				int data1=stack_pop(st);
				// printf("%d %d",data1,data2);
				switch(ch){
					case'+':stack_push(st,data1+data2);break;
					case'/':stack_push(st,data1/data2);break;
					case'*':stack_push(st,data1*data2);break;
					case'|':stack_push(st,data1|data2);break;
					case'&':stack_push(st,data1&data2);break;
					case'^':stack_push(st,data1^data2);break;
					case'%':stack_push(st,data1%data2);break;
				}
				ch=getchar();
				
			}

			if(ch!='\n')
				ch=getchar();
			
			//printf("%c ghff",ch);
			
		}
		//printf("%dewh",ewh);
		printf("%d\n",stack_pop(st));
	}
	
}