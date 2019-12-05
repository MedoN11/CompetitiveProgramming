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
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int, int> pii;
#define ios std::ios_base::sync_with_stdio(false);
const ll mod = 1000000007;
int dp[21][100005];

// DP O(N*M)

// Since the numbers must be distinct if we sort them they must be strictly increasing
// then we can make the problem easier by
// instead counting increasing sequences that make up m.
// so let's start by placing 1,2,3,4,5...etc
// now to increase pos i, we must add n - i to everything after us
// so the dp becomes easier.
int solve(int n, int rem) {
	if (n < 0 || rem < 0)
		return 0;
	if (rem == 0 && n == 0)
		return 1;
	int &ret = dp[n][rem];
	if (ret != -1)
		return ret;
	ret = 0;
	ret += solve(n, rem - n);
	ret %= mod;
	ret += solve(n - 1, rem);
	ret %= mod;
	return ret;
}
int main() {
	int n, m;
	int t;
	cin >> t;
	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%d %d", &n, &m);
		ll ways = 0;

		for (int k = 0; k <= m; ++k) {
			int res = n * (n + 1) / 2;
			if (res > k)
				continue;
			ways += solve(n, k - res);
			ways %= mod;
		}

		printf("%d\n", ways);
	}
}
