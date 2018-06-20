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

// DP -- Permutations DP
int n,m,k;
ll c[2000][2000];
// placed bad
ll dp[751][2000];
ll fac[2000],fac_inv[2000];
long long modPow(long long a,long long b)
{
    long long res = 1;
    while (b) {
        if (b & 1) res = 1LL*(res%mod) * (a%mod),res %= mod;
        a = (a%mod * a%mod);
        a %= mod;
        b >>= 1;
    }
    return res;
}
ll modInv(ll x) {
	return modPow(x,mod - 1);
}
void comb() {
	c[0][0] = 1;
	for (int i = 1 ; i < 2000 ; ++i) {
		c[i][0] = 1;
		for (int j = 1 ; j < 2000 ; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			c[i][j] %= mod;
		}
	}
	fac[0] = 1;
	for (int i = 1 ; i < 2000 ; ++i) {
		fac[i] = 1LL*i * fac[i - 1];
		fac[i] %= mod;

		fac_inv[i] = modInv(fac[i]) % mod;
	}

}
ll distObjects(int n,int k) {
	if (k <= 0) return 0;
	return c[n + k - 1][k - 1];
}
ll nck(int n,int k) {
	return c[n][k];
}
int sum[751];
int f[751];
map<int,int> cord;
int sz = 1;
int p[751];
bool sq(ll x) {
	if (x == 1) return 1;
	ll lo = 2, hi = sqrt(x) + 5;
	while (lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		if (1LL * mid * mid == x) return 1;
		if (1LL*mid *mid > x) hi = mid -1 ;
		else lo = mid + 1;
	}
	return 0;
}
int g[751];
int lead[751];
vector<int> grp[751];
unordered_map<int,int> mp;
int main() {
	//cout << mod << "\n";
	int n;
	scanf("%d",&n);
	vector<int> nums;
	for (int i = 0 ; i < n ; ++i) {
		int x; scanf("%d",&x);
		nums.pb(x);
		mp[x]++;

	}
	sort( nums.begin(), nums.end() );
	nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
	REP(i,nums) {
		g[i] = mp[nums[i]];
		grp[i].pb(nums[i]);
		lead[i] = i;
	}

	for (int i = 0 ; i < sz(nums); ++i) {
		for (int j = i + 1 ; j < sz(nums) ; ++j) {
			if (lead[j] == -1)
				continue;

			if (sq(1LL*nums[i] * nums[j])) {
				g[j] += g[i];
				lead[i] = -1;
				REP(k,grp[i]) grp[j].pb(grp[i][k]);
				break;

			}
		}
	}
	for (int i = 0 ; i < sz(nums) ; ++i) {
		if (lead[i] != -1) {
			f[sz++] = g[i];
		}
	}

	for (int i = 1 ;i < sz ; ++i) {
		sum[i] = f[i] + sum[i - 1];
		//cout << f[i] << " ";
	}


	comb();
	dp[0][0] = 1;
	for (int pos = 1 ; pos < sz ; ++pos) {
		int before = sum[pos - 1];
		int gaps = before + 1;
		int toks = f[pos];
		for (int bad = 0 ; bad <= before ; ++bad) {
			int good = gaps - bad;
			for (int i = 0; i <= toks ; ++i) {
				if (i > good) break;
				for (int j = 0 ; j <= toks - i ; ++j) {
					if (j > bad)
						break;
					int rem = toks - (i + j);

					dp[pos][bad - j + rem] += ( 1LL*( (dp[pos - 1][bad]%mod * nck(bad,j) %mod ) * 1LL*(nck(good,i)%mod * distObjects(rem,i + j)%mod)%mod))%mod;
					dp[pos][bad - j + rem] %= mod;

				}
			}
		}

	}

	ll cur = dp[sz - 1][0];

	for (int i = 0 ; i < sz(nums) ; ++i) {
		if (lead[i] != -1) {
			ll tot = fac[g[i]];
		//	cerr << g[i] << "\n";
			REP(j,grp[i]) {
				//	cerr << grp[i][j] << " " ;
				//cerr << mp[grp[i][j]] << " ";

				tot *= 1LL*fac_inv[mp[grp[i][j]]];
				tot %= mod;
			}
			cur *= tot;
			cur %= mod;
			//cerr << "\n";
		}
	}
	cout << cur << "\n";


}
