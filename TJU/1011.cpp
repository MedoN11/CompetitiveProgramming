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
#include <complex>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
const double PI = acos(-1.0);
const double EPS = 1e-8;

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
#define all(v)      ((v).begin()), ((v).end())
#define sz(v)     ((int)((v).size()))
#define clr(v, d)   memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)

// Geometry Pick's theorm
// On integral points between 2 points
// let the slope between them be a / b = ( (y2 - y1) / (x2 - x1))
// by definition of slope for every a in X, we must move b in Y
// a and b must be integers in this case because we are dealing with lattice points
// simplify the fraction a / b by getting gcd
// this b is the minimum change we can do in Y while maintaining an integer change in X
// the frequency we can move is b / gcd(a,b)
// now how many points can we cover ? (b) / (b/gcd(a,b)) = gcd(a,b)
// same can be derived from X

int getCount(point p, point q)
{

	if (p.X==q.X)
		return abs(p.Y - q.Y) - 1;


	if (p.Y == q.Y)
		return fabs(p.X-q.X) - 1;

	int g = __gcd((int)abs(p.X-q.X), (int)abs(p.Y-q.Y));
	return  -1+(abs(p.Y - q.Y)) / (abs(p.Y-q.Y) / g); // or just return gcd..but it's an illustration for formula above
}

double polygonArea(vector<point>& points) {
	long double a = 0;
	rep(i, points)  a += cp(points[i], points[ (i+1) % sz(points) ]);
	return fabs(a/2.0);
}
typedef pair<int,int> pii;
set<pii> s;
int main()
{
	int t;
	scanf("%d",&t);
	int tc = 1;
	int n;

	while(t--)
	{   int x = 1;
		printf("Scenario #%d:\n",tc++);
		int currX = 0, currY = 0;
		vector<point> poly;

		scanf("%d",&n);
		for(int i = 0 ; i < n ; ++i)
		{
			int dx,dy; scanf("%d %d",&dx,&dy);
			currX += dx, currY += dy;
			poly.pb(point(currX,currY));

		}
		//REP(i,poly) cerr << poly[i].X << " " << poly[i].Y << "\n";
		for(int i = 0 ; i < sz(poly) - 1; ++i)
		{
			int y = getCount(poly[i],poly[i + 1]);
			x += y + 1;

		}
		x += getCount(poly[0],poly[sz(poly) - 1]);

		double area = polygonArea(poly);
		int in = 2*area - (x) + 2; in /= 2;
		printf("%d %d %.1f\n",in,x,area);
		printf("\n");

	}

}
