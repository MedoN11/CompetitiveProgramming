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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair< long double,long double> pdd;
#define F first
#define S second
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define mp make_pair
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define for1LL(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define fornLL(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define ld long double
const int maxn = 10005;
int n,m;
vector<int> g[maxn];
int dfs_low[maxn],dfs_num[maxn];
vector<pii> res;
int tim = 0;
void dfs(int u,int p,bool root = 0) {

	dfs_num[u] = dfs_low[u] = tim++;
	int tot = 1;
	bool art = 0;
	int childs = 0;
	REP(i,g[u]) {
		int v = g[u][i];
		if(dfs_num[v] == -1) {
			++childs;
			dfs(v,u,0);
			if (dfs_low[v] >= dfs_num[u]) {
				++tot;
				art = 1;
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		} else {
			if (v != p)
				dfs_low[u] = min(dfs_num[v],dfs_low[u]);
		}
	}
	art |= root && childs >= 2;
	if (art && !root) {
		res.pb(pii(tot,-u));
	} else {
		if(root && art) {
			res.pb(pii(childs,-u));
		}  else {
			res.pb(pii(1,-u));
		}
	}
}
int main() {
	while(scanf("%d %d",&n,&m)) {
		if(n + m  == 0)
			break;
		int u,v;
		res.clear();
		forn(i,n) {
			g[i].clear(),dfs_low[i]=-1,dfs_num[i]=-1;
		}
		tim = 0;
		while (scanf("%d %d",&u,&v) && u != -1 && v != -1) {
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0,-1,1);
		sort(rall(res));
		forn(i,m) {
			printf("%d %d\n",-res[i].S,res[i].F);
		}
		puts("");
	}




}


