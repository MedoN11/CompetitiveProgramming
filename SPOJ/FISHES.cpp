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
typedef pair<int,ll> pii;
#define F second.first
#define S second.second
#define MP make_pair
ll dp[105][105];
ll grid[105][105];
ll range[505];
int r,c,h,k,t;
int n,m;
ll solve(int i1,int j1,int i2,int j2) {
	ll s = 0;
	s = dp[i2][j2];
	if (i1 > 0) s -= dp[i1 - 1][j2];
	if (j1 > 0) s -= dp[i2][j1 - 1];
	if (i1 > 0 && j1 > 0) s += dp[i1 - 1][j1 - 1];
	return s;
}
int main() {
	int tt;
	scanf("%d",&tt);
	for (int tc = 1 ; tc <= tt ; ++tc) {
		printf("Case #%d:\n",tc);
		memset(range,0,sizeof(range));
		scanf("%d %d %d %d %d",&r,&c,&h,&k,&t);
		n = r,m = c;
		memset(dp,0,sizeof(dp));
		//map<int,int> mp;
		for (int i = 0 ; i < r ; ++i ) {
			for (int j = 0 ; j < c ; ++j) {
				scanf("%lld",&grid[i][j]);
				//mp[grid[i][j]] = 1;
			}
		}
//		int cnt = 1;
//		for(map<int,int>::iterator it = mp.begin() ; it != mp.end() ;it++) {
//			it->second = cnt++;
//		}
//		for (int i = 0 ; i < r ; ++i ) {
//			for (int j = 0 ; j < c ; ++j) {
//				grid[i][j] = mp[grid[i][j]];
//			}
//		}
		for (int i = 0 ; i < t ; ++i) {
			ll x;scanf("%lld",&x);
			for (int j = 1 ; j <= k ; ++j) {
				ll y; scanf("%lld",&y);
				range[j] += 1LL*x * y;
			}
		}
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < m ; ++j) {
				grid[i][j] = range[grid[i][j]];
			}
		}
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < m ; ++j) {
				dp[i][j] = grid[i][j];
				if (i > 0) dp[i][j] += 1LL*dp[i - 1][j];
				if (j > 0) dp[i][j] += 1LL*dp[i][j - 1];
				if (i > 0 && j > 0) dp[i][j] -= 1LL*dp[i - 1][j - 1];
			}
		}
		ll ans = -(1LL << 59);
		for (int i = 0 ; i  < n ; ++i) {
			for (int j = 0 ; j < m ; ++j) {
				for (int k = i ; k < n ; ++k) {
					for (int d = j ; d < m ; ++d) {
						ans = max(ans,solve(i,j,k,d));
					}
				}
			}
		}
		printf("%lld\n",1LL*ans + 1LL*h);
	}

}
