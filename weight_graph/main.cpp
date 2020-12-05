#include <iostream>
#include "wGraph.h"
using namespace std;

int main() {
	int n, m; //the number of vertices and edges
	int u, v, weight;
	int start;
	wGraph g;

	//input
	cout << "정점 수 와 간선 수 입력> ";
	cin >> n >> m;
	g.set(n, m);

	for (int i = 0; i < m; i++) {
		cout << i + 1 << "번째 간선과 가중치 입력> ";
		cin >> u >> v >> weight;
		
		if (weight < 0) {
			cout << "warning: weight must be positive integer" << endl;
			i--; //re-input weight
		}
		else g.insert(u, v, weight);

	}

	cout << "시작 정점 입력> ";
	cin >> start;

	//ouput result
	g.shortest_path(start);

}