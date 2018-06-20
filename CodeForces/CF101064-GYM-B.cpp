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
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
typedef pair<ll,ll> pii;
const ll mod = 1000*1000*1000 + 7;
int n;
const int N = 61;
int dp[N][N][N][N][3];

// DP
// Answer is n! - sequences with LIS 3 or 4.
// Use DP to count these. Editorial is good.

int solve(int l1,int l2,int l3,int l4,int f) {
	if (l1 + l2 + l3 + l4 == 0) {

		return f ? 1 : 0;
	}
	int &ret = dp[l1][l2][l3][l4][f];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = 1 ; i <= l1 ; ++i) {
		ret += solve(i - 1,l2 + l1 - i,l3,l4,f);
		ret %= mod;
	}
	for (int i = 1 ; i <= l2 ; ++i) {
		ret += solve(l1,i - 1,l3 + l2 - i,l4,f);
		ret %= mod;
	}
	for (int i = 1 ; i <= l3 ; ++i) {

		ret += solve(l1,l2,i - 1,l4 + l3 - i,1);
		ret %= mod;

	}
	if (l4 >= 1) {
		ret += solve(l1,l2,l3,l4 - 1,1);
		ret %= mod;
	}
	return ret;

}
int main() {

	cin >> n;
	memset(dp,-1,sizeof(dp));
	ll ans = 1;
	for (ll i = 1 ; i <= n ; ++i) {
		ans *= i;
		ans %= mod;
	}
	ll res = ans - solve(n,0,0,0,0);
	while (res < 0) res += mod;
	res %= mod;
	cout << res << "\n";
}
