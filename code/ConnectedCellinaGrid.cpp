/*input

*/
/**
 * Connected Cell in grid Grid
 * Raj
 /******************************/
/*    Fight Till Victory!     */
/******************************/
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
#define lli long long int
#define vi vector<int>
#define mod 1000000007
#define MOD 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(grid, val) memset(grid, val, sizeof(grid))
#define pb(n) push_back(n)
#define F first
#define S second
#define int long long int
#define double long double
using namespace std;
void solve();
int32_t main() {
  time_t start = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;

  while (T--) {
    solve();
  }
  cerr << fixed << setprecision(6)
       << "Time: " << 1.0 * (clock() - start) / CLOCKS_PER_SEC << endl;
  return 0;
}

int countCurrent(vector<vector<int>> &grid, int i, int j, int n, int m) {

  if (i >= n || i < 0 || j >= m || j < 0)
    return 0;
  if (grid[i][j] == 0)
    return 0;

  int curAns = grid[i][j]--;
  curAns += countCurrent(grid, i + 1, j + 1, n, m);
  curAns += countCurrent(grid, i - 1, j - 1, n, m);
  curAns += countCurrent(grid, i - 1, j, n, m);
  curAns += countCurrent(grid, i + 1, j, n, m);
  curAns += countCurrent(grid, i, j - 1, n, m);
  curAns += countCurrent(grid, i, j + 1, n, m);
  curAns += countCurrent(grid, i - 1, j + 1, n, m);
  curAns += countCurrent(grid, i + 1, j - 1, n, m);

  return curAns;
}

int dfs(vector<vector<int>> grid, int n, int m) {
  int res = INT_MIN;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        int cur = countCurrent(grid, i, j, n, m); 
        // cout << cur << endl;
        res = max(res, cur);
      }
    }
  }
  return res;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      grid[i][j] = x;
    }
  }
  cout << dfs(grid, n, m) << endl;
}