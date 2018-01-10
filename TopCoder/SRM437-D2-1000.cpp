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
#define fst first.first
#define snd first.second
#define trd second.first


// Map + DP
// Reverse all operations now you want to go from N to 1 by taking log, adding or subtracting
// each step we decide when we last did a power, what was the exponent
// so we bruteforce all possibilites(they are like 62 at most log2(n) because N is at most 10^18).
// once we do that we get our exponent p which is possibly a double..we round it down
// we try p and p + 1 and subtract absolute differences.
map<ll,int> dp;
ll n;

ll powr(ll x,ll p) {
	if(p == 0)
		return 1;
	if(p == 1)
		return x;
	ll r = pow(x,p/2);
	r *=1LL*r;
	if(p % 2) r *= 1LL*x;
	return r;
}
long double logBase(ll x,ll b) {
	return double(log(x) / log(b));
}
ll f(ll x) {

	if(x < 0)
		return 0;
	if(x == 0)
		return 1;
	if(x == 1)
		return 1;
	if(x == 2) return 1;

	if(x <= 4) return 2;

	if(dp.find(x) != dp.end())
		return dp[x];
	//cerr << x << "\n";
	ll val = 100;
	ll ret = x;
	for(ll i = val ; i >= 2 ;--i ) {
		long double p = pow(x,1.0/i);
		ll y = floor(p);
		ret = min(ret,1 + f(y) + (ll)(abs(x-powr(y,i))));
		ret = min(ret,1 + f(y + 1) + (ll)(abs(x-powr(y + 1,i))));



	}
	return dp[x] = ret;
}
int main() {
	cin >> n;
	cout << f(n) << "\n";
}
