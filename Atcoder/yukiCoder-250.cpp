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
const int maxn = 400005;
const ll mod = 1000*1000*1000 + 7;
int n,k;
int ans = 0;
int ptr = 0;
ll dp[1505][1505];
ll loop(int ind,int k) {
	if (ind > n) return 0;
	if (k == 0) {
		return 1;
	}
	ll &ret = dp[ind][k];
	if (ret!=-1) return ret;
	ret = 0;
	ret += loop(ind + 1,k);
	ret %= mod;
	ret += loop(ind,k - 1);
	ret %= mod;
	return ret;
}
int solve() {
	for (int i = 1 ; i <= n ; ++i) dp[i][0] = 1;
	for (int loop = 1 ; loop <= k ; ++loop) {
		for (int i = 1; i <= n ; ++i) {
			dp[i][loop] += 1ll*dp[i][loop - 1];
			//dp[i][loop]  %= mod;
			dp[i][loop] += 1ll*dp[i - 1][loop];
			dp[i][loop] = min(dp[i][loop],1LL<<57);
			//dp[i][loop] %= mod;
		}
	}
	cout << dp[n][k] << "\n";
}
int main() {
	n = 1501,k=1501;
	int q; cin >> q;
	int n,k,t;
	while(q--) {
		scanf("%d %d %d",&n,&k,&t);
		if (dp[n][k] <= t) {
			printf("AC\n");
		} else {
			printf("ZETUBOU\n");
		}
	}

}
