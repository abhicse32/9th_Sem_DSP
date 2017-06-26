#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
//#include"stack.c"
//#include"List.c"
#include<string.h>
#define size 1000

void intopost( char * );
int convert (char *);
int icp(int);
int isp (int);
char rev_con( int );
int operator( char * );

int main(){
	int i;
	for(i=0;i<10;i++){
	    char *s = (char *)malloc(size * sizeof(char));
	    fgets(s, 100, stdin);
	    int len = strlen(s);
	    s[len-1]='\0';
	    
	    intopost(s);
	    printf("\n");
	  }
    return 0;
} 

void intopost( char * str){

	//printf("%s\n", str);
	fflush(stdout);
	int count=0; 
    int i, len, j, k, l, m;
    char d;
    char *token, *c;
    stack * st = stack_new();
    char spc[2] = " ";
    len = strlen(str);
    //printf("%dlen\n", len);
    //fflush(stdout);
    token = strtok(str, spc);
    while(token!=NULL){
    	//printf("%s\n", token);
	//fflush(stdout);
	//m = atoi(token);
        c = token;

        if(!operator(token)) //If c is an alphabet print it
            printf("%s ", token);
            
        else if(stack_is_empty(st)){
        	//printf("%dcon", convert(c));
            stack_push(st, convert(c));
            }
        else{
        	if(!strcmp(c, "("))
        	{
        		stack_push(st, convert(c));
        		//break;
        	}
        		
        	else if(!strcmp(c, ")")){
        		while(!stack_is_empty(st)){
        			d = rev_con(stack_pop(st));
        			if(d=='(')
        				break;
        			else
        				printf("%c ", d);
        		}
		}
		else{
		    j = icp(convert(c));
		    l = stack_pop(st);
		    k = isp(l);
		    //printf("%d--%d\n", j, k);
		    if(j>k){
		        stack_push(st, l);
		        stack_push(st, convert(c));
		        }
		        
		    else{
		    	if(stack_is_empty)	
		    		printf("%c ", rev_con(l));
		    	else{
		        while(!(j>k)){
		        	//printf("%d--%d\n", j, k);
		        	printf("%c ", rev_con(l));
		        	if(stack_is_empty(st))
		        		break;
		        	l = stack_pop(st);
		  		k = isp(l);     
		  		}  	
			        
               		 }
               		 stack_push(st, convert(c));
               		}
            
           
                }
            }
    token = strtok(NULL, spc);
   // stack_print(st);
    //printf("\n");
    }
    //stack_print(st);
    //printf("\n");
    while(!stack_is_empty(st))
    	printf("%c ", rev_con(stack_pop(st)));
        
}

int convert (char *c){
	
	if(strcmp(c, "(")==0)
		return 0;
	else if(strcmp(c, "+")==0)
		return 1;
	else if(strcmp(c, "-")==0)
		return 2;
	else if(strcmp(c, "*")==0)
		return 3;
	else if(strcmp(c, "/")==0)
		return 4;
	else if(strcmp(c, ")")==0)
		return 5;
	else if(strcmp(c, "|")==0)
		return 6;
	else if(strcmp(c, "&")==0)
		return 7;
	else if(strcmp(c, "%")==0)
		return 8;
	else if(strcmp(c, "^")==0)
		return 9;
	
}

char rev_con( int n ){

	switch(n){

		case 0:
			return '(';
			break;
		case 1:
			return '+';
			break;
		case 2:
			return '-';
			break;
		case 3:
			return '*';
			break;
		case 4:
			return '/';
			break;
		case 5:
			return ')';
			break;
		case 6:
			return '|';
			break;
		case 7:
			return '&';
			break;
		case 8:
			return '%';
			break;
		case 9:
			return '^';
			break;
		
		
		
		
			
	}
			
}

int icp(int n){

	switch (n){
	
		case 0:
			return 5;
			break;
		case 1:
			return 3;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 4;
			break;
		case 4:
			return 4;
			break;
		case 9:
			return 1;
			break;
		case 6:
			return 0;
			break;
		case 7:
			return 2;
			break;
		case 8:
			return 4;
			break;
		}
}

int isp (int n){

	switch (n){
	
		case 0:
			return -1;
			break;
		case 1:
			return 3;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 4;
			break;
		case 4:
			return 4;
			break;
		case 9:
			return 1;
			break;
		case 6:
			return 0;
			break;
		case 7:
			return 2;
			break;
		case 8:
			return 4;
			break;
		}
}

int operator ( char * c ){

	if(strcmp(c,"(")==0 || strcmp(c, "+")==0 || strcmp(c,"-")==0 || strcmp(c,"*")==0 || strcmp(c,"/")==0 || strcmp(c,")")==0 || strcmp(c, "&")==0 || strcmp(c, "|")==0 || strcmp(c, "%")==0 || strcmp(c, "^")==0){
		//printf("%dop", 1);
		return 1;
		}
	else{
		//printf("%dop", 0);
		return 0;
	}
}	
