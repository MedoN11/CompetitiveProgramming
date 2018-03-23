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
#define F first
#define S second
#define MP make_pair
const int maxn = 10005;
double eps = 1e-12;
long long n,T;
// Euler Tour
// Treat each matrix as an edge
struct OrderDoesMatter {
	int getOrder(vector<int> a,vector<int> b);
};
vector<int> g[maxn];
vector<int> un[maxn];
bool seen[maxn];
int in[maxn],out[maxn];
int c = 0;
void dfs(int u) {
	if(seen[u]) {
		return;
	}
	seen[u] = 1;
	++c;
	REP(i,un[u]) dfs(un[u][i]);
}
int OrderDoesMatter::getOrder(vector<int> a,vector<int> b) {
	int s = -1, t = -1;
	bool ok = 1;
	set<int> nodes;
	REP(i,a) {
		nodes.insert(a[i]);
		nodes.insert(b[i]);
		g[a[i]].pb(b[i]);
		un[a[i]].pb(b[i]);
		un[b[i]].pb(a[i]);
		out[a[i]]++;
		in[b[i]]++;

	}
	dfs(a[0]);
	if(c != sz(nodes)) return -1;
	for (int i = 0 ; i < 1001 ; ++i) {
		if(nodes.find(i) == nodes.end())
			continue;
		ok &= in[i] == out[i];
		if(in[i] == out[i]) continue;
		if(in[i] == 1 + out[i]) {
			if(t == -1) t = i;
			else return -1;

			continue;
		}
		if(in[i]  + 1 == out[i]) {
			if(s == -1) s = i;
			else return -1;
			continue;
		}
		return -1;
	}
	if(ok){
		int res = 0;
		REP(i,a) {
			res = max(res,a[i]*a[i]);
		}
		return res;
	}
	return s * t;

}
