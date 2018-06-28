#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include <random>
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
#include <unordered_map>
#include<numeric>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
typedef pair<ll,ll> pii;
typedef pair<pii,int> tri;

// Greedy
// It's clear that it's optimal to always color edges closer to the root as possible ( can never make the answer worse).
// a tricky part is to decide if there are any bad nodes belonging to a child of a node
// for this store the worst node in an array, and check if it become good, otherwise color.
int n;
const int maxn = 200005;
vector<tri> tree[maxn];
int dp[maxn];
bool bad[maxn];
pair<int,pii> far[maxn];
int dfs(int u,int good,int tot,int p) {
	int ret = 0;
	if ((tot + 1) / 2 > good) ++ret,bad[u]=1;

	REP(i,tree[u]) {
		int v = tree[u][i].first.first;
		if (v == p) {
			continue;
		}
		ret += dfs(v,good + tree[u][i].first.second,tot + 1,u);
	}

	return dp[u] = ret;
}
pair<int,pii> upd(pair<int,pii> a, pair<int,pii> b) {
	if (a.first < b.first) {
		return b;
	}
	return a;
}
pair<int,pii> dfs2(int u,int good,int tot,int p) {
	far[u] = make_pair(max(0,(tot + 1) / 2 - good),pii(good,tot));
	REP(i,tree[u]) {
		int v = tree[u][i].first.first;
		if (v == p) {
			continue;
		}
		far[u] = upd(far[u],dfs2(v,good + tree[u][i].first.second,tot + 1,u));
	}
	return far[u];
}
vector<int> sol;
void solve(int u,int good,int tot,int p,int up,int fix) {
	if ((good) >= (tot + 1) / 2 && bad[u]) --dp[u];
	if (dp[u] && up && far[u].first) {
		if ((far[u].second.second + 1) / 2 > (far[u].second.first + fix)) {
			--dp[u];
			++good;
			sol.pb(up);
			fix++;
		}
	}

	REP(i,tree[u]) {
		int v = tree[u][i].first.first;
		if (v == p) {
			continue;
		}
		int c = 0;
		if (!tree[u][i].first.second) c = tree[u][i].second;
		solve(v,good + tree[u][i].first.second,tot + 1,u,c,fix);
	}

}
int main() {
	ios
	cin >> n;
	string s;
	for (int i = 0 ; i < n - 1 ; ++i) {

		int u,v;
		cin >> u >> v >> s;
		--u,--v;
		int f = 0;
		if (s == "protected") {
			f = 1;
		} else {
			cin >> s;
		}

		tree[u].pb(tri(pii(v,f),i + 1));
		tree[v].pb(tri(pii(u,f),i + 1));

	}


	dfs(0,0,0,-1);
	dfs2(0,0,0,-1);
	solve(0,0,0,-1,0,0);
	cout << sz(sol) << "\n";
	REP(i,sol) cout << sol[i] <<" ";


}
