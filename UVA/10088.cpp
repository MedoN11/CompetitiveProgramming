#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <unordered_map>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define ll  long long
using namespace std;
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

ll gcd(int a,int b)
{

	if(b == 0)
		return a;
	return gcd(b,a % b);

}
int main()
{

	int n;
	vector<point> points;
	cerr << __gcd(1,2);

	while(scanf("%d",&n),n)
	{
		points.clear();
		for(int i = 0 ; i < n ; ++i)
		{
			int x,y; scanf("%d %d",&x,&y);
			points.push_back(point(x,y));
		}
		ll b = 0;

		REP(j,points)
		{
			point v = vec(points[j],points[(j + 1) % n]);

			b += gcd((int)abs(v.X),(int)abs(v.Y)) ;
		}

		--b;
		long double a = 0;
		REP(i, points)  a += cp(points[i], points[ (i+1) % sz(points) ]);
		ll A = fabs(a/2.0);
		ll I = (2*A - b + 2)/ 2;
		cout << I << "\n";
	}
	return 0;
}

