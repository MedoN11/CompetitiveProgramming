#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include "testlib.h"
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
#include "testlib.h"
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
typedef pair<pii,int> en;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
// LOE - Probability
// linearity of expectation
// for each position, fix a value, then calculate the leftmost position that would block it
// duplicates will not be an issue when permuting as they will cancel each other.
const int maxn = 1005;
double c[maxn][maxn];
double f[maxn];
int main() {
	int t;
	scanf("%d",&t);
	f[0] = 1;
	for (int i =1 ; i < maxn ; ++i) {
		f[i] = i * f[i - 1];
	}
	for (int i = 0 ; i < maxn ; ++i) {
		c[i][0] = 0;
		for (int j = 0 ; j < maxn; ++j) {
			c[i][j] = 0;
		}
	}
	c[0][0] = 1;
	for (int i = 1 ; i < maxn ; ++i) {
		c[i][0] = 1;
		for (int j = 1 ; j < maxn; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	while (t--) {
		int n; scanf("%d",&n);
		vector<int> v;
		for (int i = 0 ; i < n ; ++i) {
			int x; scanf("%d",&x);
			v.pb(x);
		}
		sort(all(v));
		double exp = 0.0;
		for (int i = 0 ; i < n ; ++i){
			int less = i;
			int eq = 0;
			while (v[less] == v[i]) {
				--less;
				++eq;
			}
			less++;
			int more = n - less - 1;
			for (int j = 0 ; j < n ; ++j) {
				for (int k = j - 1; k >= 0; --k) {
					int d = j - k;
					int rem = j - k - 1;
					if (less >= rem && n - 2 >= rem) {
						double p = (more * (c[less][rem]) * f[rem] * f[n - (rem) - 2]) / f[n];
						exp += p * d;
					}

				}
				int d = j + 1;
				int rem = j;
				double p = (c[less][rem]) * f[rem] * f[n - rem - 1];
				p /= f[n];
				exp += p*d;
			}
		}


		printf("%.2f\n",exp);
	}
}
