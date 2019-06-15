/*input

*/
/**
 * Network Topology
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
	
	while(T--){
		solve();
	}
	cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << endl;
	return 0;
}
void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for (int i = 0; i < m; ++i){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}





	map<int, int> degreeCnt;
	for (int i = 1; i <= n; ++i){
		int curDegree  = adj[i].size();
		degreeCnt[curDegree]++;
		// cout << adj[i].size() << " ";
	}



	if (degreeCnt.size() == 1 and degreeCnt[2] >= 1){
		cout << "ring topology" << endl;
	}
	else if (degreeCnt.size() == 2 and degreeCnt[1] == 2 and degreeCnt[2] == n-2)	{
		cout << "bus topology" << endl;
	}
	else if (degreeCnt[n-1] == 1 and degreeCnt[1] == n-1)	{
		cout << "star topology" << endl;
	}
	else cout << "unknown topology" << endl;
	
}