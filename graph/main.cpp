#include"Public.h"
#include"Graph.h"
#include"memory"


int main() {
	FILE* fin = fopen("input.txt","r");
	FILE* fout = fopen("output.txt", "w");



	Node** graph;
	MALLOC(graph,sizeof(Node*)*100,Node**);
	memset(graph, NULL, 100 * sizeof(Node*));
	
	short int visited[100];
	memset(visited, 0, 100*sizeof(short int));

	int n;
	createGraph(fin,graph,n);
	int v;
	while (fscanf(fin, "%d", &v), v != -1) {
		fprintf(fout, "DFS from v%d:", v);
		DFS(fout, graph, v, visited);
		fprintf(fout, "\n");
		memset(visited, 0, 100 * sizeof(short int));
	}
	fclose(fin);
	fclose(fout);
}