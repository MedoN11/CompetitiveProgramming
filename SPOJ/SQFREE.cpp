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
const int maxn = 1000*1000*10 + 5;
using namespace std;
int t;
int coef[maxn];
bool prime[maxn];
// Inclusion Exclusion with Mobius
int main()  {
	scanf("%d",&t);
	for(int i = 0 ; i < maxn ; ++i) {
		prime[i] = 1;
		coef[i] = -1;
	}
	for(int i = 2 ; i < maxn ; ++i) {
		if(prime[i]) {
			coef[i] = 1;
			for(int j = i * 2 ; j < maxn ; j += i) {
				prime[j] = false;
				if(j % (1LL * i * i) == 0)
					coef[j] = 0;
				else {
					coef[j] *= -1;
				}
			}
		}
	}

	while(t--) {
		ll ans = 0;
		ll n;
		scanf("%lld",&n);
		for(int i = 1 ; 1LL*i * i <= n ; ++i) {
			///cerr << i << " " << coef[i] << "\n";
			ans += coef[i] * (n /(1LL*i*i));
		}
		printf("%lld\n",-ans);

	}
}
