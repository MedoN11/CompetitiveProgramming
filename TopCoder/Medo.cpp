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
typedef pair<int,ll> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
int t,n;
vector<pii> pts;
int l,w;
ll ans = 0;
void go(pii &a,pii &b)
{

	int min_x = min(a.first,b.first), max_x = max(a.first,b.first);
	int min_y = min(a.second,b.second), max_y = max(a.second,b.second);

	REP(k,pts)
	{
		pii p = pts[k];
		if(p.first == a.first && p.second == a.second)
			continue;
		if(p.first == b.first && p.second == b.second)
			continue;
		if(p.first <= max_x && p.first >= min_x)
		{
			if( p.second < max_y && p.second > min_y) return;
		}

	}
	ll curr = max_x - min_x ;
	curr *= (max_y - min_y);
	ans = max(ans,curr);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		pts.clear();
		scanf("%d %d",&l,&w);
		int k;
		ans = 0;
		while(scanf("%d",&k), k != 0)
		{
			int x,y,dx,dy;
			if(k == 1) scanf("%d %d",&x,&y),pts.pb(pii(x,y));
			else
			{
				scanf("%d %d %d %d",&x,&y,&dx,&dy);
				for(int j = 0 ; j < k ; ++j) pts.pb(pii(x + dx * j,y + dy * j));
			}
		}
		sort(all(pts));
		vector<pii> bounds;
		bounds.pb(pii(0,0));
		bounds.pb(pii(0,w));
		bounds.pb(pii(l,0));
		bounds.pb(pii(l,w));

		for(int i = 0 ; i < 4 ; ++i)
		{
			for(int j = i + 1 ; j < 4 ; ++j)
			{
				go(bounds[i],bounds[j]);
			}
			for(int k = 0 ; k < sz(pts) ; ++k) go(bounds[i],pts[k]);
		}

		for(int i = 0 ; i < sz(pts) ; ++i)
		{
//			int j = i + 1;
//			while(j < sz(pts))
//			{
//				if(pts[i].second == pts[j].second)
//				{
//					go(pts[i],pts[j]);
//					++j;
//				}
//				else
//				{
//					go(pts[i],pts[j]);
//					break;
//				}
//			}
			for(int j = i + 1 ; j < sz(pts) ; ++j) go(pts[i],pts[j]);

		}
		printf("%lld\n",ans);
	}


}

