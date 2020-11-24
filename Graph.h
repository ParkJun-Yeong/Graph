#pragma once
#include "GraphNode.h"

typedef GraphNode* Nodeptr;
class Graph
{
private:
	Nodeptr* HeadNode;
	int size;
public:
	Graph(int);
	void insertEdge(int u, int v);
	void print();
	DFS();
};

