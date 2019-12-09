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

// Dynamic Programming

int dp[5001][2501][2][2];
int n;
int a[5005];

int solve(int ind, int rem, int prv, int f) {
	if (rem == 0)
		return 0;
	if (ind == n) {
		return 1 << 30;
	}
	int &ret = dp[ind][rem][prv][f];
	if (ret != -1) {
		return ret;
	}

	ret = 1 << 30;
	int val = a[ind];
	if (f) {
		val = a[ind - 1] - 1;
	}
	// i was larger than prev
	if (prv) {
		if (ind + 1 == n || val > a[ind + 1]) {
			ret = min(ret, solve(ind + 1, rem - 1, 0, 0));
		} else {
			ret = min(ret,
					a[ind + 1] - val + 1 + solve(ind + 1, rem - 1, 0, 1));
			if (val == a[ind + 1])
				ret = min(ret, 1 + solve(ind + 1, rem, 1, 0));
			ret = min(ret, solve(ind + 1, rem, a[ind + 1] > val, 0));
		}
	} else {
		ret = min(ret,
				solve(ind + 1, rem, ind == n - 1 || val < a[ind + 1], 0));
		if (ind != n - 1 && val >= a[ind + 1]) {
			ret = min(ret, val - a[ind + 1] + 1 + solve(ind + 1, rem, 1, 0));
		}
	}
	return ret;
}
int main() {
	cin >> n;
	a[n] = 1 << 30;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
//	n = 5000;
//	for (int i = 0 ; i < n ; ++i) {
//		a[i] = rand() % 1000*1000*1000 + 5;
//	}
	memset(dp, -1, sizeof(dp));
	for (int k = 1; k <= (n + 1) / 2; ++k) {
		printf("%d ", solve(0, k, 1, 0));
	}
}
