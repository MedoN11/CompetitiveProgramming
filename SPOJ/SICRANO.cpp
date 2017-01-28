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
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define ll  long long
#define EPS (1e-8);
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define neg(x) memset(x,-1,sizeof(x));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define endl "\n"
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;
#define MAXN 1000001
#define x first
#define y second
typedef pair<int,int> point;
typedef pair<point,point> segment;
int tc;
int pts,segs;
vector<segment> v;
vector<point> p;
int ans[60];

bool equal(double a, double b)
{
	return fabs(a - b) <= EPS;
}
double sqr(double x)
{
	return x * x;
}
double dis(point &p1,point &p2)
{
	return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}
bool onSegement(point &a,point &b,point &c)
{
	return equal(dis(a,b),dis(a,c) + dis(c,b));
}
int main()
{
	scanf("%d",&tc);
	while(tc--)
	{
		v.clear();
		p.clear();
		memset(ans,0,sizeof(ans));
		scanf("%d %d",&pts,&segs);
		int x,y,x2,y2;
		for(int j = 0 ; j < pts ; ++j)
		{
			scanf("%d %d",&x,&y);
			p.push_back(point(x,y));
		}
		for(int j = 0 ; j < segs; ++j)
		{
			scanf("%d %d %d %d",&x,&y,&x2,&y2);
			v.push_back(segment(point(x,y),point(x2,y2)));
		}
		REP(i,v)
		{
			REP(j,p)
			{
				if(onSegement(v[i].first,v[i].second,p[j]))
					ans[i]++;
			}
		}
		for(int i = 0 ; i < segs ; ++i)
			printf("%d\n",ans[i]);
	}
}

