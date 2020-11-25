#pragma once
#include "mGraphNode.h"

class mGraph
{
private:
	mGraphNode** array;
	bool* visited;
	int size;
public:
	mGraph(int);
	void insert(int,int);
	void DFS(int);
	void BFS(int);

};

