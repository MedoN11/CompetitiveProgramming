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
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
bool vis[20 * 1000000];
int n,m;
int transform(int m1,int m2) {
	int res = 0;
	for (int i = 0 ; i < n ; ++i) {
		int b1 = (m1 & (1 << i)) ? 1 :0;
		int b2 = (m2 & (1 << i)) ? 1 :0;
		res *= 3;
		if (b1 && b2) {
			res += 2;
		}
		if (b1 && !b2) {
			res++;
		}
	}
	return res;
}
int larger(int m1,int m2,int s) {
	for (int i = n - 1; i >= 0 ; --i) {
		int b1 = (m1 & (1 << i)) ? 1 :0;
		int b2 = (m2 & (1 << i)) ? 1 :0;
		if (b1 && b2) {
			if (s == 3) {
				return i;
			}
		}
		if (b1 && !b2) {
			if (s == 2) {
				return i;
			}
		}
		if (!b1 && !b2) {
			if (s == 1) {
				return i;
			}
		}
	}
	return -1;
}
int main() {
	while (scanf("%d %d",&n,&m)) {
		queue<pair<pii,int > > q;
		int m1 = 0,m2 = 0;
		int sz;
		cin >> sz;
		int x;
		memset(vis,0,sizeof(vis));
		for (int i = 0 ; i < sz ; ++i) {
			scanf("%d",&x);
		}
		cin >> sz;
		for (int i = 0 ; i < sz ; ++i) {
			scanf("%d",&x); --x;
			m1 |= (1 << x);
		}
		cin >> sz;
		for (int i = 0 ; i < sz ; ++i) {
			scanf("%d",&x); --x;
			m1 |= (1 << x);
			m2 |= (1 << x);
		}
		q.push(make_pair(pii(m1,m2),0));
		int res = 1 << 30;
		set<pii> s;
		while (!q.empty()) {

			pair<pii,int> p = q.front(); q.pop();
			int msk = transform(p.f.f,p.f.s);
			if (vis[msk]) {
				continue;
			}
			if (p.s > m) {
				break;
			}
			vis[msk] = 1;
			int s1 = 0, s3 = 0;
			for (int j = 0 ; j < n ; ++j) {
				int b1 = (p.f.f & (1 << j)) ? 1 :0;
				int b2 = (p.f.s & (1 << j)) ? 1 :0;
				s1 += (!b1 && !b2);
				s3 += (b1 && b2);
			}

			if (s3 == n || s1 == n) {
				res = p.s; break;
			}
			// 1 -> 2
			int one = larger(p.f.f,p.f.s,1), two = larger(p.f.f,p.f.s,2), three = larger(p.f.f,p.f.s,3);
			if (one > two) {
				int m1 = p.f.f | (1 << one), m2 = p.f.s;
				int tmp = transform(m1,m2);
				if (!vis[tmp])
					q.push(make_pair(pii(m1,m2),p.s + 1));
			}
			// 2 -> 1
			if (two > one) {
				int m1 = p.f.f & ~(1 << two), m2 = p.f.s;
				q.push(make_pair(pii(m1,m2),p.s + 1));
			}
			// 2- > 3
			if (two > three) {
				int m1 = p.f.f, m2 = p.f.s | 1 << two;
				int tmp = transform(m1,m2);
				if (!vis[tmp])
					q.push(make_pair(pii(m1,m2),p.s + 1));
			}
			// 3 -> 2
			if (three > two) {
				int m1 = p.f.f, m2 = p.f.s & ~ (1 << three);
				int tmp = transform(m1,m2);
				if (!vis[tmp])
					q.push(make_pair(pii(m1,m2),p.s + 1));
			}


		}
		if (res == 1 << 30) {
			res = -1;
		}
		printf("%d\n",res);

	}
}
