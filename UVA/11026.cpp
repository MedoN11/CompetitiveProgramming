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
typedef pair< long double,long double> pdd;
#define F first
#define S second
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
//#define mp make_pair
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
#define ld long double
ll dp[1001][1001];
int mod;
int n;
int arr[1001];
// enumerate using dynamic programming
// f(i,k) = i * f(i + 1,k - 1)
ll solve(int ind,int rem) {
	if (ind == n) {
		return 0;
	}
	ll &ret = dp[ind][rem];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	if (rem == 1) {
		ret += arr[ind];
		ret %= mod;
	}
	ret += solve(ind + 1,rem);
	ret %= mod;
	ret += 1LL*(arr[ind] * solve(ind + 1,rem - 1)%mod);
	ret %= mod;
	return ret;
}
int main() {
	ios
	while (cin >> n >> mod) {
		if (n + mod == 0) {
			break;
		}
		for (int i = 0; i < n ; ++i) {
			cin >> arr[i];
		}
		memset(dp,-1,sizeof(dp));
		ll res = 0;
		for (int i = 1 ; i <= n ; ++i) {
			res = max(res,solve(0,i));
		}
		cout << res << "\n";
	}

}

