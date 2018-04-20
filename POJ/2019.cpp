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
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define F first
#define S second
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define mp make_pair
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left

using namespace std;
int lo[251][4*251],hi[251][4*251];
pii ans[251][4*251];
int mat[251][251];
int n,b,q;
void build(int t,int ind,int l,int r) {
	lo[t][ind] = l, hi[t][ind] = r;
	if(lo[t][ind] == hi[t][ind]) {
		ans[t][ind].F = mat[t][l];
		ans[t][ind].S = mat[t][l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(t,ind*2,l,mid);
	build(t,ind*2+1,mid + 1,r);
	ans[t][ind].F = min(ans[t][ind*2].F,ans[t][ind*2+1].F);
	ans[t][ind].S = max(ans[t][ind*2].S,ans[t][ind*2+1].S);

}
pii query(int t,int ind,int l,int r) {

	if(l > hi[t][ind] || lo[t][ind] > r)
		return pii(300,-300);
	if(l <= lo[t][ind] && hi[t][ind] <= r) {
		return ans[t][ind];
	}

	pii a = query(t,ind*2,l,r);
	pii b = query(t,ind*2+1,l,r);
	a.F = min(a.F,b.F);
	a.S = max(a.S,b.S);

	return a;
}
pii dp[251][251];
int main() {
	scanf("%d %d %d",&n,&b,&q);
	for (int i = 0 ;i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			scanf(" %d",&mat[i][j]);
		}
		build(i,1,0,n - 1);
	}
	//cerr << query(0,1,1,1).F << "\n";
	forn(i,n){
		forn(j,n) {

			if (i + b - 1 < n && j + b - 1 < n) {
				pii res = pii(300,-300);
				fore(k,i,i + b - 1) {

					pii g_ans = query(k,1,j,j + b - 1);
					res.F = min(res.F,g_ans.F);
					res.S = max(res.S,g_ans.S);
				}
				dp[i][j] = res;
			}
		}
	}

	//	cerr << "hena"<<"\n";
	while (q--) {
		int x,y;
		scanf("%d %d",&x,&y);
		--x,--y;
		pii res = dp[x][y];
		//cerr << res.S << " " << res.F << "\n";
		printf("%d\n",res.S - res.F);
	}


}
