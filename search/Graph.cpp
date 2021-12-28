#include"Graph.h"
#include"Public.h"
#include"Queue.h"
void createGraph(FILE* fin, Node** graph, int& n)
{
	int n1, m;
	fscanf(fin, "%d %d", &n1,&m);
	n = n1;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		fscanf(fin,"%d %d %d", &a, &b, &c);
		Node* t;
		MALLOC(t, sizeof(Node), Node*);
		t->next = graph[a];
		t->vertex = b;
		t->weight = c;
		graph[a] = t;    
	}
}

void printGraph(Node** graph, int n)
{
	Node* t;
	for (int i = 0; i < n; i++) {
		printf("%d ", i);
		t = graph[i];
		while (t!=NULL) {
			printf("%d ", t->vertex);
			t = t->next;
		}
		printf("\n");
	}
}

void DFS(FILE* fout, Node** graph, int v, short int visited[])
{
	Node* t;
	visited[v] = 1;
	for (t = graph[v]; t != NULL; t = t->next) {
		if (!visited[t->vertex]) {
			fprintf(fout, "v%d ", t->vertex);
			DFS(fout, graph, t->vertex, visited);
		}
	}
}

void BFS(FILE* fout, Node** graph, int v, short int visited[])
{
	Queue queue = createQueue();
	Node* t;
	visited[v] = 1;
	EnQuque(queue, v);
	while (!isEmpty(queue)) {
		v = DeQueue(queue);
		for (t = graph[v]; t != NULL; t = t->next) {
			if (!visited[t->vertex]) {
				fprintf(fout, "v%d ", t->vertex);
				EnQuque(queue, t->vertex);
				visited[v] = 1;
			}
		}
	}
}