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
#define read(f) freopen (f,"r",stdin)
#define write(f) freopen (f,"w",stdout)
typedef pair<int,int> ii;
const double EPS = 1e-9;

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
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

int ccw(point a, point b, point c)
{
	point v1(b - a), v2(c - a);

	double t = cp(v1, v2);

	if (t > +EPS)
		return +1;
	if (t < -EPS)
		return -1;
	if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return +1;
	return 0;
}



bool intersect(point p1, point p2, point p3, point p4)
{
	bool x = (p1 == p2), y = (p3==p4);
	if(x && y)  return p1 == p3;
	if(x)   return ccw(p3, p4, p1) == 0;
	if(y)   return ccw(p1, p2, p3) == 0;

	return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
			ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

int t;
int main()
{
	scanf("%d",&t);
	point p1 = point(0,0);
	while(t--)
	{
		int x1,y1,x2,y2,xm,ym;
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&xm,&ym);
		point to = point(xm,ym);
		point blk1 = point(x1,y1), blk2 = point(x2,y2);
		if(intersect(p1,to,blk1,blk2))
			puts("NO");
		else puts("YES");
	}



}
