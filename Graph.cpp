#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int n) {
	size = n;
	HeadNode = new GraphNode* [size];
	for (int i; i < size; i++) {
		HeadNode[i] = 0;
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
	while (1) {
		if (!pop()) break;
		if (!p) p = stack.pop();
		
		if(!visited[p->data]) {
			cout << p->data << '\t';
			visited[p->data] = true;
			stack.push(p);
			p = HeadNode[p->data];
		}
		else p = p->link;

	}

}
