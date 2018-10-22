#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include <deque>
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
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
typedef pair<pii,int> en;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
const int maxn = 1005;
int n,m;
char grid[maxn][maxn];
int dis[maxn][maxn];

// 0 - 1 BFS using a deque
// The graph costs are 0 or 1 -- special graph
bool valid(pii s) {
	return s.first >= 0 && s.first < n && s.second >= 0 && s.second < m;
}
pii transform(pii s,int x) {

	if (x == 0) {
		return pii(s.first - 1,s.second);
	}
	if (x == 1) {
		return pii(s.first - 1,s.second + 1);
	}
	if (x == 7) {
		return pii(s.first - 1,s.second - 1);
	}
	if (x == 2) {
		return pii(s.first,s.second + 1);
	}
	if (x == 6) {
		return pii(s.first,s.second - 1);
	}
	if (x == 5) {
		return pii(s.first + 1,s.second - 1);
	}
	if (x == 4) {
		return pii(s.first + 1,s.second);
	}
	if (x == 3) {
		return pii(s.first + 1,s.second + 1);
	}
}
bool seen[maxn][maxn];
int solve(pii s,pii t) {
	queue<pair<int,pii> > q;
	memset(seen,0,sizeof(seen));
	deque<pair<int,pii> > deq;
	deq.push_back(make_pair(0,s));
	while (!deq.empty()) {
		pair<int,pii> r = deq.front(); deq.pop_front();
		pii p = r.second;
		int i = p.first, j = p.second;
		if (seen[i][j]) {
			continue;
		}
		seen[i][j] = true;
		if (t.first == i && t.second == j) {
			return r.first;
		}
		pii nxt = transform(p,grid[i][j] - '0');
		if (valid(nxt)) {
			deq.push_front(make_pair(r.first,nxt));
		}
		for (int k = 0 ; k <= 7 ; ++k) {
			nxt = transform(p,k);
			if (valid(nxt)) {
				deq.push_back(make_pair(r.first + 1,nxt));
			}
		}

	}
	assert(false);

}
int main() {
	ios
	cin >> n >> m;

	string str;
	for (int i = 0 ; i < n ; ++i) {
		cin >> str;
		for (int j = 0 ; j < m ; ++j) {
			grid[i][j] = str[j];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		pair<int,int> src,dest;
		cin >> src.first >> src.second >> dest.first >> dest.second;
		--src.first; --src.second; --dest.first; --dest.second;
		cout << solve(src,dest) << "\n";
	}


}
