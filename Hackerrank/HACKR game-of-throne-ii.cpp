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
int a,b,n;
int f[26];
const int maxn = 1e5 + 5;
string s;
ll dp[maxn][26];
ll fact[maxn + 5];
ll mod = 1000000007;
// Counting
// Solve for first half since second must be identical
int put(int x,int y) {
	int p = 1;
	for (int i= 1 ; i <= y; i<<=1 ) {

		if(y & i) p = (1LL*p*x) %mod;
		x = (1LL*x*x) %mod;
	}
	return p;
}

ll nCk(int n,int m)
{
	if(n < 0 || m < 0) return 0;
	return (1LL * fact[n] * put( (1LL * fact[m] * fact[n-m] ) % mod, mod - 2 ))%mod;
}
int pre[26];
int main() {
	fact[0] = 1;
	for(int i=1;i < maxn ;i++) fact[i] =( 1LL * fact[i-1] *i )%mod;
	ios
	cin >> s;
	REP(i,s) f[s[i]-'a']++;

	int sum = 0;
	for(int i = 0 ; i < 26 ; ++i) {
		f[i] /= 2;
		sum += f[i];
		pre[i] = sum;
	}


	ll ans = 1;
	int ex = 0;
	for(int i = 0 ; i < 26 ; ++i) {
		int poss = sum - ex;
		//cerr << poss << " " << f[i] << "\n";
		if(f[i] > poss || f[i] == 0)
			continue;
		ans *= 1LL*nCk(poss,f[i]);
		ans %= mod;
		ex = pre[i];
	}
	cout << ans << "\n";



}
