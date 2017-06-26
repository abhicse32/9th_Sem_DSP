
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"

#define BUFF_SIZE 20

int main(int argc, char const *argv[])
{	
	int i ;
	scanf("%d" , &SIZE) ;

	int* arr = (int*)malloc(SIZE*sizeof(int)) ;
	for (i = 0; i < SIZE; ++i)
		scanf("%d" , &arr[i]) ;

	initializeMap (arr) ;

	char str[BUFF_SIZE];

	while(fgets(str,BUFF_SIZE,stdin) != NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if( temp == NULL) continue ;
		if(!strcmp(temp,"union"))
		{
			int xVal=atoi(strtok(NULL," "));
			int yVal=atoi(strtok(NULL," "));
			Union(xVal , yVal);
		}
		else if(!strcmp(temp,"find"))
		{
			int xVal=atoi(strtok(NULL," "));
			printNode( find (xVal) ) ;
		}
		else if(!strcmp(temp,"isMember"))
		{
			int xVal=atoi(strtok(NULL," "));
			int yVal=atoi(strtok(NULL," "));
			if (isMember(xVal ,yVal)) printf("true\n");
			else  printf("false\n");
		}
		else if(!strcmp(temp,"printNode"))
		{
			int xVal=atoi(strtok(NULL," "));
			printNode( getNode (xVal) ) ;
		}
		else if(!strcmp(temp,"printMap"))
		{
			printMap() ;
		}
		else if(!strcmp(temp,"findWithPathCompression"))
		{
			int xVal=atoi(strtok(NULL," "));
			printNode( findWithPathCompression (xVal) ) ;
		}
		else if(!strcmp(temp,"cardinality"))
		{
			int xVal=atoi(strtok(NULL," "));
			printf("%d\n", cardinality(xVal));
		}
		
		//printf("\n");
	}
	return 0;
}


