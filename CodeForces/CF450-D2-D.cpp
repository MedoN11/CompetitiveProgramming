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
using namespace std;
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;;
// Combinatronics
// Stars and Bars theorm
//First if x does not divide y, then the answer is zero, since the gcd has to divide every number, it must divide the sum.
//Now to the case where x divides y, we need to calculate all sequences that sum to y / x with gcd 1, why? Because any valid sequence can be transformed to such form if you take the gcd as a common factor. Let's say a1 + a2 + a3 ...an = y, and the gcd of a1,a2,a3.. an is g, then we can write it as g*b1 + g*b2 + g*b3...g*bn = y, which is the same as g*(b1+b2 + b3 +..bn) = y, now divide by g, and you get b1 +b2 +b3 + b4...bn = y/g.
//Now to count the sequences of sum X and gcd 1, you start by saying that all sequences are valid, so you add all sequences that sum to X ( To get that number, check the comment by i_love_ayrawhsia_nodnat, he explains it perfectly, or google stars and bars theorm).
//After you do so, you need to subtract bad sequences with gcd > 1 and sum equal to y / x, the gcd must divide the sum again (y/x) , so you re-enumerate the process by finding numbers that sum to (y/x)/g, where g divides y /x. You keep doing so recursively.
ll mod = 1000*1000*1000 + 7;
map<ll,ll> dp;
ll pow2(ll n) {
	if(n == 0) return 1;
	if(n == 1) return 2;
	ll h = pow2(n >> 1);
	h *= h; h %= mod;
	if(n & 1) h *= 2;
	h %= mod;
	return h;
}
int solve(int n) {
	if(n == 1)
		return 1;
	if(dp.find(n) != dp.end())
		return dp[n];
	ll tot = pow2(n - 1) - 1;
	tot %= mod;
	tot += mod;
	tot %= mod;
	for(ll i = 2 ; i * i <= n ; ++i) {
		if(n % i == 0) {
			tot -= solve(i);
			tot += mod;
			tot %= mod;
			if(n / i != i) tot -= solve(n / i);
			tot += mod;
			tot %= mod;
		}
	}
	return dp[n] = tot;
}
//ll C[5000][5000];
//void pascals() {
//	C[0][0] = 1;
//	for(int i = 1 ; i < 2000 ; ++i) {
//		C[i][0] = 1;
//		for(int j = 1 ; j < 2000 ; ++j) {
//			C[i][j] += C[i][j - 1] + C[i - 1][j - 1];
//		}
//	}
//
//}
//int sum(int n) {
//	int ans = 0;
//	for(int k = 1 ; k <= n ; ++k) {
//		ans += C[n + k - 1][k - 1];
//	}
//	return ans;
//}
int main() {
//	pascals();
//	cout << sum(3) << "\n";
	int n,k;
	scanf("%d %d",&n,&k);
	if(k % n) puts("0");
	else {
		printf("%d\n",solve(k / n));
	}
}
