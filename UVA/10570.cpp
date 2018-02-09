
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
const int maxn = 1e7 + 1;
int n;
int me[510];
// 1 4 5 6 7 8 9
vector<int> nxt;
bool seen[510];
int c = 0;
void dfs(int u) {
	if(seen[u])
		return;
	seen[u] = 1;
	++c;
	dfs(me[nxt[u]]);
}
int solve(vector<int> a,vector<int> &b) {
	memset(seen,0,sizeof(seen));
	nxt = a;
	for (int i = 0 ; i < n ; ++i) {
		me[b[i]] = i;
	}
	int s = 0;
	REP(i,a) {
		if(seen[a[i]])
			continue;
		c = 0;
		dfs(a[i]);
		s += c - 1;
	}


	return (s);
}
//
int main() {
	while(scanf("%d",&n) && n) {
		vector<int> p(n);
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d",&p[i]);
			--p[i];
			//cerr << p[i] << " ";
		}
		//cerr << "\n";
		vector<int> q(n);
		int res = 1 << 30;
		for (int i = 0 ; i < n ; ++i) {
			q[0] = i;
			q[1] = (i + 1 % n);
			q[n - 1] = (i - 1 + n ) % n;
			for (int j = 1 ; j < n - 1 ; ++j) {
				q[j] = (q[j - 1] + 1) % n;
			}
//			REP(i,q) cerr << q[i] << " ";
//			cerr << "\n";
			res = min(res,solve(p,q));
			q[0] = i;
			q[1] = (i - 1 + n) % n;
			q[n - 1] = (i + 1) % n;
			for (int j = 1 ; j < n - 1 ; ++j) {
				q[j] = (q[j - 1] - 1 + n) % n;
			}
//			REP(i,q) cerr << q[i] <<" ";
//			cerr << "\n";
			res = min(res,solve(p,q));
		}
		printf("%d\n",res);

	}

}

