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
const int maxn = 60;
double dis[maxn];
int n,m,t;
typedef pair<pii,int> triple ;
vector<triple> edges;
const int inf = 1 << 29;

// minimum average cycle
bool negative_cycle(double c) {
	fill(dis,dis + maxn,inf);
	dis[0] = 0;
	for (int i = 0 ; i < n - 1; ++i) {
		REP(j,edges) {
			int u = edges[j].first.first, v = edges[j].first.second;
			double cost = edges[j].second;
			cost -= 1.0*c;
			if(dis[u] + cost < dis[v]) dis[v] = dis[u] + cost;


		}
	}
	REP(j,edges) {
		int u = edges[j].first.first, v = edges[j].first.second;
		double cost = edges[j].second;
		cost -= 1.0*c;
		if(dis[u] + cost < dis[v]) return 1;
	}

	return 0;
}
int main() {
	scanf("%d",&t);
	int tc = 1;
	while(t--) {
		edges.clear();
		scanf("%d %d",&n,&m);
		while(m--) {
			int u,v,c;
			scanf("%d %d %d",&u,&v,&c);
			--u,--v;
			edges.pb(triple(pii(u,v),c));
		}
		printf("Case #%d: ",tc++);
		if(!negative_cycle(inf + 5)) {
			puts("No cycle found.");
			continue;
		}

		double lo = 0.0, hi = 1 << 30;
		double ans = 0.0;
		for (int i = 0 ; i < 50 ; ++i) {
			double mid = lo + (hi - lo) / 2.0;
			if(!negative_cycle(mid)) lo = mid,ans = mid;
			else hi = mid;
		}
		printf("%.2f\n",ans);
	}
}
