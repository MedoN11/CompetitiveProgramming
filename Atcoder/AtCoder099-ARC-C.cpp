#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include <deque>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include<vector>
#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<numeric>
using namespace std;
typedef vector<int> vi;
const int maxn = 705;
int n, m;
int adj[maxn][maxn];
int col[maxn];
int has[maxn][4];
int dp[maxn][maxn];
int ok = 1;
int comps = 0;


void dfs(int u) {
	++has[comps][col[u]];
	for (int v = 0 ; v < n ; ++v) {
		if (adj[u][v]) continue;
		if (u == v) continue;
		if (col[v] == -1) {
			col[v] = 1 ^ col[u];
			dfs(v);
		} else {
			if (col[u] != (1 ^ col[v])) {
				ok = 0;
			}

		}
	}

}

int gg(int x) {
	return (x) * (x - 1) / 2;
}

int solve(int ind,int b,int r) {

	if (ind == comps) {
		return gg(b) + gg(r);
	}

	int &ret = dp[ind][b];
	if (ret != -1) {
		return ret;
	}
	ret = 1 << 27;


	ret = min(ret,solve(ind + 1,b + has[ind][0], r + has[ind][1]));

	// make 1 b
	//cont = (has[ind][1] * b) / 2 + (has[ind][0] * r) / 2;

	ret = min(ret,solve(ind + 1,b + has[ind][1],r + has[ind][0]));
	//ret += gg(has[ind][0]) + gg(has[ind][1]);
	return ret;
}

int main() {
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		--u, --v;
		adj[u][v] = adj[v][u] = 1;
	}

	memset(col,-1,sizeof(col));
	memset(dp,-1,sizeof(dp));
	for (int i = 0 ; i < n ; ++i) {
		ok = 1;
		if (col[i] == -1) {
			col[i] = 0;
			dfs(i);
			++comps;
			if (!ok) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	//cerr << comps << endl;
	cout << solve(0,0,0);

}
