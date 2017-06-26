#include <stdio.h>
#include <stdbool.h>

#include "set.h"
#include "graph.h"

int main(int argc, char const *argv[])
{
	/* code */
	int T, i, N, E, j;
	Graph *graph;
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d", &N, &E);
		graph = createGraph(N, E);
		for(j=0;j<E;j++)
			scanf("%d%d", &(graph->edge[j].src), &(graph->edge[j].dest));	
		if(isCycle(graph, N, E)==1)
		    printf("%s", "true\n");
		else
		    printf("%s", "false\n");
	}
	return 0;
}
