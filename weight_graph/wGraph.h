#pragma once
#include "wgraphNode.h"

class wGraph
{
private:
	int n, m;
	wgraphNode** graph;
	int chosen(int*, bool*);
	void renewal(int, int*, int*);
	void result(int*, int*, int);

public:
	wGraph();
	void set(int,int); //allocate array using n,m
	void insert(int, int, int); //set edge using u,v,w
	void shortest_path(int);
	~wGraph();
};

