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
typedef pair<ll,ll> pii;
typedef pair<pii,int> tri;
const int maxn = 4100;
const int mod = 1000*1000*1000 + 7;
using namespace std;
ll n,m,k,s;
int dp[maxn][maxn];
int solve(int ind,int s) {
	if (s < 0) {
		return 0;
	}
	if (ind < 0) {
		return 0;
	}
	if (ind == 0) {
		return s == 0 ? 1 : 0;
	}
	int &ret = dp[ind][s];
	if (ret != -1) {
		return ret;
	}
	ret = solve(ind - 1,s);
	ret += solve(ind,s - ind);
	ret %= mod;
	return ret;
}
// at least x times
int f(int x,int sr) {
	if (sr - x < 0) return 0;
	if (x < 0) return 0;
	return solve(x,sr - x);
}
// sequences such that x occurs exactly y times
int g(int x,int y) {
	return (f(k-y,s - x * y) - f(k-(y+1),s - x * (y + 1)) + mod)%mod;
}
ll p[maxn];
ll go(ll i,ll m) {
	ll a = 1;
	while(m--) a *= i, a %= mod;
	return a;
}
int main() {
	memset(dp,-1,sizeof(dp));
	cin >> n >> k >> m;
	s = n;
	p[0] = 1;
	for (ll i = 1 ; i <= n ; ++i) {
		p[i] = go(i,m);
	}

	ll ans = 0;
	for (int i = 1 ; i <= n ; ++i) {
		for (int j = 1 ; j <= n ; ++j){
			//cerr << i << " " << j << " " << g(i,j) << "\n";
			ans += ((1ll*j*1ll*p[i])%mod*(g(i,j))%mod)%mod;
			ans %=mod;
		}
	}
	cout << ans << "\n";
}
