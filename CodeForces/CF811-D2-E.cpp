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
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
const int maxn = 100005;
int arr[11][maxn];
int curr = 0;
int m,n,q;

// Segment Tree with a compressed DSU in each node
struct seg {
	int l,r;
	int comps;
	int dsu_left[11],dsu_right[11];

	void merge(int x,int y) {
		for(int i = 0 ; i < n ; ++i){
			if(dsu_left[i] == x)
				dsu_left[i] = y;
			if(dsu_right[i] == x) {
				dsu_right[i] = y;
			}
		}
	}
};
seg ans[4*maxn];

seg merge(seg a,seg b) {
	if(a.comps == 0)
		return b;
	if(b.comps == 0)
		return a;
	seg s;
	s.comps = a.comps + b.comps;
	s.l = a.l,s.r = b.r;
	for(int i = 0 ; i < n ; ++i) s.dsu_left[i] = a.dsu_left[i];
	for(int i = 0 ; i < n ; ++i)
	s.dsu_right[i] = b.dsu_right[i];
	for(int i = 0 ; i < n ; ++i) {
		if(arr[i][a.r] == arr[i][b.l] && a.dsu_right[i] != b.dsu_left[i]) {
			s.comps--;
			a.comps--;
			s.merge(a.dsu_right[i],b.dsu_left[i]);
			a.merge(a.dsu_right[i],b.dsu_left[i]);
		}
	}
	return s;
}
void build(int ind,int l,int r) {
	if(l == r) {
		seg s;
		s.l = l, s.r = r;
		int c = 0;
		for(int j = 0 ; j < n ; ++j) {
			if(j == 0 || arr[j - 1][l] != arr[j][l]) c++,curr++;
			s.dsu_left[j] = (curr);
			s.dsu_right[j] = (curr);
		}
		s.comps = c;
		ans[ind] = s;
		return;
	}
	int m = l + (r - l ) / 2;
	build(ind << 1,l,m);
	build((ind << 1) | 1,m + 1,r);
	ans[ind] = merge(ans[ind << 1],ans[((ind << 1) | 1)]);
	ans[ind].l = l, ans[ind].r = r;

}



seg query(int ind,int l,int r) {
	seg tmp; tmp.comps = 0;
	if(r < ans[ind].l || l > ans[ind].r)
		return tmp;
	if(l <= ans[ind].l && ans[ind].r <= r)
		return ans[ind];
	return merge(query(ind << 1,l,r),query((ind << 1) | 1,l,r));
}

int main() {
	scanf("%d %d %d",&n,&m,&q);
	for (int i = 0 ; i < n ; ++i) {
		for(int j = 0 ; j < m ; ++j) {
			scanf("%d",&arr[i][j]);
		}
	}
	build(1,0,m - 1);
	while(q--) {
		int l,r;
		scanf("%d %d",&l,&r);
		--l,--r;
		printf("%d\n",query(1,l,r).comps);
	}
}

