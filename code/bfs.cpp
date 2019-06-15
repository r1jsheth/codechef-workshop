/*input
6
8
1 2
1 3
2 4
2 5
4 5
3 5
4 6
5 6

*/


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


void bfs(int source){
	
	list<int> q;
	q.push_back(source);
	visited[source] = 1;
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop_front();
		cout << curNode << " ";

		for (int i = 0; i < graph[curNode].size(); ++i){
			int neighbour = graph[curNode][i];
			if(!visited[neighbour]){
				visited[neighbour] = 1;
				q.push_back(neighbour);
			}
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
	bfs(1);
	cout << endl;
	return 0;
}