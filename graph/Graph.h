#ifndef GRAPH_H
#define GRAPH_H
#include"Public.h"

struct Node
{
	int vertex;
	Node* next;
	int weight;
};
void createGraph(FILE* fin,Node** graph,int &n);
void printGraph(Node** graph, int n);
void DFS(FILE* fout, Node** graph, int v,short int visited[]);
void BFS(FILE* fout, Node** graph, int v,short int visited[]);

#endif