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
typedef pair<long double,long double> pii;
typedef pair< long double,long double> pdd;
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
#define for1LL(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define fornLL(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define ld long double
vector<pdd> poly;
ld pre[500001];
int n,q;

int main() {
	//fo("res.out");
	int tc = 0;
	while (cin >> n >> q) {
		if (n + q == 0)break;
		if(tc) cout << "\n";
		tc = 1;
		poly.clear();
		forn(i,n) {
			ld x,y; cin >> x >> y;
			poly.pb(pdd(x,y));
		}
		poly.pb(pii(poly[0].F,poly[0].S));
		ld s = 0;
		forn(i,n) {
			pre[i] = s;
			s += (long double)((poly[i].F - poly[i + 1].F) * (poly[i].S + poly[i + 1].S));
		}
		long double area = abs(s);
		while (q--) {
			int a,b;
			cin >> a >> b;

			long double cur = pre[b] - pre[a] + (poly[b].F - poly[a].F) * (poly[a].S + poly[b].S);
			//cur += (poly[b].F - poly[a].F) * (poly[b].S + poly[a].S);
			cur = abs(cur);
			long double ans = min(cur, area - cur)/2.0;
		//	cout << ans << "\n";
			cout << fixed;
			cout <<setprecision(1);
			cout << ans << "\n";

		}
	}
}
//4 2
//0 0
//0 1
//1 2
//1 0
//1 3
//0 2
//0 0

//12 3
//-610 1301
//28 1405
//275 1385
//1614 21
//1564 -347
//1106 -1024
//-681 -1274
//-901 -1166
//-935 -1146
//-1064 -1057
//-1288 -848
//-1465 -591
//3 7
//0 9
//6 9
