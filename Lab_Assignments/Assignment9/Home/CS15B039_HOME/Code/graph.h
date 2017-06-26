#ifndef GRAPH_H
#define GRAPH_H

typedef struct Graph_ Graph;
typedef struct Edge_ Edge ;

struct Edge_
{
	int src ;
	int dest ;
};

struct Graph_
{
	int numNodes ;
	int numEdges ;
	Edge* edge ;
};

//Create an empty graph structure
Graph* createGraph(int V, int E) ;


bool isCycle( Graph* graph , int numNodes, int numEdges);

#endif