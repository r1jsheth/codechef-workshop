/*input

*/
/**
 * Connect
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
	


int n;
int grid[55][55];
bool vis1[55][55] = {};
bool vis2[55][55] = {};


void dfs1(int x, int y){
	if(grid[x][y]) return;
	if(!vis1[x][y]){
		vis1[x][y] = 1;
		if(x<=n-1) dfs1(x+1,y);
		if(y<=n-1) dfs1(x,y+1);
		if(x>=2) dfs1(x-1,y);
		if(y>=2) dfs1(x,y-1);
	}
}
void dfs2(int x, int y){
	if(grid[x][y]) return;
	if(!vis2[x][y]){
		vis2[x][y] = 1;
		if(x<=n-1) dfs2(x+1,y);
		if(y<=n-1) dfs2(x,y+1);
		if(x>=2) dfs2(x-1,y);
		if(y>=2) dfs2(x,y-1);
	}
}


void solve(){
	cin >> n;
	int x,y,a,b;
	cin >> x >> y >> a >> b;
	vector<string> str(n+1);
	
	for (int i = 1; i < n+1; ++i){
		cin >> str[i];
	}

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			grid[i][j] = str[i][j-1]-'0';
		}
	}

	dfs1(x,y);
	dfs2(a,b);


	vector<pair<int,int>> firstList, secondList;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			if (vis1[i][j]){
				pair<int,int> curPair = make_pair(i,j);
				firstList.push_back(curPair);
			}
			if (vis2[i][j]){
				pair<int,int> curPair = make_pair(i,j);
				secondList.push_back(curPair);
			}
		}
	}


	int ans = INT_MAX;

	for(auto x : firstList){
		for(auto y : secondList){
			ans = min(ans, (x.F-y.F)*(x.F-y.F) + (x.S-y.S)*(x.S-y.S));
		}
	}
	

	cout << ans << endl;


}