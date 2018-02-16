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
const int maxn = 1000005;
const ll MOD1 = 2000000011;
int n,m;
unordered_map<ll,ll> mp;
vector<int> adj[maxn];
const int p = 10000000003;
const int p2 = 10003;
ll hash(vector<int> &v) {
	sort(all(v));
	ll h1 = 0;
	ll h2 = 0;
	REP(j,v) {
		h2 *= p;
		h2 += v[j];

	}

	return h2;
}
int main() {
	scanf("%d %d",&n,&m);
	for (int i = 0 ; i < m ; ++i) {
		int u,v;
		scanf("%d %d",&u,&v);

		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1 ; i <= n ; ++i ) {
		ll r = hash(adj[i]);
		mp[r]++;


	}
	ll ans = 0;
	for (int i = 1 ; i <= n ; ++i ) {
		ll r = hash(adj[i]);
		ans += (mp[r] - 1);

	}
	mp.clear();
	vector<int> v;
	for (int i = 1 ; i <= n ; ++i ) {
		v.clear();
		v.pb(i);
		REP(j,adj[i]) v.pb(adj[i][j]);
		ll r = hash(v);

		mp[r]++;


	}
	for (int i = 1 ; i <= n ; ++i ) {
		v.clear();
		v.pb(i);
		REP(j,adj[i]) v.pb(adj[i][j]);

		ll r = hash(v);
		ans += (mp[r] - 1);


	}
	ans/=2;
	cout << ans << "\n";



}
