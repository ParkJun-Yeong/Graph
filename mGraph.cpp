#include "mGraph.h"
mGraph::mGraph(int n) {
	size = n;
	array = new mGraphNode * [size];
	visited = new bool[size];
	for (int i = 0; i < size; i++) {
		array[i] = new mGraphNode[size];	//difference
		visited[i] = 0;
	}
}

void mGraph::insert(int u, int v) {
	array[u][v].data = 1;
	array[v][u].data = 1;	//in undirected graph
}

void mGraph::DFS(int w) {
	visited[w] = true;

	for (int i = 0; i < size; i++) {
		if (array[w][i].data && !visited[i]) {
			visited[i] = true;
			DFS(i);
		}
	}
}

void mGraph::BFS(int u) {
	int i;
	for (i = 0; i < size; i++) visited[i] = 0;
	visited[u] = true;
	q.push(u);

	while (!q.IsEmpty()) {
		u = q.pop();
		for (i = 0; i < size; i++) {
			if (array[u][i].data && !visited[i]) {
				cout << i << '\t';
				visited[i] = true;
				q.push(i);
			}
		}

	}
}
