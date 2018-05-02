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
#include <unordered_map>
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
int n;

//segment tree + primes + inclusion exclusion + binary search
// If for every element in the array we calculate prev[i] where prev[i] is the nearest coprime to it's left, then we can solve
// each query in logn by building a segment tree over prev, and doing easy rmq
// The idea is in calculating prev
// first we notice that since each number is at most around 10^6, number of distinct prime factors is like at most 8-9
//  For every number, let's binary search on maximum j such that coprimes from j to i - 1 with arr[i] are 1. Clearly if we maximize this function, we get prev[i].
// now to calcute the number of coprimes in a range, we do inclusion exclusion of prime factorization of arr[i].
// for each subset of prime number we add/subtract their count in range [j,i] depending on parity

const int maxSize = 5*100005;
int par[maxSize];
int dp[maxSize];
vector<int> pre[maxSize];

int lo[maxSize],hi[maxSize],ans[maxSize];
void build(int ind,int l,int r) {
	lo[ind] = l;
	hi[ind] = r;
	if (lo[ind] == hi[ind]) {
		ans[ind] = dp[l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind*2,l,mid);
	build(ind*2+1,mid + 1,r);
	ans[ind] = max(ans[ind*2], ans[ind*2+1]);
}
int query(int ind,int l,int r) {
	if (l > hi[ind] || r < lo[ind])
		return -(1 <<30);
	if (l <= lo[ind] && hi[ind] <= r)
		return ans[ind];
	return max(query(ind*2,l,r), query(ind*2+1,l,r));
}
int main() {
	int q;
	scanf("%d",&n);
	scanf("%d",&q);

	for (int i = 0 ; i < n; ++i) {
		int x;
		scanf("%d",&x);
		dp[i] = -(1 << 30);

		vector<int> localPrimes;
		for (ll j = 2 ; 1LL*j*j <= x ; ++j) {
			if (x % j == 0) {
				localPrimes.pb(j);
				while (x % j == 0) x /= j;
			}
		}
		if(x != 1) {
			localPrimes.pb(x);
		}
		int m = localPrimes.size();
		assert(m < 15);
		int lo = 0, hi = i - 1;
		int res = -(1 << 30);
		vector<int> subs;
		for (int msk = 1 ; msk < (1 << m) ; ++msk) {
			int num = 1;
			int b = 0;
			for (int j = 0 ; j < m ; ++j) {
				if ( (msk & (1 << j)) > 0) {
					++b;
					num *= localPrimes[j];

				}
			}
			par[num] = b % 2;
			subs.pb(num);
		}
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			int 	coprimes =  i - mid ;
			REP(k,subs) {
				int p = subs[k];
				if(pre[p].size() == 0)
									continue;
				vector<int>::iterator it = lower_bound(all(pre[p]),mid);
				if (it == pre[p].end())
					continue;
				int l = (int)(it - pre[p].begin());


				it = (upper_bound(all(pre[p]),i));
				--it;

				int r = it - pre[p].begin();
				int cnt = r - l + 1;

				//System.err.println(i+" "+mid+" "+p+" "+cnt+" "+par[p]+" "+l+" "+r);
				//System.err.println(pre[p]);
				if (par[p] == 1) {
					coprimes -= cnt;
				} else {
					coprimes += cnt;
				}
			}
			//if (i == 5) System.err.println("mid "+mid+" "+coprimes);

			//System.out.println(mid +" "+i +" "+coprimes);
			if (coprimes >= 1) {
				lo = mid + 1;
				res = mid;
			} else {
				hi = mid - 1;
			}
		}
		dp[i] = res;

		for (int msk = 1 ; msk < (1 << m) ; ++msk) {
			int num = 1;
			for (int j = 0 ; j < m ; ++j) {
				if ( (msk & (1 << j)) > 0) {
					num *= localPrimes[j];


				}
			}
			pre[num].pb(i);
		}


	}

	build(1,0,n - 1);
	int l,r;
	while (q-- > 0) {
		scanf("%d %d",&l,&r);
		--l,--r;
		bool found = false;
		int piv = query(1,l,r);
		//System.out.println(piv);
		//	System.err.print(dp[i]+", ");
		found |= piv >= l;

		if (found) {
			puts("S");
		} else {
			puts("N");
		}
	}

}
