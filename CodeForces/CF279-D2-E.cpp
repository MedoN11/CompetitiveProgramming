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
#define F second.first
#define S second.second
#define MP make_pair
// Greedy + DP
//Optimal greedy way to apply operations, then simulate min cost  by dp.
const int maxn = 1000005;
int dp[maxn][2];
char s[maxn];
int n;
int solve(int ind,int f) {
	if (ind == n) {
		return 0;
	}
	int &ret = dp[ind][f];
	if (ret != -1) {
		return ret;
	}
	ret = 1 << 30;
	if (!f) {
		ret = min(ret,2 + solve(ind,1));
	}
	if(!f) {
		int p = s[ind] == '1' ? 1 : 0;

		ret = min(ret,p + solve(ind + 1,0));
	}
	if (f) {
		int p = s[ind] == '1' ? 0 : 1;

		ret = min(ret,p + solve(ind + 1,1));
		ret = min(ret,p + solve(ind + 1,0));

	}
	return ret;
}
int main() {
	scanf("%s",s);
	n = strlen(s);
	memset(dp,-1,sizeof(dp));
	cout << solve(0,0);
}
