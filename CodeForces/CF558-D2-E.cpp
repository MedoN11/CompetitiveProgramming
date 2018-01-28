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
const int maxn = 100005;
// Seg Tree for each character
// Editorial is good enough
int n,q;
char s[maxn];
int lazy[26][4*maxn],ans[26][4*maxn],lo[26][4*maxn],hi[26][4*maxn];
void build(int node,int ind,int l,int r) {
	lo[node][ind] = l, hi[node][ind] = r;
	if(lo[node][ind] == hi[node][ind]) {
		ans[node][ind] = (s[l] - 'a') == node ? 1 : 0;
		lazy[node][ind] = -1;
		return;
	}
	int mid = l + (r - l) / 2;
	build(node,ind * 2,l,mid);
	build(node,ind * 2 + 1,mid + 1,r);
	ans[node][ind] = ans[node][ind * 2] + ans[node][ind * 2 + 1];
	lazy[node][ind] = -1;

}
void upd(int node,int ind) {
	ans[node][ind] = lazy[node][ind] * (hi[node][ind] - lo[node][ind] + 1);
}
void prop(int node,int ind) {
	if(lazy[node][ind] != -1) {
		lazy[node][ind * 2] = lazy[node][ind];
		lazy[node][ind * 2 + 1] = lazy[node][ind];
		upd(node,ind*2);
		upd(node,ind*2+1);
		lazy[node][ind] = -1;
	}
}

void update(int node,int ind,int l,int r,int c) {
	if(r < lo[node][ind] || l > hi[node][ind])
		return;
	if(l <= lo[node][ind] && hi[node][ind] <= r) {
		lazy[node][ind] = c;
		ans[node][ind] = c * (hi[node][ind] - lo[node][ind] + 1);
		return;
	}
	prop(node,ind);
	update(node,ind * 2,l,r,c);
	update(node,ind*2+1,l,r,c);
	ans[node][ind] = ans[node][ind * 2] + ans[node][ind * 2 + 1];

}
int query(int node,int ind,int l,int r) {

	if(r < lo[node][ind] || l > hi[node][ind])
		return 0;
	if(l <= lo[node][ind] && hi[node][ind] <= r) {
		return ans[node][ind];
	}
	prop(node,ind);
	return query(node,ind * 2,l,r) + query(node,ind*2+1,l,r);

}
int f[26];
int main() {
	cin >> n >> q;
	scanf("%s",s);
	for (int i = 0 ; i < 26 ; ++i) {
		build(i,1,0,n - 1);
	}
	//cout << query(0,1,0,n-1)<<"\n";
	while(q--) {

		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		--l,--r;
		for (int i = 0 ; i < 26 ; ++i) {
			f[i] = query(i,1,l,r);
			update(i,1,l,r,0);
		}

		if(k == 1) {
			int ind = l;
			for (int i = 0 ; i < 26 ; ++i) {
				if(f[i]) {
					update(i,1,ind,ind + f[i] - 1,1);
					ind += f[i];
				}
			}
		} else {
			int ind = l;
			for (int i = 25 ; i >= 0 ; --i) {
				if(f[i]) {
					update(i,1,ind,ind + f[i] - 1,1);
					ind += f[i];
				}
			}
		}
	}

	for (int i = 0 ; i < n ; ++i) {
		for(int j = 0 ; j < 26 ; ++j) {
			if(query(j,1,i,i)) {
				printf("%c",(char)(j+'a'));
				break;
			}
		}
	}


}

