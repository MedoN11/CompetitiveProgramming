#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
const int maxn = 200005;

// k * (i - 1) < n
// (i - 1) < k

// Start by a slow bruteforce then optimize it.
// Adhoc + little ds
vector<int> v;
int lo[4 * maxn], hi[4 * maxn];
vector<int> ans[4 * maxn];
void build(int ind, int l, int r) {
	lo[ind] = l, hi[ind] = r;
	if (lo[ind] == hi[ind]) {
		ans[ind].push_back(v[l]);
		return;
	}
	int m = (l + r) / 2;
	build(ind * 2, l, m);
	build(ind * 2 + 1, m + 1, r);

	int i = 0, j = 0;
	vector<int> lft = ans[ind * 2], ryt = ans[ind * 2 + 1];
	while (i < lft.size() && j < ryt.size()) {
		if (lft[i] < ryt[j]) {
			ans[ind].push_back(lft[i++]);
		} else {
			ans[ind].push_back(ryt[j++]);
		}
	}
	while (i < lft.size())
		ans[ind].push_back(lft[i++]);
	while (j < ryt.size())
		ans[ind].push_back(ryt[j++]);
}

int query(int ind, int l, int r, int v) {
	if (l <= lo[ind] && hi[ind] <= r) {
		vector<int>::iterator it = upper_bound(ans[ind].begin(), ans[ind].end(),
				v - 1);
		return it - ans[ind].begin();
	}
	if (lo[ind] > r || hi[ind] < l)
		return 0;
	return query(ind * 2, l, r, v) + query(ind * 2 + 1, l, r, v);
}
int main() {
	int n;
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	//v[i] = rand() % n + 1;
	build(1, 1, n);
	//cout << query(1, 1, 5, 5);
	int p = 0;
	int mn = n;
	int res;
	for (int k = 1; k <= n - 1; ++k, ++p) {
		++p;
		res = 0;
		for (int i = 1; i <= min(mn, n / k + 1); ++i) {
			if (k * (i - 1) > n) {
				mn = min(mn, i);
				break;
			}
			int l = max(i + 1, k * (i - 1) + 2);
			int r = min(n, k * i + 1);
			res += query(1, l, r, v[i]);

		}
		printf("%d ", res);
	}
}

