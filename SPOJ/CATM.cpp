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
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define time __time
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 4*100005;
int n,m;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
bool ok(int i,int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
vector<int> bfs(int u) {
	vector<int> dis(n*m,1 << 30);
	queue<int> q;
	dis[u] = 0;
	q.push(u);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		int i = v / m , j = v % m;
		for(int k = 0 ; k < 4 ; ++k) {
			int x = dx[k] + i, y = j + dy[k];
			if(ok(x,y)) {
				int st = x * m + y;
				if(dis[st] == 1 << 30) {
					dis[st] = dis[v] + 1;
					q.push(st);
				}
			}
		}
	}
	return dis;

}
int main() {

	scanf("%d %d",&n,&m);
	int q;
	scanf("%d",&q);
	while(q--) {
		int x,y;
		cin >> x >> y;
		--x;--y;
		vector<int> p = bfs(x * m + y);
		cin >> x >> y;
		--x; --y;
		vector<int> c1 = bfs(x * m + y);
		cin >> x >> y;
		--x; --y;
		vector<int> c2 = bfs(x * m + y);
		bool f = 1;
		for (int i = 0 ; i < n && f ; ++i) {
			for (int j = 0 ; j < m  && f; ++j) {
				if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
					int curr = i * m + j;
					if(p[curr] < c1[curr] && p[curr] < c2[curr]) {
						puts("YES");
						f = 0;
					}
				}
			}
		}
		if(f) puts("NO");
	}

}
