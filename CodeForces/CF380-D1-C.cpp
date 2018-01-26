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
const int maxn = 1000001;
char s[4*maxn];
int lo[4*maxn],hi[4*maxn],correct[4*maxn],open[4*maxn],close[4*maxn];
void merge(int ind) {
	correct[ind] = correct[ind * 2] + correct[ind * 2 + 1];
	correct[ind] += min(open[ind * 2],close[ind * 2 + 1]);
	int tmp = min(open[ind * 2],close[ind * 2 + 1]);
	open[ind] = open[ind * 2] + open[ind * 2 + 1] - tmp;
	close[ind] = close[ind * 2] + close[ind * 2 + 1] - tmp;
}
struct res {
	int open,close,correct;
	res(int o,int c,int cor) {
		open = o,close = c,correct = cor;
	}
};
void build(int ind,int l,int r) {
	lo[ind] = l, hi[ind] = r;
	if(lo[ind] == hi[ind]) {
		if(s[l] == ')') ++close[ind];
		else ++open[ind];
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind * 2,l,mid);
	build(ind*2+1,mid + 1,r);
	merge(ind);
}
res merge(res &a,res &b) {
	res c = res(0,0,0);
	c.correct = a.correct + b.correct + min(a.open,b.close);
	int tmp = min(a.open,b.close);
	c.open = a.open + b.open - tmp;
	c.close = a.close + b.close - tmp;
	return c;
}
res query(int ind,int l,int r) {
	if(l > hi[ind] || r < lo[ind])
		return res(0,0,0);
	if(l <= lo[ind] && hi[ind] <= r)
		return res(open[ind],close[ind],correct[ind]);
	res left = query(ind*2,l,r);
	res right = query(ind*2+1,l,r);
	return merge(left,right);
}
int main() {
	scanf("%s",s); int n = strlen(s);
	int q; cin >> q;
	int l,r;
	build(1,0,n - 1);
	while(q--) {
		scanf("%d %d",&l,&r);
		--l; --r;
		printf("%d\n",query(1,l,r).correct<<1);
	}

}
