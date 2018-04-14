#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include <random>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include <unordered_map>
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
typedef pair<double,int> pii;
#define F first
#define S second
#define MP make_pair
#define LL long long
using namespace std;
deque<pii> xs1,ys1;
int n,k;
const int maxn = 100005;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool f[maxn];
ll go(int xleft,int xright, int yleft,int yright) {
	deque<pii> xs,ys;
	deque<pii>::iterator it = xs1.begin();
	while(it != xs1.end()) xs.push_back(*it),it++;
	it = ys1.begin();
	while(it != ys1.end()) ys.push_back(*it),it++;
	memset(f,0,sizeof(f));
	while(xleft-- > 0 && sz(xs) > 0) {
		pii p = xs.front();
		xs.pop_front();
		f[p.second]  = 1;
	}
	while(xright-- > 0 && sz(xs) > 0) {
		pii p = xs.back();
		xs.pop_back();
		f[p.second]  = 1;
	}


	while (yleft-- > 0 && sz(ys) > 0) {
		pii p = ys.front();
		ys.pop_front();
		if(f[p.second]) ++yleft;
		f[p.second] = 1;
	}
	while (yright-- > 0 && sz(ys) > 0) {
		pii p = ys.back();
		ys.pop_back();
		if(f[p.second]) ++yright;
		f[p.second] = 1;
	}
	double min_y = 1LL<<59,max_y= -(1LL<<59);
	double min_x = 1LL<<59,max_x= -(1LL<<59);
	it = xs.begin();
	while(it != xs.end()){
		if(!f[it->second]) max_x = max(max_x,it->first),min_x = min(min_x,it->first);
		it++;
	}

	it = ys.begin();
	while(it != ys.end()){
		if(!f[it->second]) max_y = max(max_y,it->first),min_y = min(min_y,it->first);
		it++;
	}


	ll diff_x = (ll)(ceil(max_x - min_x));
	ll diff_y = (ll)(ceil(max_y - min_y));

	if(diff_x == 0) ++diff_x;
	if(diff_y == 0) ++diff_y;

	return 1LL*diff_x * diff_y;

}
int main() {
	n = read(), k = read();
	vector<pii> vx,vy;
	for (int i = 0 ; i < n ; ++i) {
		int x1,y11,x2,y2;
		x1 = read(),y11=read(),x2=read(),y2=read();
		double cx = 1.0*(x1 + x2) / 2.0 , cy = 1.0*(y2 + y11) / 2.0;
		vx.pb(pii(cx,i));
		vy.pb(pii(cy,i));
	}
	sort(all(vx));
	sort(all(vy));
	REP(i,vx) xs1.push_back(vx[i]);
	REP(i,vy) ys1.push_back(vy[i]);
	ll ans = 1e18 + 1;
	//cout << ans << "\n";
	for (int i = 0 ; i <= k; ++i) {
		for (int j = 0 ; j <= k ; ++j) {
			for (int a = 0; a <= k ; ++a) {
				int curr = i + j + a;
				int rem = k - curr;
				if(rem < 0)
					continue;

				ans = min(ans,go(i,j,a,rem));
			}
		}
	}

	printf("%lld\n",ans);
}
