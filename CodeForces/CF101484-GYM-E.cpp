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
using namespace std;
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
int n,m;
typedef pair<ll, ll> point;

// Get convex hull of both polygons while adding colinear points in the hull
// then check if it equals either..
bool cw(const point &a, const point &b, const point &c) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) <= 0;
}

vector<point> convexHull(vector<point> p) {
	int n = p.size();
	if (n <= 1)
		return p;
	int k = 0;
	sort(p.begin(), p.end());
	vector<point> q(n * 2);
	for (int i = 0; i < n; q[k++] = p[i++])
		for (; k >= 2 && !cw(q[k - 2], q[k - 1], p[i]); --k)
			;
	for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
		for (; k > t && !cw(q[k - 2], q[k - 1], p[i]); --k)
			;
	q.resize(k - 1 - (q[0] == q[1]));
	return q;
}

int main() {
	// read vecs
	scanf("%d %d",&n,&m);
	vector<point> p(n),q(m),hull(n + m);
	for(int i = 0 ; i < n ; ++i) {
		scanf("%lld %lld",&p[i].first,&p[i].second);
		hull[i] = p[i];
	}
	for(int i = 0 ; i < m ; ++i) {
		scanf("%lld %lld",&q[i].first,&q[i].second);
		hull[i + n] = q[i];
	}
	hull = convexHull(hull);
	sort(all(hull));
	sort(all(p)); sort(all(q));;
	if(hull == p || hull == q) cout << "YES";
	else cout << "NO";
	cout << "\n";


}
