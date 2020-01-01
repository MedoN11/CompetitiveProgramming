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
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100005;
int n, L;
int dd[maxn][2];
pii pr[maxn][2];
int x[maxn], d[maxn], t[maxn], p[maxn];
vector<pair<int, int> > g[maxn];
int main() {
	cin >> n >> L;
	if (n == 0) {
		cout << L << endl;
		puts("0");
		return 0;
	}
	vector<pair<int, int> > prs;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d %d", &x[i], &d[i], &t[i], &p[i]);
		p[i] = x[i] - p[i];
		prs.push_back(make_pair(p[i], i));
	}
	sort(prs.begin(), prs.end());
//	cerr << "ooo\n";
//	for (int i = 0 ; i < n ; ++i) cerr << prs[i].first << " ";
//	cerr <<"ooo\n";
	priority_queue<pair<int, pii>, vector<pair<int, pii> >,
			greater<pair<int, pii> > > pq;
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < 2; ++j) {
			dd[i][j] = 1 << 30;
		}
	}
	for (int i = 0; i < n; i++) {
		if (p[i] >= 0)
			pq.push(make_pair(p[i], pii(i, 0))), dd[i][0] = p[i], pr[i][0] =
					pii(-1, -1);
		//pq.push(make_pair(x[i], pii(i, 1)));
	}
	int ans = -1;
	vector<int> st;
	while (!pq.empty()) {
		pair<int, pii> out = pq.top();
		int dis = out.first, ind = out.second.first, tp = out.second.second;
		pq.pop();
//		cerr << dis << " " << ind << " " << tp << endl;
//		if (tp)
//			cerr << x[ind] + d[ind] << endl;
//		else
//			cerr << p[ind] << endl;

		if (ind == n) {
			ans = dis;
			pii cur = pr[ind][tp];
			while (cur.first != -1 && cur.second != -1) {
				if (cur.second)
					st.push_back(cur.first + 1);
				cur = pr[cur.first][cur.second];
			}
			break;
		}

		// go to end
		int cst = dis + L - (tp ? (x[ind] + d[ind]) : p[ind]);
		if (dd[n][0] > cst) {

			pq.push(make_pair(cst, pii(n, 0)));
			dd[n][0] = cst;
			pr[n][0] = pii(ind, tp);
		}

		if (tp) {
			// go to prev
			int prev = lower_bound(prs.begin(), prs.end(),
					make_pair(x[ind] + d[ind], -1)) - prs.begin();
			prev--;
			if (prev >= 0) {
				prev = prs[prev].second;
				int cst = (x[ind] + d[ind]) - p[prev] + dis;
				if (dd[prev][0] > cst) {
					dd[prev][0] = cst;
					pr[prev][0] = make_pair(ind,1);
				}
			}
			// xd val so go to a p val
			int to = upper_bound(prs.begin(), prs.end(),
					make_pair(x[ind] + d[ind], ind)) - prs.begin();
			if (to == n)
				continue;
			to = prs[to].second;
			//assert(p[to] >= (x[ind] + d[ind]));
			int cst = (p[to] - (x[ind] + d[ind]) + dis);
			if (dd[to][0] > cst) {
				pq.push(make_pair(cst, pii(to, 0)));
				dd[to][0] = cst;
				pr[to][0] = pii(ind, tp);
			}
		} else {

			// take the jump and move forward
			//assert(x[ind] >= p[ind]);
			cst = (x[ind] - p[ind] + dis + t[ind]);
			if (dd[ind][1] > cst) {
				pq.push(make_pair(cst, pii(ind, 1)));
				dd[ind][1] = cst;
				pr[ind][1] = pii(ind, tp);
			}

			// go to prev p
			int prev = lower_bound(prs.begin(), prs.end(), pii(p[ind], ind))
					- prs.begin();
			//assert(prev != n);
			if (prev != 0) {
				--prev;
				prev = prs[prev].second;
				int cst = p[ind] - p[prev] + dis;
				if (p[prev] >= 0 && dd[prev][0] > cst) {
					pq.push(make_pair(cst, pii(prev, 0)));
					dd[prev][0] = cst;
					pr[prev][0] = make_pair(ind, 0);
				}
			}
			// go to next p
			int to = upper_bound(prs.begin(), prs.end(), make_pair(p[ind], ind))
					- prs.begin();
			if (to == n)
				continue;
			to = prs[to].second;
			cst = p[to] - p[ind] + dis;
			if (dd[to][0] > cst) {
				pq.push(make_pair(cst, pii(to, 0)));
				dd[to][0] = cst;
				pr[to][0] = pii(ind, tp);
			}

		}

	}

	cout << ans << endl;
	cout << st.size() << endl;
	for (int i = 0; i < st.size(); ++i)
		printf("%d ", st[i]);
}
