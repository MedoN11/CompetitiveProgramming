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
typedef pair<long double,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
typedef long double ld;
ll n;
int const maxn = 200001;

ll phi[maxn];
bool prime[maxn];
void sieve() {
	for(int i = 1 ; i <= maxn ; ++i) {
		phi[i] = 1;
	}
	memset(prime,1,sizeof(prime));
	for(ll i = 2 ; i <= maxn ; ++i) {
		if(prime[i]) {
			phi[i] = i - 1;
			for(int j = i << 1;  j < maxn ; j += i) {
				prime[j] = 0;
				int k = j;
				ll res = 1;
				while(k % i == 0) {
					res *= i;
					k /= i;
				}
				phi[j] *= 1LL*(res) - (res / i);
			}
		}
	}
	for(int i = 2 ; i < maxn ; ++i) {
		if(prime[i])
			phi[i] = i - 1;
	}
}

ll gcd(ll a,ll b) {
	if(a == 0)
		return b;
	return gcd(b % a,a);
}
ll acc[maxn];
int main()
{
	sieve();
	for(int i = 1 ; i < maxn ; ++i) {
		acc[i] += 1LL*acc[i - 1];
		acc[i] += 1LL*phi[i];
	}
	while(scanf("%lld",&n)) {
		if(n == 0)
			break;
		--n;
		if(n == 0) {
			cout << "0/1" << "\n";
			continue;
		}
		int lo = 0, hi = maxn - 1;
		int ans = 0;
		while(lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if(acc[mid] < n) {
				lo = mid + 1;
				ans = mid;
			}
			else {
				hi = mid - 1;
			}
		}

		//cerr << acc[ans] << " " << ans << " " << "\n";
		int den = ans + 1, num = 0;
		n -= acc[ans];
		for(int j = 1 ; j <= den ; ++j) {
			if(gcd(j,den) == 1) {
				--n;
				if(n == 0) {
					num = j;
					break;
				}
			}
		}
		//cerr << n << "\n";
		cout << num << "/" << den << "\n";


	}

}
