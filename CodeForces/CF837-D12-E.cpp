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
const int maxn = 100005;
int mod = 0;

// the gcd change is monotonic
// and each of them must divide the next
// so we just do binary search
// number of unique gcd's is small, so complexity is fast
ll gcd(ll a,ll b) {
	if(a == 0)
		return b;
	return gcd(b % a,a);
}
vector<ll> divs;
bool ok(ll x,ll b,ll curr) {
	if(x < 0)
		return 0;
	REP(i,divs) {
		if(b/divs[i] - (x - 1) / divs[i] >= 1 && divs[i] > curr &&  divs[i] % curr == 0)
			return 0;
	}
	return 1;
}
ll f(ll a,ll b) {
	if(b == 0) return 0;
	ll lo = 1;
	ll hi = b;
	ll k = 1;
	ll curr = gcd(a,b);
	while(lo <= hi) {
		ll mid = lo + (hi - lo )/2LL;
		if(b / mid <  curr)
		{
			hi = mid - 1;
			continue;
		}
		ll x = b - mid*curr;

		if(!ok(x,b,curr))
			hi = mid - 1;
		else {
			k = mid;
			lo = mid + 1;
		}
	}
		cerr << k << " " << curr << "\n";
	return k + f(a,b - k*gcd(a,b));
}
ll f2(ll a,ll b) {
	if(b == 0) return 0;
	//	cerr <<"org "<< gcd(a,b) << "\n";
	return 1+f2(a,b-gcd(a,b));
}
ll n,m;
int main() {
	cin >> n >> m;
	set<ll> s;
	for (ll i = 1 ; i * i <= n ; ++i) {
		if(n  % i == 0) {
			divs.pb(i);
			if(i != n / i)
			divs.pb(n / i);
		}
	}

	cout << f(n,m) << "\n";

	//cout << "\n" << f2(n,m)<<"\n";
}
