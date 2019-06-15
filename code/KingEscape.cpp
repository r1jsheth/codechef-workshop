/*input

*/
/**
 * King Escape
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
	int n;
	cin >> n;
	bool chessBoard[n+5][n+5];

	int queen_x, queen_y, king_x, king_y, dest_x, dest_y;
	cin >> queen_x >> queen_y >> king_x >> king_y >> dest_x >> dest_y;


	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			// king can move here
			chessBoard[i][j] = true;
		}
	}


	for (int i = 1; i <= n; ++i){
		chessBoard[queen_x][i] = false;
		chessBoard[i][queen_y] = false;
	}

	for (int i = 0; (queen_x + i <= n) and (queen_y + i <= n); ++i){
		chessBoard[queen_x + i][queen_y + i] = false;
	}

	for (int i = 0; (queen_x + i <= n) and (queen_y - i >= 1); ++i){
		chessBoard[queen_x + i][queen_y - i] = false;
	}

	for (int i = 0; (queen_x - i >= 1) and (queen_y + i <= n); ++i){
		chessBoard[queen_x - i][queen_y + i] = false;
	}

	for (int i = 0; (queen_x - i >= 1) and (queen_y - i >= 1); ++i){
		chessBoard[queen_x - i][queen_y - i] = false;
	}

	if (chessBoard[king_x][king_y] == false or
		chessBoard[dest_x][dest_y] == false){
		cout << "NO" << endl;
	}

	else if ((dest_x < queen_x and king_x < queen_x) || (dest_x > queen_x and king_x > queen_x)){
		if ((dest_y < queen_y and king_y < queen_y) || (dest_y > queen_y and king_y > queen_y)){
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	else cout << "NO" << endl;



}