#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int n;
const int maxn = 100005;
int a[maxn];
long long inf = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 1;

// Inclusion Exclusion + bitmasks

long long gcd(long long a, long long b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
	long long tmp = b / gcd(a, b);
	if (a > inf / tmp)
		return inf;
	return a * tmp;
}
vector<pair<int, long long> > lcms;
void go() {
	for (int msk = 1; msk < (1 << n); ++msk) {
		int par = 0;
		long long m = 1;
		for (int j = 0; j < n; ++j) {
			if (msk & (1 << j)) {
				++par;
				m = lcm(m, a[j]);
			}
		}
		if (m == inf)
			continue;
		lcms.push_back(make_pair((par & 1), m));
	}
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int d;
	cin >> d;
	go();
	for (int i = 0; i < d; ++i) {
		long long l, r;
		scanf("%lld %lld", &l, &r);
		long long sum = 0;
		for (int i = 0; i < lcms.size(); ++i) {
			if (lcms[i].first) {
				sum += (r / lcms[i].second) - (l - 1) / lcms[i].second;
			} else {
				sum -= (r / lcms[i].second) - (l - 1) / lcms[i].second;
			}
		}
		printf("%lld\n", sum);
	}
}
