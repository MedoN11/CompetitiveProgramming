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
typedef pair<double,double> pdd;
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
struct BunnyConverter {
	int getMinimum(int n,int z,int start,int g);
};
// BFS on the whole graph..complexity is O(N)
int d[500005];
vector<int> go[500005];
int BunnyConverter::getMinimum(int n_,int z_,int s_,int g_) {
	ll n = n_, z = z_, s = s_, g = g_;
	ll a = 1LL*(z * z);
	a %= n;
	a *= z;
	a %= n;
	queue<ll> q;
	q.push(s);
	fill(d,d + 500005, 1 << 30);
	d[s] = 0;
	for1LL(i,n) {
		go[1LL*(i*i)%n].pb(i);
	}

	while (!q.empty()) {
		ll cur = q.front(); q.pop();
		if(cur == g)
			return d[cur];

		ll here = -(cur + a);
		here %= n;
		while(here < 0) here += n;
		here %= n;
		REP(j,go[here]) {
			ll y = go[here][j];
			if (d[cur] + 1 < d[y]) {
				q.push(y);
				d[y] = d[cur] + 1;
			}
		}

	}

	return -1;
}

int main() {
	struct BunnyConverter d;
	ll n,z,s,g;
	cin >> n >> z >> s >> g;
	cout << d.getMinimum(n,z,s,g);
}
