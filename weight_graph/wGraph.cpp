#include "wGraph.h"
#include <stack>
#include <iostream>
#define _MAX_INT 50000
using namespace std;

wGraph::wGraph() { n = 0; m = 0; graph = 0; }
void wGraph::set(int n, int m) {
	int i,j;
	this->n = n;
	this->m = m;
	graph = new wgraphNode *[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			graph[i] = new wgraphNode[n];
	
	for (i = 0; i < n; i++)		//initailization
		for (j = 0; j < n; j++)
			graph[i][j].weight = _MAX_INT;
}
void wGraph::insert(int u, int v, int w) {
	graph[u][v].weight = w;
}
void wGraph::shortest_path(int s) {
	//variable definition
	int* path = new int[n];
	for (int i = 0; i < n; i++)
		path[i] = s;
	bool* check = new bool[n] {false}; //checking already chosen vertex
	int* dist = new int[n];
	for (int i = 0; i < n; i++)
		dist[i] = graph[s][i].weight;
	check[s] = true;

	//finding shortest path
	//int u = 0;//s, p = 0;
	for (int i = 0; i < n - 2; i++) {
		//p = u;
		int u = chosen(dist,check);
		check[u] = true;
		renewal(u, dist, path);
	}

	//print result;
	result(dist, path, s);
	
	delete[] path;
	delete[] dist;
	delete[] check;
}
int wGraph::chosen(int* a, bool* ch) {
	int min = _MAX_INT;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (min > a[i] && !ch[i]) {	
			min = a[i];	
			j = i;	
		}
	}
	return j;
}
void wGraph::renewal(int u,int* dist,int* path) {
	wgraphNode** length = graph;
	for (int i = 0; i < n; i++) {
		if (dist[i] > dist[u] + length[u][i].weight) {
			dist[i] = dist[u] + length[u][i].weight;
			path[i] = u;
		}

	}
}
void wGraph::result(int* dist, int* path, int start) {
	stack<int> stack;

	cout << "<dist>" << endl;
	for (int i = 0; i < n; i++) {
		cout << dist[i] << ' ';
	}
	
	cout << endl;

	cout << "<shortest path>" << endl;
	for (int i = 0; i < n; i++) {
		int j = i;	//j is destination
		while(j != start /*&& (j != _MAX_INT)*/){
			stack.push(j);
			//stack.push(path[j]);
			j = path[j];
		}
		stack.push(start);
		cout << start << " -> " << i << ": ";
		while (!stack.empty()) {
			cout << stack.top() << ' ';
			stack.pop();
		}
		cout << endl;
	}

}
wGraph::~wGraph() { delete[] graph; }
