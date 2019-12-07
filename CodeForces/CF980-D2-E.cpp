#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
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
#include<numeric>
using namespace std;
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
const int maxn = 1000005;
#define ios std::ios_base::sync_with_stdio(false);
vector<int> sol;
int n, k;
vector<int> tree[maxn];
bool mark[maxn];
int dp[21][maxn];
int pr[maxn];
int L[maxn];
int rem;

// Trees
// Binary lifting + greedy
// Check CF editorial for more details.
void dfs(int u) {
	REP(i,tree[u])
	{
		int v = tree[u][i];
		if (pr[u] == v) {
			continue;
		}
		pr[v] = u;
		L[v] = L[u] + 1;
		dfs(v);
	}
}
int solve(int u, int k) {
	if (k == 0) {
		return pr[u];
	}
	int &ret = dp[k][u];
	if (ret != -1) {
		return ret;
	}
	return ret = solve(solve(u, k - 1), k - 1);

}
int getKthPar(int u,int pw) {
	int cur = u;
	for (int i = 0 ; i <= 20 ; ++i) {
		if (pw & (1 << i)) {
			cur = solve(cur,i);
		}
	}
	return cur;
}
void lol(int ind) {
	int tmp = ind;
	int bad = ind;
	for (int k = 20 ; k >= 0 ; --k) {
		int up = solve(ind, k);
		if (!mark[up]) {
			ind = up;
			bad = up;
		}
	}
	bad = pr[bad];
	int d = L[tmp] - L[bad];
	//cerr << (tmp+1) << " " << bad+1 << " " << d << endl;
	if (d <= rem) {
		rem -= d;
	//	cerr << "YES\n";
		do {
			mark[tmp] = true;
			tmp = pr[tmp];
			//cerr << tmp << " " << bad << endl;
		} while (tmp != bad);
	}
}

int main() {
	memset(dp,-1,sizeof(dp));
	cin >> n >> k;
	int u,v;
	for (int i = 0; i < n - 1; ++i) {
			scanf("%d %d",&u,&v);
			--u,--v;
			tree[u].pb(v);
			tree[v].pb(u);
		}
	pr[n - 1] = n - 1;
	dfs(n - 1);
	rem = n - k;
	mark[n - 1] = true;
	--rem;
	sol.pb(n - 1);

	for (int i = n - 2; i >= 0; --i) {
		if (mark[i]) {
			continue;
		}
		lol(i);
	}
	for (int i = 0 ; i < n ; ++i) {
		if (!mark[i]) {
			printf("%d ", i + 1);
		}
	}

}
