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
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;;

// Maintain 60 Seg trees ( lcm from 2 to 6)
// merge for responses
const int maxn = 4*100005;
int a[maxn];
int seg[60][maxn];
int solve(int ind,int lo,int hi,int l,int r,int t) {
	if(l <= lo && hi <= r)
		return seg[t][ind];
	if(l > hi || r < lo)
		return 0;
	int mid = lo + (hi - lo) / 2;
	int x = solve(ind*2,lo,mid,l,r,t);
	int y = solve(ind*2+1,mid + 1,hi,l,r,(t + x) % 60);
	return x + y;
}

void upd(int ind,int lo,int hi,int p,int v) {
	if(p < lo || p > hi)
		return;
	if(lo == p && p == hi) {
		for(int j = 0 ; j < 60 ; ++j) {
			seg[j][ind] = 1;
			if(j % v == 0) seg[j][ind]++;
		}
		return;
	}
	int mid = lo + (hi - lo) / 2;
	upd(ind*2,lo,mid,p,v);
	upd(ind*2+1,mid + 1,hi,p,v);
	for(int j = 0 ; j < 60 ; ++j) {
		seg[j][ind] = seg[j][ind*2] + seg[(j + seg[j][ind*2])%60][ind*2+1];
	}
}
int n;
int main() {
	ios
	cin >> n;
	for(int i = 0 ; i < n ; ++i) {
		cin >> a[i];
		upd(1,0, n - 1,i,a[i]);
	}

	int q;
	cin >> q;
	while(q--) {
		char c;
		int l,r;
		cin >> c >> l >> r;
		if(c == 'A') {
			--l; --r;
			cout << solve(1,0,n - 1,l,r - 1,0) << "\n";


		} else {
			--l;
			upd(1,0,n - 1,l,r);
		}
	}

}
