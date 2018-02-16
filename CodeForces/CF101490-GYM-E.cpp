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
#define time __time
typedef pair<ll,ll> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 1000*1000 + 5;
string ans = "";
int n,m,p;
vector<pii> g[maxn];
ll block = 0;
ll best = 0;
ll DIS[maxn];
ll oo = 1LL << 55;
ll diji(int idx) {
	for(int i = 0 ; i < n; i++)
	{
		DIS[i] = oo;
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > PQ;
	DIS[idx]= 0;
	PQ.push(make_pair(0,idx));
	while(!PQ.empty())
	{
		pair<ll,ll> out = PQ.top(); PQ.pop();
		int index = out.second;
		ll dis = out.first;
		if(DIS[index] < dis) continue;
		int sz = (int)(g[index].size());
		for(int i = 0 ; i < sz ; i++)
		{
			pair<ll,ll> next = g[index][i];
			if(next.second > block) continue;
			ll cost = (ll)(1LL*next.second + DIS[index]);
			if(cost >= DIS[next.first]) continue;
			DIS[next.first] = cost;
			PQ.push(make_pair(cost,next.first));

		}
	}
	return DIS[n - 1];
}
ll ok(ll x) {
	return 100*x <= 100*best + best * p;
}
bool can(ll x) {
	block = x;
	ll res = diji(0);
	return ok(res);

}
int main() {
	ios
	scanf("%d %d %d",&n,&m,&p);
	for (int i = 0 ; i < m ; ++i) {
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		--u,--v;
		g[u].pb(pii(v,c));
		g[v].pb(pii(u,c));
	}
	block = 1LL << 55;
	best = diji(0);
	cerr << best << "\n";
	ll lo = 1 , hi = 1LL << 32;
	ll ans = -1;
	while (lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		if(can(mid)) {
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	cout << ans << "\n";
}