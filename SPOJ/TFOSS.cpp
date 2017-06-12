#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<complex>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef vector<int> vi;
#define ln log
#define e exp
double EPS = 1e-9;
typedef pair<double, double> point;

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
vector<point> hull;
int curr = 0;
ll sqr(ll x) { return x * x ;}
ll dis(int i,int j)
{
	return sqr(hull[i].first - hull[j].first) + sqr(hull[i].second - hull[j].second);
}

ll f(int x)
{
	return dis(x,curr);
}
ll solve(int ind)
{
	int n = sz(hull);
	int lo = ind + 1,hi = n - 1;
	curr = ind;
	int ans = 0;
	while(lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if(f(mid) > f(mid + 1))
			hi = mid - 1,ans = f(mid);
		else lo = mid + 1;
	}
	return ans;

}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<point> v;


		for(int i = 0 ; i < n ; ++i)
		{
			int x,y; scanf("%d %d",&x,&y);
			v.push_back(point(x,y));
		}

		ll d = 0;
		if(n < 5)
		{
			hull = v;
			REP(i,v)
					 REP(j,v)
					 d = max(d,dis(i,j));
			printf("%lld\n",d);
			continue;

		}
		sort(v.begin(),v.end());

		hull = convexHull(v);

		ll ans = 0;
		REP(i,hull)
		{
			//cerr << hull[i].first << " " << hull[i].second << "\n";
			ans = max(ans,solve(i));
			cerr << "\n";
		}
		printf("%lld\n",ans);
	}

}


