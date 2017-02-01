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
int n,m;

struct circle
{
	int x,y,r;

	circle(int x_,int y_,int r_)
	{
		this->x = x_;
		this->y = y_;
		this->r = r_;
	}

	ll sqr(ll t)
	{
		return t*t;
	}
	long long dist(int a,int b)
	{
		return sqr(a - x) + sqr(y - b);
	}
	bool insideCircle(int a,int b)
	{
		return dist(a,b) <= r * r;
	}
};
vector<circle> circles;
int main()
{
	fast
	int tc = 1;
	int t;
	cin >> t;
	while(t--)
	{
		circles.clear();
		cin >> n >> m;
		int x,y,r;
		for(int i = 0 ; i < n ; ++i)
		{
			cin >> x >> y >> r;
			circles.push_back(circle(x,y,r));
		}
		cout << "Case " << tc++ <<":" << endl;
		for(int j = 0 ; j < m ; ++j)
		{
			bool ok = 0;
			cin >> x >> y;
			REP(j,circles)
			if(circles[j].insideCircle(x,y))
				ok = 1;

			if(ok)
				cout << "Yes" << endl;
			else cout << "No" << endl;
		}

	}


}

