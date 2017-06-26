#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "List.h"
#include "queue.h"
#define MAX_LEN 20
#define STR_MAX 1000

void findWords(int count, char dict[count][MAX_LEN], int N, int M, char A[N][M]);
void findWordsUtil(int count, char dict[count][MAX_LEN], int N, int M, int visited[N][M], char A[N][M], int i, int j, char *str);
int main(int argc, char const *argv[])
{
	/* code */
	char str[STR_MAX], copy[MAX_LEN];
	int N, M, i, j;
	
	fgets(str, STR_MAX, stdin);
	//puts(str);
	str[strlen(str)-1] = '\0';
	strcpy(copy, str);
	
	scanf("%d%d", &N, &M);
	//printf("%d %d\n", N,M);
	
	char A[N][M], c;
	int num = 0;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			scanf(" %c", &A[i][j]);
	//printf("%cc", A[0][1]);
	
	char *token;
	int count=0;
	token = strtok(copy, " ");
	while(token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	//printf("%d\n", count);
	
	char dict[count][MAX_LEN];
	count = 0;
	token = strtok(str, " ");
	//puts(str);
	while(token != NULL)
	{
		strcpy(dict[count], token);
		//puts(dict[count]);
		count++;
		token = strtok(NULL, " ");
	}
	//printf("%d\n", count);
	//for(i=0;i<count;i++)
	//	puts(dict[i]);
		
	findWords(count, dict, N, M, A); 
	printf("\n");
	return 0;
}

void findWords(int count, char dict[count][MAX_LEN], int N, int M, char A[N][M])
{
	int visited[N][M];
	
	int i, j;	
	
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			visited[i][j] = 0;
			
	char str[MAX_LEN];
	str[0] = '\0';
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
		{
			if(!visited[i][j])
				findWordsUtil(count, dict, N, M, visited, A, i, j, str);
			str[0] = '\0';
		}
}

void findWordsUtil(int count, char dict[count][MAX_LEN], int N, int M, int visited[N][M], char A[N][M], int i, int j, char *str)
{
	visited[i][j]=1;
	
	char temp[2];
	temp[0] = A[i][j];
	temp[1] = '\0';
	strcat(str, temp);
	//puts(str);
	fflush(stdout);
	
	int k;
	for(k=0;k<count;k++)
		if(!strcmp(dict[k], str))
		{
			printf("%s ", str);
			strcpy(dict[k], "$-$");
		}
		
	int r, c;
	
	
	for(r=i-1;r<=i+1 && r<N;r++)
		for(c=j-1;c<=j+1 && c<M;c++)
			if(r>=0 && c>=0 && !visited[r][c])
				findWordsUtil(count, dict, N, M, visited, A, r, c, str);
				
	str[strlen(str) - 1]='\0';
	visited[i][j] = 0;
	
}
