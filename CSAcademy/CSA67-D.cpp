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
typedef vector<int> vi;

// Sweep + Segment Tree
// Task of painting segments
struct Segment {
	int l,r,y;
	Segment() {}
	Segment(int l_,int r_,int y_) {
		l = l_;
		r = r_;
		y = y_;
	}
	bool operator<(const Segment &s) const {
		return y < s.y;
	}
};
const int maxn = 100005;
Segment segs[maxn];
int lo[4*maxn],hi[4*maxn],ans[4*maxn],lazy[4*maxn];
int n,m;
void build(int ind,int l,int r) {	lo[ind] = l, hi[ind] = r;
if(lo[ind] == hi[ind]) {
	ans[ind] = l;
	return;

}
int mid = l + (r - l) / 2;
build(ind*2,l,mid);
build(ind*2+1,mid + 1,r);
}
void prop(int ind) {
	lazy[ind*2] = lazy[ind];
	lazy[ind*2+1] = lazy[ind];
	ans[ind*2] = ans[ind*2+1] = ans[ind];
	lazy[ind] = 0;
}
void update(int ind,int l,int r,int c) {
	if(r < lo[ind] || hi[ind] < l) return;
	if(l <= lo[ind] && hi[ind] <= r) {
		lazy[ind] = c;
		ans[ind] = c;
		return;
	}
	if(lazy[ind]) {
		prop(ind);
	}
	update(ind*2,l,r,c);
	update(ind*2+1,l,r,c);
}
int query(int ind,int p) {
	if(p < lo[ind] || p > hi[ind])
		return -1;
	if(lo[ind] == p && hi[ind] == p) {
		return ans[ind];
	}
	if(lazy[ind]) {
		prop(ind);
	}
	return max(query(ind * 2,p), query(ind*2 + 1,p));
}
int main() {

	scanf("%d %d",&n,&m);
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d %d %d",&segs[i].l,&segs[i].r,&segs[i].y);
	}
	build(1,0,maxn - 1);
	//cerr << query(1,1) << "\n";
	sort(segs,segs + n);
	for (int i = 0 ; i < n ; ++i) {
		int from = segs[i].l, to = segs[i]. l + (segs[i].r - segs[i].l) / 2;
		int cur = query(1,from);

		update(1,from,to,cur);
		from = to + 1, to = segs[i].r;
		cur = query(1,to);
		update(1,from,to,cur);
	}
	int x;
	while(m--) {
		scanf("%d",&x);
		printf("%d\n",query(1,x));
	}
}



