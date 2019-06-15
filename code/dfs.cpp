/**
 * DFS
 * Raj
 /******************************/
 /*    Fight Till Victory!     */
 /******************************/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> visited(101,0);
vector<int> graph[101];


void dfs(int source){
	cout << source << endl;
	visited[source] = 1;
	for(int i = 0 ; i < graph[source].size() ; ++i){
		int currentVertex = graph[source][i];
		if (!visited[currentVertex]){
			dfs(currentVertex);
		}
	}
}


int32_t main(){
	int nodes, edges;
	cin >> nodes >> edges;
	for (int i = 0; i < edges; ++i){
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(2);
	return 0;
}