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
typedef vector<int> vi;
int n,m;
int dp[1 << 9][1 << 9][9];
int ans[18];
/* Meet in the Middle + Dynamic Programming on bits
 * Split each binary number of 16 bits into low and high of 8 bits
 * dp[high][low][k] represents if we choose a high currently, then dp[high][low][k] represents how many numbers
 * in our current set has k differences from high and low as low
 * Each time we update dp
 * then reupdate it in dp
 */
int main() {
	scanf("%d %d",&n,&m);
	int curr;
	for (int i = 0 ; i < n ; ++i) {

		scanf("%d",&curr);

		int low  = ((1 << (8)) - 1)  & curr;
		int high = (~((1 << 8) - 1)) & curr;
                curr >= 8;

		memset(ans,0,sizeof(ans));

		for (int j = 0 ; j < 256; ++j) {
			for (int k = 0 ; k <= m / 2 ; ++k) {
				ans[k + __builtin_popcount(j ^ low)] += dp[high][j][k];
			}
		}
		for (int j = 0 ; j < 256 ; ++j) {
			dp[j][low][__builtin_popcount(j ^ high)]++;
		}

		for (int i = 0; i <= m ; ++i) {
			printf("%d ",ans[i]);
		}
		puts("");
	}
}

