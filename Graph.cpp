#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int n) {
	size = n;
	HeadNode = new GraphNode* [size];
	visited = new bool[size];
	for (int i = 0; i < size; i++) {
		HeadNode[i] = 0;
		visited[i] = false;
	}
}
void Graph::insertEdge(int u, int v) {
	GraphNode* p = new GraphNode;
	p->data = u;
	p->link = HeadNode[v];
	HeadNode[v] = p;

	p = new GraphNode;
	p->data = v;
	p->link = HeadNode[u];
	HeadNode[u] = p;

	delete p;
}
void Graph::print() {

	for (int i = 0; i < size; i++) {
		cout << "vertex connected  with " << i << " : ";
		for(GraphNode* p = HeadNode[i];p->data; p = p->link)
			cout << p->data << '\t';
		cout << '\n';
	}
}
void Graph::DFS(int u) {
	GraphNode* p = HeadNode[u];
	visited[u] = true;
	cout << u << '\t';
	
	for(;p; p = p->link) {
		//alternate codes of line 41,42
		//stack.pop --> recursion
		//if (!pop()) break;
		//if (!p) p = stack.pop();
		int w = p->data;
		if(!visited[w]) {
			cout << w << '\t';
			DFS(w);

			//visited[p->data] = true;
			//stack.push(p);
			// alternate codes of line 46,47 to line 45
		}
	}
}

void Graph::BFS(int u) {
	GraphNode* p = HeadNode[u];
	for (int i = 0; i < size; i++) visited[i] = false;
	
	visited[u] = true;
	q.push(p);

	while (!q.IsEmpty()) {
		p = HeadNode[q.pop()];
		for (; p; p = p->link) {
			if (!visited[p->data]) {
				cout << p->data << '\t';
				q.push(p);
			}
		}
	}
}


