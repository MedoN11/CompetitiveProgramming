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
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define read(f) freopen (f,"r",stdin)
#define write(f) freopen (f,"w",stdout)

struct Circle
{
	int x,y,r;
	Circle(int x_,int y_,int r_)
	{
		x = x_, y = y_, r = r_;
	}
	ll area()
	{
		return sqr(r);
	}

	bool operator <(const Circle &c) const
	{
		// least x first
		if(r != c.r) return r < c.r;
		if(x != c.x) return x < c.x;
		return y < c.y;

	}
	ll sqr(ll x) { return 1LL*x * x; }
	ll dis(Circle c) { return 1LL*sqr(x - c.x) + sqr(y - c.y);}
	bool isInside(Circle c)
	{
		ll d = dis(c);
		return 1LL*sqr(r) > (1LL*d );
	}



};
vector<Circle> circles;
bool root[1100];
vector<int> tree[1100];
ll dp[1100][2][2];
const ll inf = 1LL << 52;
int n;

ll solve(int ind,int s1,int s2)
{
	s1 %= 2, s2 %= 2;

	ll &ret = dp[ind][s1][s2];
	if(ret != -1)
		return ret;
	ret = -inf;
	ll off1 =  s1 ? -1 : 1;
	ll off2 =  s2 ? -1 : 1;
	ll val = 1LL*circles[ind].area();

	ll opt1 = off1 * val;
	REP(j,tree[ind])
	{
		opt1 += 1LL*solve(tree[ind][j], s1 + 1,s2);
	}
	ll opt2 = off2 * val;
	REP(j,tree[ind])
	{
		opt2 += 1LL*solve(tree[ind][j], s1,s2 + 1);
	}
	return ret = max(opt1,opt2);



}
double pi = acos(-1.0);
int main()
{
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i)
	{
		int x,y,r; scanf("%d %d %d",&x,&y,&r);
		circles.push_back(Circle(x,y,r));
		root[i] = 1;
	}

	sort(circles.begin(),circles.end());
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = i + 1; j < n ; ++j)
		{
			if(circles[j].isInside(circles[i]))
			{
				//cerr << j << " has " << i << "\n";
				root[i] = 0;
				tree[j].push_back(i);
				break;
			}
		}
	}
	ll ans = 0;
	memset(dp,-1,sizeof(dp));
	for(int i = 0 ; i < n ; ++i)
	{
		if(root[i])
		{

			ans += solve(i,0,0);
		}
	}


	printf("%.12f",1.0*ans*pi);
}
