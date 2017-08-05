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
#include<complex>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
using namespace std;
#define ll  long long
typedef pair<int,int> pii;
#define pb push_back
int n;

typedef complex<double> point;
const double PI  = acos(-1.0);

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
const int EPS = 1e-9;
bool circle2PtsRad(point p1, point p2, double r, point &c) {
	double d2 = (p1.X - p2.X) * (p1.X - p2.X) +
			(p1.Y - p2.Y) * (p1.Y - p2.Y); double det = r * r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	double tX = (p1.X + p2.X) * 0.5 + (p1.Y - p2.Y) * h;
	double tY = (p1.Y + p2.Y) * 0.5 + (p2.X - p1.X) * h;
	c = point(tX,tY);
	return true; }
double sqr(double x) {return x * x; }
bool inside(point a,double R, point c)
{
	if(sqr(a.X - c.X) + sqr(a.Y- c.Y) + EPS <= R*R )
		return 1;
	return 0;
}
int main()
{
	while(cin >> n)
	{
		if(!n)
			break;
		int x,y;
		vector<point> pts;
		for(int i = 0 ; i < n ;  ++i)
		{
			cin >> x >> y;
			pts.pb(point(x,y));

		}
		double R = 0.0;
		cin >> R;
		bool found = 0;
		for(int i = 0  ; i < n && !found ; ++i)
		{
			for(int j = 0 ; j < n && !found ; ++j)
			{
				if(i == j)
					continue;
				point c;
				if(circle2PtsRad(pts[i],pts[j],R,c))
				{
					bool ok = 1;
					for(int k = 0 ; k < n && ok ; ++k)
					{
						if(!inside(pts[k],R,c))
							ok = 0;
					}
					found |= ok;
				}
			}
		}
		if(found)
			puts("The polygon can be packed in the circle.");
		else puts("There is no way of packing that polygon.");

	}

}
