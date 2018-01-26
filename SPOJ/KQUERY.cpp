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
typedef pair<pii,pii> entry;
const int maxn = 30001;
int lo[4*maxn],hi[4*maxn], ans[4*maxn];
void build(int ind,int l,int r) {
	lo[ind] = l,hi[ind] = r;
	if(lo[ind] == hi[ind]) {
		ans[ind] = 1;
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind*2,l,mid);
	build(ind*2+1,mid + 1,r);
	ans[ind] = ans[ind * 2] + ans[ind*2+1];
}
void update(int ind,int p) {
	if(p < lo[ind] || p > hi[ind])
		return;
	if(p == lo[ind] && p == hi[ind]) {
		ans[ind] = 0;
		return;
	}
	update(ind*2,p);
	update(ind*2+1,p);
	ans[ind] = ans[ind * 2] + ans[ind*2+1];

}
int query(int ind,int l,int r) {
	if(r < lo[ind] || l > hi[ind])
		return 0;
	if(l <= lo[ind] && hi[ind] <= r) {
		return ans[ind];
	}
	return query(ind*2,l,r) + query(ind*2+1,l,r);
}
int res[ 200001];
int n;
int main() {
	scanf("%d",&n);
	build(1,0, n - 1);
	vector<pii> v;
	int x;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d",&x);
		v.pb(pii(x,i));
	}

	int q;
	cin >> q;
	vector<entry> qur;
	for(int c = 0 ; c < q ; ++c) {
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		--l,--r;

		qur.pb(entry(pii(k,c),pii(l,r)));

	}
	sort(all(v));
	sort(all(qur));
	int ind = 0;
	REP(i,qur) {
		entry e = qur[i];
		//cerr << "hena: " << e.first.first << "\n";
		while(ind < sz(v) && e.first.first >= v[ind].first) {
		//	cerr << v[ind].first << " ";
			update(1,v[ind].second);
			ind++;
		}
		//cerr << "\n";
		res[e.first.second] = query(1,e.second.first,e.second.second);

	}
	for (int i = 0 ; i < q ; ++i) {
		printf("%d\n",res[i]);
	}



}
