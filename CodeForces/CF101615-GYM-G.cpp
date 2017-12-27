
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
#include <unordered_map>
using namespace std;
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
const int maxn = 1001;
vector<pii> g[maxn];
int L[5001],R[5001];
bool vis[5001];
int n,m,k;
int s,t;
vector<pii> res;
typedef pair<int,pii> triple;
int ok = 0;
void dfs(int u,int r) {
	if(u == t) {
		ok = 1;
		return;
	}
	if(vis[u])
		return;
	vis[u] = 1;
	REP(i,g[u]) {
		int v = g[u][i].first, ind = g[u][i].second;
		if(r >= L[ind] && r <= R[ind])
			dfs(v,r);
	}
}

int main() {
	ios
	cin >> n >> m >> k;
	cin >> s >> t;
	--s,--t;
	int u,v,l,r;
	set<int> poss;
	for (int i = 0 ; i < m ; ++i) {
		cin >> u >> v >> l >> r;
		--u,--v;
		g[u].pb(pii(v,i));
		L[i] = l, R[i] = r;
		poss.insert(l);
		poss.insert(r + 1);
	}
	vector<int> ranges;

	for(set<int>::iterator it = poss.begin(); it != poss.end() ;it++) {
		ranges.pb(*it);
	}
	ll ans = 0;
	int nxt = -1;
	REP(i,ranges) {
		memset(vis,0,sizeof(vis));
		ok = 0;
		dfs(s,ranges[i]);
		if(!ok)
			continue;
		if(i == sz(ranges) - 1) {
			nxt = k + 1;
		}
		else nxt = ranges[i + 1];
		ans += 1LL*nxt - ranges[i];
	}

	cout << ans << "\n";

}x
