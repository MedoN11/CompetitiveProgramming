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
int arr[16];
vector<int> sets[12035];
ll dp[1 << 16];
// Masks - Adhoc
// generate all subsets of length 4
// then for each subset try all unique ways of assigning the coefficients in 4!
// for each of them find the non intersecting subsets which have the same sum
// for these 8 numbers you can now form a proper row/col
// make sure you avoid rotations and reversals. So count the above pairs only once.
// Now iterate over all subsets of length 8, and obtain their reverse by xor, and multiply numbers to make both.
int main() {
	ios
	int b[4];
	int tc = 1;
	while (true) {
		cin >> arr[0];
		if (arr[0] == 0) {
			break;
		}
		assert(arr[0] <= 1024);
		memset(dp,0,sizeof(dp));
		for (int i = 0 ; i < 10235 ; ++i) {
			sets[i].clear();
		}
		for (int i = 1 ; i < 16 ; ++i) {
			cin >> arr[i];
			assert(arr[i] <= 1024);
		}
		sort(arr, arr + 16);

		for (int msk = 0 ; msk < (1 << 16) ; ++msk) {
			if (__builtin_popcount(msk) != 4) {
				continue;
			}

			int ptr = 0;
			for (int j = 0 ; j < 16 ; ++j) {
				if ((msk & (1 << j)) > 0) {
					b[ptr++] = arr[j];
				}
			}
			sort(b, b + 4);
			assert (ptr == 4);
			do {

				int val = 4 * b[0] + 3 * b[1] + 2 * b[2] + b[3];
				REP(k,sets[val]) {
					int x = sets[val][k];
					if ((msk & x) != 0) {
						continue;
					}
					dp[msk | x]++;

				}
				sets[val].pb(msk);


			} while(next_permutation(b,b + 4));
		}

		ll ways = 0;
		for (int msk = 0; msk < (1 << 16) ; ++msk) {
			if (__builtin_popcount(msk) == 8) {
				ways += 1LL*dp[msk] * dp[msk ^ ((1 << 16) - 1)];
			}
		}
		cout << "Case "<<(tc++)<<": ";
		cout << ways/2 << "\n";
	}

}

