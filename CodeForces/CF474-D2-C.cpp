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
#include<algorithm>
#include <cassert>
#include <stack>
#include<cstring>
#include <cmath>
#include <complex>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <cstdio>
#include<map>
using namespace std;
#define ll  long long
#define MAXN 110005
#define fast std::ios_base::sync_with_stdio(false);
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
const double PI  = acos(-1.0);
double EPS = 10e-8;
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p0,p1)             (dp(vec(p0,p1),vec(p0,p1)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define polar(r,ang)            ((r)*exp(point(0,ang)))
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  	(rotateO(vec(about,p),ang)+about)
vector<point> p;
vector<point> about;
int dcmp(double a, double b) {	return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1;	}

struct Double {
	double d;
	Double() {d = 0.0; };
	Double(double d): d(d) {}
	bool operator < (const Double& D) const {
		return dcmp(d, D.d) < 0;
	}
	bool operator > (const Double& D) const {
		return dcmp(d, D.d) > 0;
	}
	bool operator == (const Double& D) const {
		return dcmp(d, D.d) == 0;
	}
};


bool isSquare(vector<point> &checks)
{
	map<Double, vector<pair<int, int> > > mp;

	for (int i = 0; i < sz(checks); ++i)
	{
		for (int j = i + 1; j < sz(checks); ++j)
		{
			Double len(length(checks[i]-checks[j]));

			mp[len].push_back(make_pair(i,j));
		}
	}
	if(mp.size() != 2)
		return false;

	map<Double, vector<pair<int, int> > >::iterator side = mp.begin();

	map<Double, vector<pair<int, int> > >::iterator diag = mp.begin();

	++diag;

	if(side->second.size() != 4 || diag->second.size() != 2)
		return false;

	set<int> s;
	s.insert(diag->second[0].first);
	s.insert(diag->second[0].second);
	s.insert(diag->second[1].first);
	s.insert(diag->second[1].second);

	return s.size() == 4;

}
int main()
{

	int n; cin >> n;
	p.resize(4); about.resize(4);

	int a,b,c,d;
	for(int t = 0 ; t <  n ; ++t)
	{
		for(int i = 0 ; i < 4 ; ++i)
		{

			scanf("%d %d %d %d",&a,&b,&c,&d);
			p[i] = point(a,b);
			about[i] = point(c,d);
		}

		int ans = 1 << 30;
		for(int i = 0 ; i < 4;  ++i)
		{
			point a = rotateA(p[0],i * PI / 2.0,about[0]);
			for(int j = 0 ; j < 4 ; ++j)
			{
				point b = rotateA(p[1],j * PI / 2.0,about[1]);

				for(int k = 0 ; k < 4 ; ++k)
				{
					point c = rotateA(p[2],k * PI / 2.0,about[2]);

					for(int z = 0  ; z < 4 ; ++z)
					{
						point d = rotateA(p[3],z * PI / 2.0,about[3]);
						vector<point> checks;
						checks.push_back(a);
						checks.push_back(b);
						checks.push_back(c);
						checks.push_back(d);
						if(isSquare(checks))
						{

							ans = min(ans,i + j + k + z);
						}

					}
				}
			}
		}
		if(ans == 1 << 30)
			ans = -1;
		printf("%d",ans);
		puts("");
	}
}
