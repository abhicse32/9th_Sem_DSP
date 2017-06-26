#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "List.h"
#include "queue.h"

void topological_sort(LList **, int);
int sort(LList **, int, int *, int);

int main(){
	int N, M, i, a, b;
	
	scanf("%d%d", &N, &M);
	LList** lst;
	lst = (LList **)malloc((N+1)*sizeof(LList *));
	
	for(i=1;i<=N;i++)
	{
		lst[i] = llist_new();
	}
	
	for(i=0;i<M;i++)
	{
		scanf("%d%d", &a, &b);
		llist_append(lst[a], b);
		llist_append(lst[b], a);
	}
	topological_sort(lst, N);
	
}

void topological_sort(LList** lst, int size)
{	
	int N, i, cur, j, flag;
	
	N=size; 
	int *visited = (int *)malloc((N+1)*sizeof(int));
	
	for(i=1;i<=N;i++)
	{
	        if(!visited[i])
	        {
	                flag=sort(lst, i, visited, -1);
	                if(flag==0)
	                {
	                        printf("%s\n", "NO");
	                        return;
	                }
	        }
	}
	printf("%s\n", "YES");
	      return;
	//stack_print(st);
	//printf("\n");
}

int sort(LList **lst, int i, int *visited, int parent)
{
        int j, cur, flag;
        //printf("%di\n", i);
        flag=1;
        visited[i]=1;
        for(j=0;j<llist_size(lst[i]);j++)
        {
                cur = llist_get(lst[i], j);
                
                if(!visited[cur])
                {
                       flag=sort(lst, cur, visited, i);
                       //return 1;
                }
                
                else if(cur==parent)
	                continue;
                else
                	return 0;
        }
        return (1);
}
