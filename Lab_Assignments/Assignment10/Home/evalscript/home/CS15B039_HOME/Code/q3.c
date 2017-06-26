#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"
#include "List.h"
#include "queue.h"

typedef struct edge_
{
	int *source, *dest;
	int *weight;
}edge;

void longest_dist(LList **, edge *, int, int, int);
int getWeight(edge *, int, int, int);

int main(int argc, char const *argv[])
{
	/* code */
	
	int N, M, S, i, src, dst, len;
	scanf("%d%d%d", &N, &M, &S);
	
	LList** lst;
	lst = (LList **)malloc((N+1)*sizeof(LList *));
	edge *Edge = (edge *)malloc(sizeof(edge));
	Edge->source = (int *)malloc(M * sizeof(int));
	Edge->dest = (int *)malloc(M * sizeof(int));
	Edge->weight = (int *)malloc(M * sizeof(int));
		
	for(i=0;i<N;i++)
	{
		lst[i] = llist_new();
	}
	for(i=0;i<M;i++)
	{
		scanf("%d%d%d", &Edge->source[i], &Edge->dest[i], &Edge->weight[i]);
		llist_append(lst[Edge->source[i]], Edge->dest[i]);
	}
	
	longest_dist(lst, Edge, N, M, S);
	return 0;
}

void longest_dist(LList **lst, edge *E, int N, int M, int S)
{
	int *dist = (int *)malloc(N * sizeof(int));
	int *visited = (int *)malloc(N * sizeof(int));
	int i, temp,cur;
	
	for(i=0;i<N;i++)
		dist[i] = INT_MIN;
	dist[S] = 0;
	
	queue *q = queue_new();
	enqueue(q, S);
	while(!queue_is_empty(q))
	{
		cur = dequeue(q);
		visited[cur]=1;
		for(i=0;i<llist_size(lst[cur]);i++)
		{
			temp = llist_get(lst[cur], i);
			if(dist[temp] < dist[cur] + getWeight(E, M, cur, temp))
			{
				dist[temp] = dist[cur] + getWeight(E, M, cur, temp);
				enqueue(q, temp);
			}
			if(!visited[temp])
				enqueue(q, temp);
		}
	}
	for(i=0;i<N;i++)
		if(dist[i] == INT_MIN)
			printf("%s ", "INF");
		else
			printf("%d ", dist[i]);
	printf("\n");
}

int getWeight(edge *E, int M, int src, int dst)
{
	int i;
	for(i=0;i<M;i++)
		if(E->source[i]==src && E->dest[i]==dst)
			return E->weight[i];
}	
