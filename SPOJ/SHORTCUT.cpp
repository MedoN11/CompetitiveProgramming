#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<set>
#include<map>
#include<list>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<memory.h>
#include<iomanip>
#include<cmath>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#define ll long long
using namespace std;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
typedef pair<int,int> ii;
typedef pair<ii,int> point;
int t;
int n;
char c[250001];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",c);

		vector<point> xevents,yevents;
		int indx = 0,indy = 0;
		vector<ii> v;
		xevents.push_back(point(ii(0,0),indx++));
		yevents.push_back(point(ii(0,0),indy++));
		int x = 0, y = 0;
		v.push_back(ii(0,0));
		for(int i = 0 ; i < n ; ++i)
		{
			if(c[i] == 'N') --x;
			if(c[i] == 'S') ++x;
			if(c[i] == 'E') ++y;
			if(c[i] == 'W') --y;
			xevents.push_back(point(ii(x,y),indx++));
			yevents.push_back(point(ii(y,x),indy++));
			v.push_back(ii(x,y));
		}
		sort(xevents.begin(),xevents.end());
		sort(yevents.begin(),yevents.end());
		int sz = sz(xevents);

		int ans = 1 << 30;
		int s = 0, e = 0;
		for(int i = 0 ; i < sz - 1 ;  ++i)
		{
			point curr = xevents[i], nxt = xevents[i + 1];
			// next so skip it
			if(abs(curr.second - nxt.second) == 1)
				continue;
			if(curr.first.first == nxt.first.first)
			{
				int dis = abs(curr.first.second - nxt.first.second);
				int from = min(curr.second,nxt.second) , to = max(curr.second,nxt.second);
				if(dis == ans)
				{
					if(from < s)
					{
						s = from, e = to;
					}
					else
					{
						if(s == from)
						{
							if(to > e)
								s = from, e = to;
						}
					}
				}
				else
				{
					if(dis < ans) ans = dis, s = from, e = to;
				}
			}
		}

		for(int i = 0 ; i < sz - 1 ;  ++i)
		{
			point curr = yevents[i], nxt = yevents[i + 1];
			// next so skip it
			if(abs(curr.second - nxt.second) == 1)
				continue;
			if(curr.first.first == nxt.first.first)
			{
				int dis = abs(curr.first.second - nxt.first.second);
				int from = min(curr.second,nxt.second) , to = max(curr.second,nxt.second);
				if(dis == ans)
				{
					if(from < s)
					{
						s = from, e = to;
					}
					else
					{
						if(s == from)
						{
							if(to > e)
								s = from, e = to;
						}
					}
				}
				else
				{
					if(dis < ans) ans = dis, s = from, e = to;
				}
			}
		}
		cout << ans << " " << s << " " << e << " ";
		if(v[s].first != v[e].first)
		{
			if(v[s].first  < v[e].first)
				cout << "S";
			else cout << "N";
		}
		if(v[s].second != v[e].second)
		{
			if(v[s].second  < v[e].second)
				cout << "E";
			else cout << "W";
		}


	}
}
