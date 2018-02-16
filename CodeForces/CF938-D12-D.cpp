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
const int maxn = 3*100005;
int n,m;
ll DIS[maxn];
vector<pii> g[maxn];
ll ch[maxn];
int main() {
	scanf("%d %d",&n,&m);
	int u,v;
	ll c;
	for (int i = 0 ; i < m ; ++i) {
		scanf("%d %d %lld",&u,&v,&c);
		--u; --v;
		g[u].pb(pii(v,c*2LL));
		g[v].pb(pii(u,c*2LL));
	}
	for (int i = 0 ; i < n ; ++i) {
		scanf("%lld",&ch[i]);
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > PQ;

	for(int i = 0 ; i < n; i++)
	{
		DIS[i] = ch[i];
		PQ.push(pii(DIS[i],i));
	}

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
			ll cost = (ll)(1LL*next.second + DIS[index]);
			if(cost >= DIS[next.first]) continue;
			DIS[next.first] = cost;
			PQ.push(make_pair(cost,next.first));

		}
	}
	for (int i = 0 ; i < n ; ++i) {
		printf("%lld ",DIS[i]);
	}


}
