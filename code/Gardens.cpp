/*input
 
*/
/**
 * Utkarsh in Gardens
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
}
const int N = 2000+10;
bitset<N> g[N];
void solve(){
	int n, x;
	cin >> n;
	bool grid[n][n]={};
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			cin >> x;
			g[i][j] = x;
		}
	}
	int ans = 0, cnt = 0;
	for (int i = 1; i <= n-1; ++i){
		for (int j = i+1; j <= n; ++j){
			cnt = (g[i]&g[j]).count();
			ans += cnt*(cnt-1)/2;
		}
	}
	cout << ans/2 << endl;
}