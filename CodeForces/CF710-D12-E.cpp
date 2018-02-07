
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
const int maxn = 1e7 + 1;
ll dp[3*maxn];
ll n,x,y;
// DP
// The first transistion is tricky
// namely that we only consider (i / 2) when doubling then erasing
// intutive proof of that is as follows
// dp[i/2] denotes the optimal state for i / 2
// if we were to choose another state from (i/2) + 1 till i that would yield a better cost by doubling then erasing
// we will end up with extra erasing costs 2 * (choosen cell - (i/2)), but in that case this means that dp[i/2] was not optimal
// so we proceed with dp updates
// del
int main() {
	cin >> n >> x >> y;

	fill(dp,dp+maxn,1LL<<52);
	dp[0] = 0;
	for (int i = 0 ; i <= n ; ++i) {
		// update forward
		int l = i / 2;
		if(i % 2) ++l;

		dp[i] = min(dp[i],y + dp[l] + (l*2 - i)*x);
		// 1
		dp[i*2] = min(dp[i*2],y + dp[i]);
		// 2
		dp[i + 1] = min(dp[i + 1],dp[i] + x);

	}
	cout << dp[n];

}
