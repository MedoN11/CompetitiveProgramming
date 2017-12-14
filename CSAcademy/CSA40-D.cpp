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
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
const int mod = 1000*1000*1000 + 7;
const int maxn = 2001;
int n;
int t[maxn];
int dp[maxn][maxn];

// Dynamic Programming over permutations
int main() {
	ios
	cin >> n;
	for (int i = 0 ; i < n - 1 ;++i) {
		cin >> t[i];
	}
	dp[0][0] = 1;
	for(int i = 1 ; i < n ; ++i) {
		vector<int> sum(n,0);
		sum[0] = dp[i][0];

		for(int j = 0 ; j < n ; ++j) {
			sum[j] = dp[i - 1][j] + sum[j - 1],sum[j] %= mod;
		}
		for(int j = 0 ; j <= i ; ++j) {
			// let's put i in pos j
			if(t[i - 1]) {
				// comes after
				dp[i][j] = (j == 0 ? 0 : sum[j - 1]);
				dp[i][j] %= mod;
			} else {
				// comes before
				int l = 0;
				int r = 0;
				if(j != 0) l = sum[j - 1];
				r = sum[i];
				dp[i][j] = ((r - l)%mod + mod)%mod;
				dp[i][j] %= mod;
			}
		}
	}
	ll res = 0;
	for(int i = 0 ; i < n ; ++i) {
		res += 1LL*dp[n - 1][i];
		res %= mod;
	}
	cout << res << "\n";
}
