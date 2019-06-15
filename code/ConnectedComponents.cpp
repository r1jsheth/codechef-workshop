/*input
7 8
1 2
2 3
3 4
3 5
4 5
4 6
4 7
5 6

*/
/**
 * Connected Components
 * Raj
 /******************************/
 /*    Fight Till Victory!     */
 /******************************/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cstdio>
#include <cstring>
#include <cmath> 										
#include <cstring>										
#define endl '\n'										
#define lli long long int
#define vi vector<int>
#define mod 1000000007
#define MOD 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define pb(n) push_back(n)
#define F first
#define S second
#define int long long int
#define double long double
using namespace std;
void solve();
int32_t main(){
	time_t start = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	cin >> T;
	while(T--){
		solve();
	}
	cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << endl;
	return 0;
}

const int N = 1e3+5;
vector<int> graph[N];
vector<bool> visited(N,false);

void dfs(int source){
	visited[source] = 1;
	for(int i = 0 ; i < graph[source].size() ; ++i){
		int curNode = graph[source][i];
		if(!visited[curNode]){
			dfs(curNode);
		}
	}

}


void solve(){
	int nodes, edges;
	cin >> nodes >> edges;
	

	for (int i = 0; i < edges; ++i){
		int x,y;
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}


	int connectedComponents = 0;
	for (int i = 0; i < nodes; ++i){
		if(!visited[i]){
			connectedComponents++;
			dfs(i);
		}
	}
	cout << connectedComponents << endl;
}