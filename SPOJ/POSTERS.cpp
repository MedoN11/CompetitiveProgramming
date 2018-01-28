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
const int maxn = 6*40001;
int lazy[4*maxn],lo[4*maxn],hi[4*maxn];
map<int,int> cord;
int t,n;
#define clr(x) memset(x,0,sizeof(x))
void build(int ind,int l,int r) {
	lo[ind] = l, hi[ind] = r;
	if(lo[ind] == hi[ind]) {
		lazy[ind] = 0;
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind*2,l,mid);
	build(ind*2+1,mid + 1,r);
	lazy[ind] = 0;
}
void prop(int ind) {
	lazy[ind * 2] = lazy[ind];
	lazy[ind * 2 + 1] = lazy[ind];
	lazy[ind] = 0;
}
void update(int ind,int l,int r,int c) {
	if(l > hi[ind] || r < lo[ind])
		return;
	if(l <= lo[ind] && hi[ind]<= r) {
		lazy[ind] = c;
		return;
	}
	if(lazy[ind]) {
		prop(ind);
	}
	update(ind * 2,l,r,c);
	update(ind * 2 + 1,l,r,c);
}
set<int> s;
void count(int ind) {

	if(lazy[ind]) {
		s.insert(lazy[ind]);
		return;
	}
	if(lo[ind] == hi[ind]) {
		return;
	}
	count(ind*2);
	count(ind*2+1);

}
int main() {
	cin >> t;
	while(t--) {
		clr(lazy),clr(lo),clr(hi);

		s.clear();
		cord.clear();
		scanf("%d",&n);

		int l,r;
		vector<pii> v;
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d %d",&l,&r);
			cord[l - 1] = 1;
			cord[r - 1] = 1;
			cord[l + 1] = 1;
			cord[r + 1] = 1;
			cord[l] = 1;
			cord[r] = 1;
			v.pb(pii(l,r));
		}

		int cnt = 0;
		for(map<int,int>::iterator it =cord.begin() ;it != cord.end() ;it++) {
			it->second = cnt++;
		}
		build(1,0,cnt - 1);
		REP(i,v) {
			v[i].first = cord[v[i].first],v[i].second = cord[v[i].second];
			update(1,v[i].first,v[i].second,i + 1);
		}
		count(1);
		printf("%d\n",sz(s));


	}
}
