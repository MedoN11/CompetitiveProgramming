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
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
int t,h,w;
#define F first
#define S second
vector<pii> pts;

// Any rectangle is bounded by 4 points or borders
// Bruteforce two points, and min/max for y
int solve()
{
	int tmp = 0;
	REP(i,pts)
	{
		pii curr = pts[i];
		int top = h,bot = 0;
		for(int j = i + 1 ; j < sz(pts) ; ++j)
		{
			pii nxt = pts[j];
			//cerr << top - bot << "\n";
			tmp = max(tmp,(nxt.first - curr.first) * (top - bot));
			if(nxt.first == curr.first)
				continue;
			if(nxt.second >= curr.second)
			{
				top = min(top,nxt.second);
			}
			else bot = max(bot,nxt.second);
			tmp = max(tmp,nxt.first - curr.first * (top - bot));

		}
		//tmp = max(tmp,(w - curr.first) * (top - bot));
	}
	return tmp;
}
void inv()
{
	REP(i,pts) swap(pts[i].first,pts[i].second);
	swap(h,w);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&w,&h);
		int tp;
		pts.clear();
		int dx,dy,x,y;
		while(scanf("%d",&tp) && tp)
		{
			if(tp == 1)
			{
				scanf("%d %d",&x,&y);
				pts.pb(pii(x,y));
			}
			else
			{
				scanf("%d %d %d %d",&x,&y,&dx,&dy);
				for(int j = 0 ; j < tp ; ++j)
				{
					pts.pb(pii(x,y));
					x += dx, y += dy;
				}
			}
		}
		pts.pb(pii(0,0)); pts.pb(pii(w,h)); pts.pb(pii(w,0)); pts.pb(pii(0,h));
		sort(all(pts));
		int a = solve();
		inv();
		sort(all(pts));
		a = max(a,solve());
		cout << a << "\n";
	}
}
