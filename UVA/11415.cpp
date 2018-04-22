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
typedef pair<int,int> pii;
typedef pair< long double,long double> pdd;
#define F first
#define S second
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define mp make_pair
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define for1LL(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define fornLL(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define ld long double
int t,n;
const int maxn = 1000*1000*10 + 1;
int sp[maxn];
bool prime[maxn];
vector<ll> v;

// just do as statement says
// factorize all numbers as you go, and precompute everything offline.
int main() {

	forn(i,maxn) prime[i] = 0,sp[i] = -1;
	memset(prime,1,sizeof(prime));
	for (int i = 2 ; 1LL*i * i <= maxn ; ++i) {
		if(prime[i]) {
			sp[i] = i;
			for (int j = i << 1 ; j < maxn ; j += i) {
				if(sp[j] == - 1) {
					sp[j] = i;
				}
				prime[j] = 0;

			}
		}
	}

	v.pb(0);
	v.pb(0);
	ll res = 0;

	for (int i = 2 ; i < maxn ; ++i) {
		int x = i;
		while(x > 1) {
			int cur = sp[x];
			while(x > 1 && x % cur == 0) ++res,x /= cur;
		}
		v.pb(res);
	}
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		printf("%d\n" ,(int)(upper_bound(all(v),n) - v.begin()));
	}
}

