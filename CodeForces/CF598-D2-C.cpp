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
typedef pair<ll,ll> pii;
#define F second.first
#define S second.second
#define MP make_pair
const int maxn = 200005;
typedef pair<pair<double,double>,pair<double,int> > pt;
#define x first.first
#define y first.second

// Polar sort then take the two nearest vectors
vector<pt> v;
bool half(pt p) { // true if in blue half
	assert(p.x != 0 || p.y != 0); // the argument of (0,0) is undefined
	return p.y > 0 || (p.y == 0 && p.x < 0);
}
long double cross(pt v,pt w) {
	return v.x*w.y - w.x*v.y;
}
void polarSort(vector<pt> &v) {
	sort(v.begin(), v.end(), [](pt v, pt w) {
		return make_tuple(half(v), 0) <
				make_tuple(half(w), cross(v,w));
	});
}
int main() {
	int n;
	cin >> n;
	long double pi = acos(-1.0);
	for (int i = 0 ; i < n ; ++i) {
		long double xx,yy;
		cin >> xx >> yy;
		long double res = atan2(yy,xx);
		res *= 180.0/pi;
		if(res < 0) res +=360;
		v.pb(pt(make_pair(xx,yy),make_pair(res,i + 1)));
	}
	polarSort(v);


	long  double res = 1<<30;
	int a = 1,b = n;

	for (int i = 0 ; i < n ; ++i) {
		long double nxt = (v[(i + 1)%n].F - v[i].F);
		if(nxt < 0) nxt += 360.0;
		if(res > nxt) {
			res = nxt;
			a = v[i].S,b = v[(i+1)%n].S;
		}
	}
	//cout << res << "\n";
	cout << a << " " << b << "\n";
}
