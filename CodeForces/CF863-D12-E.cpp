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
const int maxn = 6*100005;
// Cordiante compression + Seg Tree
typedef  pair<int,int> pii;
int diff[maxn];
int n;
int lo[4*maxn];
int hi[4*maxn];
int val[4*maxn];
void upd(int ind) {
	val[ind] = min(val[ind*2],val[ind*2+1]);
}
void build(int ind,int l,int r) {
	lo[ind] = l, hi[ind] = r;
	if(l == r) {
		val[ind] = diff[l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind *2,l,mid);
	build(ind*2+1,mid + 1,r);
	upd(ind);
}
void update(int ind,int pt,int v) {
	if(pt < lo[ind] || pt > hi[ind])
		return;
	if(pt == lo[ind] && pt == hi[ind]) {
		val[ind] = v;
		return;
	}
	update(ind*2,pt,v);
	update(ind*2+1,pt,v);
	upd(ind);
}
int query(int ind,int l,int r){
	if(lo[ind] >= l && hi[ind] <= r)
		return val[ind];
	if(l > hi[ind] || r < lo[ind])
		return  (1 << 30);
	return min(query(ind*2,l,r),query(ind*2+1,l,r));

}
int main() {
	int n;
	scanf("%d",&n);
	vector<pii> v;
	map<int,int> mp;
	for (int i = 0 ; i < n ; ++i) {
		int l,r;
		scanf("%d %d",&l,&r);
		v.pb(pii(l,r));
		mp[l] = 1;
		mp[r] = 1;
		mp[r + 1] = 1;

	}

	int ind = 0;
	for(map<int,int>::iterator it = mp.begin() ; it != mp.end(); it++) {
		it->second = ind++;
	}
	REP(i,v){
		diff[mp[v[i].first]]++;
		diff[mp[v[i].second + 1]]--;
		//cerr << mp[v[i].first] << " " << mp[v[i].second+1] << "\n";

	}

	for (int i = 1 ; i < maxn; ++i) {
		diff[i] += diff[i - 1];

	}
	build(1,0,ind - 1);
	//cerr << diff[0] << " " << diff[1] << " " <<query(1,0,1) <<"\n";
	REP(i,v) {
		int l = v[i].first,r = v[i].second;

		int tot = query(1,mp[l],mp[r]);

		if(tot >= 2) {
			cout << (i + 1) << "\n";
			return 0;
		}
	}
	cout << "-1\n";

}

