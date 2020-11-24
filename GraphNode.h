#pragma once
class Graph;
class GraphNode	//link
{
private:
	int data;
	GraphNode* link;
	friend Graph;
public:
	GraphNode() {
		data = 0;
		link = 0;
	}
	~GraphNode() { }
};

