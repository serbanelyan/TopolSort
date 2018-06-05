#include <stdio.h>
#include <stdlib.h>

int V, E, **adj;

void addEdge(int v, int w)
{
	adj[v][w] = 1;
	return;
}

void topologicalSortUtil(int v, int visited[], int stack[], int *stackSize) {

	visited[v] = 1;

	int i;
	for (i = 0; i< V; i++)
		if (adj[v][i] && !visited[i])
			topologicalSortUtil(i, visited, stack, stackSize);

	stack[(*stackSize)++] = v;
}

void topologicalSort() {

	int *stack, *visited, *stackSize, i ;

	stack = (int*)calloc(V, sizeof(int));
	visited = (int*)calloc(V, sizeof(int));
	stackSize = (int*)calloc(1, sizeof(int));

	for (i = 0; i < V; i++)
		if (visited[i] == 0)
			topologicalSortUtil(i, visited, stack, stackSize);

	if (*stackSize) {
		printf("\nA Topological Sort of the given graph is ");

		while (*stackSize)
		{
			printf("%d ", stack[--(*stackSize)]);
		}

		printf("\n");
	}
	else printf("\nError using Topological Sort: Empty Graph\n");
}

void readValues() {
	printf("Number of vertices = ");
	scanf("%d", &V);

	printf("Number of arcs = ");
	scanf("%d", &E);


	int i;
	adj = (int**)calloc(V, sizeof(int*));
	for (i = 0; i < V; i++)
		adj[i] = (int*)calloc(V, sizeof(int));


	for (i = 0; i < E; i++)
	{
		int first, last;

		printf("\n[%d]", i + 1);
		do {
			printf("\nStarting point: ");
			scanf("%d", &first);
		} while (first < 0 || first > V);

		do {
			printf("Ending point: ");
			scanf("%d", &last);
		} while (last < 0 || last > V);

		addEdge(first, last);
	}
}
