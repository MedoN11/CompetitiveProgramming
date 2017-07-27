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
#include<complex>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
using namespace std;
typedef pair<int,int> pii;


// Geometry
// Point to distance
const double PI  = acos(-1.0);
double EPS = 1e-8;
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
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

point reflect(point p, point p0, point p1) {
    point z = p-p0, w = p1-p0;
    return conj(z/w)*w + p0; // Refelect point p1 around p0p1
}





bool isCollinear(point a, point b, point c) {
	return fabs( cp(b-a, c-a) ) < EPS;
}




double distToLine( point p0, point p1, point p2 ) {
	return fabs(cp(p1-p0, p2-p0)/length(p0-p1)); // area = 0.5*b*h
}




//distance from point p2 to segment p0-p1
double distToSegment( point p0, point p1, point p2 ) {
	double d1, d2;
	point v1 = p1-p0, v2 = p2-p0;
	if( (d1 = dp(v1, v2) ) <= 0)	return length(p2-p0);
	if( (d2 = dp(v1, v1) ) <= d1)	return length(p2-p1);
	double t = d1/d2;
	return length(p2 - (p0 + v1*t) );
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<point> poly;

	double d = 1 << 30;
	int x,y;
	for(int i = 0 ; i < n ; ++i) scanf("%d %d",&x,&y),poly.pb(point(x,y));
	for(int i = 0 ; i < n ; ++i)
	{
		int left = (i - 1 + n) % n;
		int right = (i + 1) % n;
		d = min(d,distToSegment(poly[left],poly[right],poly[i]));
	}
	printf("%.12f",(d / 2.0));


}

