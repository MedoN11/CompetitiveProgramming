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

// dp..

// answer will never exceed ~10.
// if number of remaining eggs >= log2(n), we can just simulate it by BS.
int ans = 0;
int dp[1005][105];
int n, k;

int solve(int n, int rem) {
	if (n == 0)
		return 0;
	if (rem == 0)
		return 1 << 29;
	int &ret = dp[n][rem];
	if (ret != -1)
		return ret;
	ret = (1 << 29);

	for (int k = 1; k <= n; k++) {
		// throw
		if (rem) {
			int broke = solve(k - 1, rem - 1);
			int solid = solve(n - k, rem);
			ret = min(ret, 1 + max(broke, solid));
		}
	}
	return ret;
}

int main() {

	memset(dp, -1, sizeof(dp));
	while (scanf("%d %d", &k, &n)) {
		if (n == 0 || k == 0)
			break;
		printf("%d\n", solve(n, min(12, k)));
	}
}
