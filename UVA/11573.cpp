
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
const int maxn = 200005;
const int N = 200005;
int lp[N + 1];
int phi[N + 1];
vector<int> pr;

// Number Theory
// let's fix the current divisor to be d
// for multiple j of d, the answer contributed by d is d * number of coprimes between d / i and numbers from 1 to d / i
// otherwise d would not be the gcd
// for line #3 we use phi function to calculate number of coprimes quickly
void calc_sieve()
{
	phi[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			phi[i] = i - 1;
			pr.push_back(i);
		}
		else
		{
			if (lp[i] == lp[i / lp[i]])
				phi[i] = phi[i / lp[i]] * lp[i];
			else
				phi[i] = phi[i / lp[i]] * (lp[i] - 1);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

ll dp[maxn];
int main() {

	calc_sieve();

	for (int i = 2 ; i < N ; ++i) {
		for (int j = i * 2 ; j < N ; j += i) {
			int cur = j / i;
			dp[j] += i*1LL*phi[cur];
		}
		dp[i] += phi[i];
		dp[i] += dp[i - 1];

	}
	int n;
	while(scanf("%d",&n) && n != 0) {

		printf("%lld\n",dp[n]);
	}

}


