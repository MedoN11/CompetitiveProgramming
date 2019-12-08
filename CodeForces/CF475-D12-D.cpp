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
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int, int> pii;
typedef vector<int> VI;
typedef vector<ll> VL;
#define ios std::ios_base::sync_with_stdio(false);
#define LSOne(x) ((x) & (-(x)))
const int maxn = 100005;

// DS + gcd
// Relies on this property:
// If you have a set S, and add a number to it, then the gcd will stay the same or will decrease by at least a factor of 2.
// so if we add N numbers to the set, we can have at most O(logn) distinct GCD values.
int arr[maxn];
int n;
map<int, long long> mp;

int table[20][200000];  // 2^16 > 10e5
int logs[200000 + 2];

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
void init() {
	for (int i = 0; i <= logs[n]; i++) {
		int curLen = 1 << i; // 2^i
		for (int j = 0; j + curLen <= n; j++) {
			if (curLen == 1) {
				table[i][j] = arr[j];
			} else {
				table[i][j] = gcd(table[i - 1][j],
						table[i - 1][j + (curLen / 2)]);
			}
		}
	}
}

int query(int l, int r) {
	int p = logs[r - l + 1];
	int pLen = 1 << p; // 2^p
	return gcd(table[p][l], table[p][r - pLen + 1]);
}

int main() {
	cin >> n;
	logs[1] = 0;
	for (int i = 2; i <= n; i++) {
		logs[i] = logs[i / 2] + 1;
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	init();
	for (int i = 0; i < n; ++i) {
		int cur = arr[i];
		int lst = i;
		int pp = 0;
		while (lst != n) {
			int lo = i, hi = n - 1;
			int ans = lst;
			int rr = 0;
			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if (query(i, mid) >= cur)
					lo = mid + 1, ans = mid;
				else
					hi = mid - 1;
			}
			mp[cur] += 1ll * ans - lst + 1;
			if (ans == n - 1 || i == n - 1)
				break;
			lst = ans + 1;
			cur = gcd(cur, arr[ans + 1]);
		}
	}
	int q, x;
	cin >> q;
	while (q--) {
		scanf("%d", &x);
		if (mp.find(x) == mp.end())
			puts("0");
		else
			printf("%lld\n", mp[x]);
	}

}
