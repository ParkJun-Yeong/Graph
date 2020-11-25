#pragma once
class mGraph;
class mGraphNode
{
private:
	int data;
	friend mGraph;
public:
	mGraphNode() { data = 0; }
};

