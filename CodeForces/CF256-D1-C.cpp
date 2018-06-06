
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
#include <unordered_map>
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
#define F second.first
#define S second.second
#define MP make_pair
// Patterns - Games
unordered_map<ll,int> dp(10000000/7);
ll solve(ll y) {

	assert(y > 0);
	if(dp.find(y)!=dp.end()) {
		return dp[y];
	}

	ll x = floor(sqrt(y));
	ll z = ceil(sqrt(sqrt(y)));
	if (x == y) --x;
	if (y == z) ++z;
	int arr[5];
	memset(arr,0,sizeof(arr));

	int d = 0;
	for (ll a = z ; a <= x ; a ++) {

		if (a > 0) {
			int t = solve(a);
			if (!arr[t]) ++d,arr[t]=1;
		}
		if(d >= 3 || 1LL*a - z >= 6)
			break;
	}
	for (ll a = x ; a >= z ; a --) {

		if (a > 0) {
			int t = solve(a);
			if (!arr[t]) ++d,arr[t]=1;
		}
		if (d >= 3 || x - a >= 6)
			break;
	}

	int q = 0;
	while(arr[q]) {
		cerr << q << "\n";
		q++;
	}
	return dp[y] = q;
}

int main() {

	//	for (int i = 1 ; i <= 20; ++i) {
	//		cout << solve(i) << "\n";
	//	}
	int n; cin >> n;
	int p = 0;
	for (int i = 0 ; i < n ; ++i) {
		ll x;
		scanf("%lld",&x);
		p ^= solve(x);
		//	cerr << solve(x) << "\n";
	}
	if(!p) puts("Rublo");
	else puts("Furlo");
}
