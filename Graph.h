#pragma once
#include "GraphNode.h"

typedef GraphNode* Nodeptr;
class Graph
{
private:
	Nodeptr* HeadNode;
	bool* visited;
	int size;
public:
	Graph(int);
	void insertEdge(int u, int v);
	void print();
	void DFS(int);
	void BFS(int);
};

