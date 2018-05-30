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
//#define mp make_pair
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
double p[130][130];
typedef pair<pii,pii> en;
map<en,double> mp;
// Dynamic programming
// state is (range,needed,i) where i is current level
// Probability that i wins a range [L,R] is the probability that it wins the [L + 2^i,R], and beats winner of [L,L + 2^i - 1]
// or the inverse depending on where i lies.
// try all possibilities for right leader, and subproblems appear so use dp.
double solve(int l,int r,int i,int d) {


	if (l + 1 == r && d == 0) {
		return i == l ? p[l][r] : p[r][l];
	}
	if (l == r) {
		return i == l ? 1 : 0;
	}
	pair<pii,pii> tt = make_pair(pii(l,r),pii(i,d));
	if (mp.find(tt) != mp.end()) {
		return mp[tt];
	}
	double ret = 0.0;
	// iterate on range
	for (int j = l ; j <= r ; ++j) {

		if (i >= l && i <= l + (1 << d) - 1 && j >= l + (1 << d) && j <= r) {
			ret += p[i][j] * solve(l + (1 << d),r,j, d - 1) * solve(l, l + (1 << d) - 1,i,d - 1);
		}
		if (j >= l && j <= l + (1 << d) - 1&& i >= l + (1 << d) && i <= r) {
			ret += p[i][j] * solve(l + (1 << d),r,i, d - 1) * solve(l, l + (1 << d) - 1,j,d - 1);
		}
	}
	return mp[tt] = ret;
}
int n;
int main() {
	;
	ios
	while (true) {
		cin >> n;
		if (n == -1) {
			break;
		}

		int m = (1 << n);

		for (int i = 0 ; i < m ; ++i) {
			for (int j = 0 ; j < m ; ++j) {
				cin >> p[i][j];
			}
		}
		mp.clear();
		double prob = -(1 << 30);
		int ans = 0;
		for (int i = 0 ; i < m ; ++i) {

			if (prob < solve(0,m - 1,i,n - 1)) {

				prob = solve(0,m - 1,i,n - 1);
				ans = i;
			}
		}
		cout << (ans + 1) << "\n";
	}

}

