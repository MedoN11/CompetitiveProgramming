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
const int maxn = 200005;
vector<int> tree[maxn];
int tmp = 0;
int sz[maxn];
int pr[maxn];
set<int> *s[maxn];
int n;
int res = 1 << 30;
int bigch = -1;
int a = -1, b = -1, c = -1;
int rr = 1 << 30;
void dfs1(int u, int p = -1) {
	sz[u] = 1;
	REP(i,tree[u])
	{
		int v = tree[u][i];
		if (v == p) {
			continue;
		}
		dfs1(v, u);
		sz[u] += sz[v];
		pr[v] = u;
	}
}

void update(int a, int b, int c) {
	int arr[3] = { a, b, c };
	sort(arr, arr + 3);
	res = min(res, arr[2] - arr[0]);
}
void solve(int u) {

	s[u] = new set<int>();
	int bigch = -1;
	REP(i,tree[u])
	{
		int v = tree[u][i];
		if (v == pr[u]) {
			continue;
		}
		if (bigch == -1 || sz[v] > sz[bigch]) {
			bigch = v;
		}
		solve(v);
		// cut this edge
		int top = n - sz[v];
		int need = (sz[v] + 1) / 2;
		set<int>::iterator it = s[v]->lower_bound(need);
		if (it != s[v]->end()) {
			update(top, *it, sz[v] - *it);
		}
		if (it != s[v]->begin()) {
			--it;
			update(top, *it, sz[v] - *it);
		}

	}
	if (bigch != -1) {
		s[u] = s[bigch];
		REP(i,tree[u])
		{
			int v = tree[u][i];
			if (v == pr[u]) {
				continue;
			}
			if (v != bigch) {
				for (set<int>::iterator it = s[v]->begin(); it != s[v]->end();
						it++) {
					int cur = *it;
					int rem = n - cur;
					set<int>::iterator it2 = s[u]->lower_bound((rem + 1) / 2);
					if (it2 != s[u]->end()) {
						update(cur, *it2, rem - *it2);
					}
					if (it2 != s[u]->begin()) {
						--it2;
						update(cur, *it2, rem - *it2);
					}
				}
			}
		}

		REP(i,tree[u])
		{
			int v = tree[u][i];
			if (v == pr[u]) {
				continue;
			}
			if (v != bigch) {
				for (set<int>::iterator it = s[v]->begin(); it != s[v]->end();
						it++) {
					s[u]->insert(*it);
				}
			}
		}
	}
	s[u]->insert(sz[u]);

}
int main() {
	cin >> n;
	int u, v;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d", &u, &v);
		--u, --v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs1(0);
	solve(0);
	cout << res << endl;

}
