/*input

*/
/**
 * FENCE
 * Raj
 /******************************/
 /*    Fight Till Victory!     */
 /******************************/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cstdio>
#include <cstring>										
#define endl '\n'										
#define lli long long int
#define vi vector<int>
#define mod 1000000007
#define MOD 1000000007
#define inf 1000000000000000001
#define all(col) col.begin(),col.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define pb(n) push_back(n)
#define F first
#define S second
#define int long long int
#define double long double
using namespace std;
void solve1();
void solve2();
int32_t main(){
	time_t start = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	cin >> T;
	while(T--){
		solve2();
	}
	cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << endl;
	return 0;
}

// Approach 1
void solve1(){
	int n, m, k;
	cin >> n >> m >> k;
	int grid[n+2][m+2]={};
	for (int i = 0; i < k; ++i){
		int row,col;
		cin >> row >> col;
		grid[row][col] = 1;
	}
	int fence = 0;
	for (int i = 0; i < n+1; ++i){
		for (int j = 0; j < m+1; ++j){
			if (grid[i][j]){
				if (grid[i-1][j] == 0)
					fence++;
				if (grid[i][j-1] == 0)
					fence++;
				if (grid[i][j+1] == 0)
					fence++;
				if (grid[i+1][j] == 0)
					fence++;
			}
		}
	}
	cout << fence << endl;
}


// Approach 2
void solve2(){
	int n, m, k;
	cin >> n >> m >> k;
	map<pair<int,int>, int> M;
	for (int i = 0; i < k; ++i){
		int row, col;
		cin >> row >> col;
		M[make_pair(row,col)]++;
	}
	int fence = 0;
	pair<int,int> curPair;
	
	for(auto x : M){
		int row = x.first.first, col = x.first.second;
		

		curPair = make_pair(row,col-1);
		if (M.find(curPair) == M.end())
			fence++;


		curPair = make_pair(row-1,col);
		if (M.find(curPair) == M.end())
			fence++;


		curPair = make_pair(row+1,col);
		if (M.find(curPair) == M.end())
			fence++;


		curPair = make_pair(row,col+1);
		if (M.find(curPair) == M.end())
			fence++;
	

	}
	cout << fence << endl;
}