#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "set.h"
#include "graph.h"


Graph* createGraph(int numNodes, int numEdges ){
	Graph *new_g;
	new_g = (Graph *)malloc(sizeof(Graph));
	new_g->numNodes = numNodes;
	new_g->numEdges = numEdges;
	new_g->edge = (Edge *)malloc(numEdges*sizeof(Edge));
	return new_g;
}


bool isCycle( Graph* graph , int numNodes, int numEdges){
	int i;
	int *A;
	Edge cur_e;
	
	A=(int *)malloc(numNodes*sizeof(int));
	for(i=0;i<numNodes;i++)
		A[i]=i;
		
	SIZE = numNodes;
	initializeMap(A);
	
	for(i=0;i<numEdges;i++)
	{
		cur_e = graph->edge[i];

		if(find(cur_e.src) == find(cur_e.dest))
			return 1;
		else
			Union(cur_e.src, cur_e.dest);
	}
	return 0;
}
