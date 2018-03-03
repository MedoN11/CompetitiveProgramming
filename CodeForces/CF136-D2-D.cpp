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
#include <unordered_set>
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
typedef pair<ll,ll> pii;
#define F first
#define S second
#define MP make_pair
// Geometry
//backtracking/msk then check if 4 points form a square and rectangle
struct pt {
	ll x,y;
	pt() {}
    pt(ll a,ll b){
		x = a, y = b;
	}
	ll sqr(ll x) {
		return x * x;
	}
	ll dis(pt &p) {
		return sqr(x-p.x) + sqr(y-p.y);
	}
};
bool square(pt p1,pt p2,pt p3,pt p4) {
	ll d2 = p1.dis(p2);
	ll d3 = p1.dis(p3);
	ll d4 = p1.dis(p4);
	if(d2 == d3 && d4 == d2*2) {
		ll dis = p4.dis(p2);
		return dis == d2 && p3.dis(p4) == d2;
	}
	if(d3 == d4 && d2 == d3*2) {
		ll dis = p3.dis(p2);
		return dis == d3 && p2.dis(p4) == d3;
	}
	if(d4 == d2 && d3 == d2 * 2){
		ll dis = p3.dis(p2);
		return dis == d2 && p3.dis(p4) == d2;
	}
	return 0;
}
bool IsOrthogonal(pt a, pt b, pt c)
{
	return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
}

int IsRectangle(pt a, pt b, pt c, pt d)
{
	return
			IsOrthogonal(a, b, c) &&
			IsOrthogonal(b, c, d) &&
			IsOrthogonal(c, d, a);
}


int rect(pt a, pt b, pt c, pt d)
{
	return IsRectangle(a, b, c, d) ||
			IsRectangle(b, c, a, d) ||
			IsRectangle(c, a, b, d);
}
int main() {
	vector<pt> pts;
	for (int i = 0 ; i < 8 ; ++i) {
		int x,y;
		scanf("%d %d",&x,&y);
		pts.pb(pt(x,y));
	}
	for (int msk = 0 ; msk < (1 << 8) ; ++msk) {
		if(__builtin_popcount(msk) != 4) continue;
		vector<pt> sq,rec;
		vector<int> a,b;
		for (int j = 0 ; j < 8 ; ++j) {
			if(msk & (1 << j)) sq.pb(pts[j]),a.pb(j+1);
			else rec.pb(pts[j]),b.pb(j + 1);
		}
		if(square(sq[0],sq[1],sq[2],sq[3]) && rect(rec[0],rec[1],rec[2],rec[3])) {
			cout << "YES\n";
			REP(k,a) cout << a[k] << " ";
			cout << endl;
			REP(k,b) cout << b[k] <<" ";
			cout << endl;;
			return 0;
		}
	}
	cout << "NO\n";
}
