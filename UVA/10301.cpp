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
#define write(file) freopen (file,"w",stdout)
#define ll  long long
using namespace std;
int arr[2*100000+5];
int n;
double EPS = 1E-8;
const double PI  = acos(-1.0);

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
typedef vector<int> vi;
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

class DSU {
private:
	vi p, rank, setSize;
	int numSets;
public:
	DSU(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) { numSets--;
		int x = findSet(i), y = findSet(j);

		if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
		else                   { p[x] = y; setSize[y] += setSize[x];
		if (rank[x] == rank[y]) rank[y]++; } } }
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

struct Circle
{
	point c;
	double r;
	Circle(point cen,double rd)
	{
		this->c = cen;
		this->r = rd;
	}
};
point reflect(point p, point p0, point p1) {
	point z = p-p0, w = p1-p0;
	return conj(z/w)*w + p0; // Refelect point p1 around p0p1
}

int dcmp(double a,double b)
{
	return fabs(a - b) <= EPS ? 0 : a < b ? - 1 :1;
}
double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}

// return min angle: aOb / bOa
// dp(v1, v2) = |v1|*|v2|*cos(theta)
double angleO(point a, point O, point b) {
	point v1(a - O), v2(b - O);
	return acos( fixAngle ( dp(v1, v2) / length(v1) / length(v2) ) );
}


double getAngle_A_abc(double a, double b, double c)
{
	return acos(fixAngle( (b*b+c*c-a*a) / (2*b*c)));
}
double getAng(point &a, point &b, point &c) // find angle abc, anticlock bc to ba
{
	double ang = angle( vec(b, c)) - angle( vec(b, a));
	if(dcmp(ang, 0) < 0)
		ang+=2*PI;
	return ang;
}


vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2)
				{
	// Handle infinity case first: same center/radius and r > 0
	if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
		return vector<point>(3, c1);    // infinity 2 same circles (not points)

	// Compute 2 intersection case and handle 0, 1, 2 cases
	double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

	if(::isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
		ang2 = 0; // fix corruption

	vector<point> v(1, polar(r1, ang1 + ang2) + c1);

	// if point NOT on the 2 circles = no intersection
	if(dcmp(dp(v[0]-c1, v[0]-c1), r1*r1) != 0 ||
			dcmp(dp(v[0]-c2, v[0]-c2), r2*r2) != 0 )
		return vector<point>();

	v.push_back(polar(r1, ang1 - ang2) + c1);
	if(same(v[0], v[1]))  // if same, then 1 intersection only
		v.pop_back();
	return v;
				}
vector<Circle> v;
int main()
{
	fast
	while(cin >> n, n != -1)
	{
		v.clear();
		double x,y,r;
		for(int i = 0 ; i < n ; ++i)
		{
			cin >> x >> y >> r;
			v.push_back(Circle(point(x,y),r));
		}
		DSU dsu(n);
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = i + 1 ; j < n ; ++j)
			{
				vector<point> ans = intersectCircleCircle(v[i].c,v[i].r,v[j].c,v[j].r);
				if((ans).size() > 1)
					dsu.unionSet(i,j);
			}
		}
		int mx = 0;
		for(int i = 0 ; i < n ; ++i)
			mx = max(mx,dsu.sizeOfSet(i));
		cout << "The largest component contains ";
		if(mx == 1)
			cout << "1 ring." << endl;
		else cout << mx <<" rings." << endl;
	}

}

