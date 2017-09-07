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
const bool debug = true;
const int maxn = 100005;
typedef pair<double, double> point;

// Geometry
// Convex hull + bitmasks
// bruteforce size of set to cut then compute convex hull of remaining pts, and see if you can cut it satisfying total costs. Take one with least cost
bool cw(const point &a, const point &b, const point &c) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
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

vector<point> pts;
int pay[maxn];
int gain[maxn];
int n;
double sqr(double x) { return x * x; }
double getPer(vector<point> v)
{
	double p = 0.0;
	REP(i,v)
	{
		int j = (i + 1) % sz(v);
		p += 1.0*sqrt(sqr(v[i].first - v[j].first) + sqr(v[i].second - v[j].second));
	}
	return p;
}
vector<int> cut;
double extra = 0.0;
int main()
{
	ios
	int x,y,v,l;
	cout << fixed;
	cout << setprecision(2);
	int tc = 1;
	bool f = 0;
	while(cin >> n && n)
	{
		if(f)
			cout << "\n";
		pts.clear();
		cut.clear();
		f = 1;
		extra = 0.0;
		for(int i = 0 ; i < n ; ++i)
		{
			cin >> x >> y >> v >> l;
			pts.pb(point(x,y));
			gain[i] = l;
			pay[i] = v;
		}
		double best = 1 << 30;
		for(int msk = 0 ; msk < (1 << n) ; ++msk)
		{
			int cost = 0, has = 0;
			vector<point> tmp;
			REP(j,pts)
			{
				if(msk & (1 << j)) tmp.pb(pts[j]);
				else  cost += pay[j],has +=  gain[j];
			}
			vector<point> hull = convexHull(tmp);
			if(cost == 0)
				cerr << has << "\n";
			double per = getPer(hull);

			if(per <= has)
			{
				vector<int> tmpo;
				REP(j,pts) if(!(msk & (1 << j))) tmpo.pb(j + 1);

				if(cost < best || (cost == best && sz(tmpo) < sz(cut)))
				{
					//					if(debug)
					//						cerr << "hena " << cost << "\n";
					best = cost;
					cut = tmpo;
					extra = has - per;
				}
			}

		}
		cout << "Forest " << (tc++) << "\n";
		cout << "Cut these trees: ";
		if(sz(cut) > 0)
		{
			cout << cut[0];
			for(int i = 1 ; i < sz(cut) ; ++i)
				cout <<" "<< cut[i];
		}
		cout << "\n";
		cout << "Extra wood: " << (extra) << "\n";

	}
}

