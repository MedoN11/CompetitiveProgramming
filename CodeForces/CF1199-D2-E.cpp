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
#define ll  long long
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
const int maxn = 400005;

// Attempt to find a matching greedily. Start with a set S of empty edges, and iterate over all edges
// if adding this edge to the set won't violate the constraints of matching  then add it.
// once this ends, if we the matching have n >= edges then great, we are done.
// otherwise let's look at all edges not in this matching, they are of size at least (n + 2), and form an independent set, why?
// if they do not form an independent set, then it means there exists two nodes (u,v) not in the matching where an edge exists between (u,v) but in this case
// our greedy algorithm would have definitely add it, so by contradiction the remaining nodes form an independent set.

// 3n - (n - 1) * 2
// 3n - (2n - 2)
// 3n - 2n + 2
// n + 2
bool used[maxn];
int main() {
	int n, m, t, u, v;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		vector<int> match;
		for (int i = 1; i <= 3 * n; ++i)
			used[i] = false;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &u, &v);
			if (used[v] || used[u]) {
				continue;
			}
			match.pb(i + 1);
			used[u] = used[v] = true;
		}
		if (sz(match) >= n) {
			puts("Matching");
			for (int i = 0; i < n; ++i)
				printf("%d ", match[i]);
			puts("");
		} else {
			int rem = n;
			puts("IndSet");
			for (int i = 1; i <= 3 * n && rem; ++i) {
				if (!used[i]) {
					printf("%d ", i);
					--rem;
				}
			}
			puts("");
		}
	}
}
