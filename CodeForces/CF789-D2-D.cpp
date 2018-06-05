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
#include <unordered_map>
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
#define F second.first
#define S second.second
#define MP make_pair
// Graphs - Euler Tour
// Problem can be phrased as
// Given a graph with even degree for each node
// remove exactly 2 edges so an euler tour exists
int n,m;
const int maxn = 1000006;
vector<pii> edges;
int d[maxn];
vector<int> g[maxn];
bool vis[maxn];
bool f[maxn];
static int comps = 0;
void dfs(int u) {
	if (vis[u]) {
		return;
	}
	++comps;
	vis[u] = true;
	REP(i,g[u]) {
		int v = g[u][i];
		if (!vis[v])
			dfs(v);
	}
}


int main() {
	scanf("%d %d",&n,&m);

	int u,v;
	ll cyc = 0;
	for (int i = 0 ; i < m ; ++i) {
		scanf("%d %d",&u,&v);
		--u;
		--v;
		g[u].pb(v);
		g[v].pb(u);
		edges.pb(pii(u,v));
		if (u == v) {
			++cyc;
			f[u] = true;
			continue;

		}
		++d[u];
		++d[v];


	}

	dfs(edges[0].first);

	ll ways = 0;
	REP(i,edges) {
		pii e = edges[i];
		int u = e.first, v = e.second;
		if (!vis[u] || !vis[v]) {
			return puts("0");
		}
		if (u == v) {
			continue;
		}
		ways += 1LL*d[u] - 1;
		ways += 1LL*d[v] - 1;
	}
	ways /= 2;
	for (int i = 0 ; i < n ; ++i) {
		if (f[i]) {
			ways += 1LL*m - 1;
		}
	}

	ways -= 1LL*(cyc) * (cyc - 1) / 2;
	cout << ways << "\n";

}
