#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

#include "set.h"
#include "graph.h"
#define MAX 1000

int main(int argc, char const *argv[])
{
	/* code */
	int T, i, N, E, j, k;
	Graph *graph;
	Edge cur_e;
	int *A=(int *)malloc(MAX*sizeof(int));
	int *people; 
	
	scanf("%d", &T);
	int *min = (int *)malloc(T * sizeof(int));
	for(k=0;k<T;k++)
		min[k] = 1001;
	for(k=0;k<T;k++)
	{
		scanf("%d%d", &N, &E);
		graph = createGraph(N, E);
		for(j=0;j<E;j++)
			scanf("%d%d", &(graph->edge[j].src), &(graph->edge[j].dest));
		
		people=(int *)malloc((N+1)*sizeof(int));
		for(i=1;i<=N;i++)
			people[i]=i;
		
		SIZE = N+1;
		initializeMap(people);	
		
		for(j=0;j<E;j++)
		{
			cur_e = graph->edge[j];

			if(find(cur_e.src) == find(cur_e.dest))
				continue;
			else
				Union(cur_e.src, cur_e.dest);
		}
		for(j=1;j<=N;j++)
		{
			A[j]=cardinality(j);
			if(A[j]<min[k])
				min[k]=A[j];
		}
	}
	for(k=0;k<T;k++)
		printf("%d\n", min[k]);
	return 0;
}
