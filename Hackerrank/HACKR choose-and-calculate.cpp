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
int n,k;
const int maxn = 1e5 + 5;
ll fact[maxn + 5];
ll mod = 1000000007;

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
	if(m > n) return 0;
	if(n < 0 || m < 0) return 0;
	return (1LL * fact[n] * put( (1LL * fact[m] * fact[n-m] ) % mod, mod - 2 ))%mod;
}

int main() {
	fact[0] = 1;
	for(int i=1;i < maxn ;i++) fact[i] =( 1LL * fact[i-1] *i )%mod;
	scanf("%d %d",&n,&k);
	vector<int> v(n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&v[i]);
	sort(all(v));
	ll low = 0, high = 0;
	for(int i = 0 ; i < n ; ++i) {
		cerr << nCk(n - i - 1,k - 1) << "\n";
		low += (1LL*v[i]%mod * nCk(n - i - 1,k - 1)%mod)%mod;
		low %= mod;
	}
//	reverse(all(v));
	for(int i = 0 ; i < n ; ++i) {
		high += (1LL*v[i]%mod * nCk(i,k - 1)%mod)%mod;
		high %= mod;
	}

	cout << (high - low + mod) % mod << "\n";

}
