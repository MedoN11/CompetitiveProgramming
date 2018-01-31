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
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 1000*1000;
int n;
ll s = 0;
const int maxs = 63000;
const int mod = 1e9 + 7;
int dp[501][maxs];
int solve(int ind,int sum) {
	if(sum >= maxs) return 0;
	if(ind == n + 1) return (s - sum) == sum;
	int &ret = dp[ind][sum];
	if(ret != -1)
		return ret;
	ret = 0;
	ret = solve(ind + 1,sum);
	ret %= mod;
	ret += solve(ind + 1,sum + ind);
	ret %= mod;
	return ret;
}
int main() {
	cin >> n;
	s = 1LL*(n)*(n+1)/2;
	if(s & 1) {
		printf("0\n");
	}
	else {
		memset(dp,-1,sizeof(dp));
		ll ans = 1LL*solve(1,0);
		ans *= 1LL*500000004;
		ans %= mod;
		cout << ans << "\n";
	}
}
