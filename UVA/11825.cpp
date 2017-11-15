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
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
int n;
int c = 0;
// DP on bitmasks
// subsets of mask trick drops complexity from 2^n * 2 ^ n to 3^n
int f[20];

int memo[1 << 18];
void count(int s) {


	int all = 0;
	for(int i = 0 ; i < n ; ++i) {
		if(s & (1 << i)) {
			all |= f[i];
		}
	}
	if(all == (1 << n) - 1)
		memo[s] = 1;
	else memo[s] = 0;
}
int dp[1 << 16];
int main() {
	int tc = 1;
	while(scanf("%d",&n) != EOF){
		if(n == 0)
			break;
		memset(dp,0,sizeof(dp));

		int m;
		for(int i = 0 ; i < n ; ++i) {
			scanf("%d",&m);
			f[i] = 1 << i;
			for(int j = 0 ; j < m ; ++j){
				int nxt;
				scanf("%d",&nxt);
				f[i] |= (1 << nxt);
			}
		}
		for(int i = 0 ; i < (1 << n) ; ++i) {
			count(i);
		}
		for(int msk = (1 << n) - 1 ; msk >= 0 ; --msk) {
			for (int s = msk; s; s= (s-1) & msk) {

					dp[msk & ~s]= max(dp[msk & ~s], memo[s] + dp[msk]);

				}
		}

		printf("Case %d: %d\n",tc++,dp[0]);
	}
}
