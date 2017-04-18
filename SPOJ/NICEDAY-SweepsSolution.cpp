#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
using namespace std;
#define ll long long
typedef long double ld;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define clr(x) memset(x,0,sizeof(x));
typedef vector<int> vi;
#include <iostream>
#include <cmath>
#include <complex>
#include <cassert>
using namespace std;

typedef pair<int,pair<int,int> > event;
#define Z first
#define X second.first
#define Y second.second
#define P second
typedef pair<int,int> ii;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		set<ii> s;
		int n; scanf("%d",&n);
		vector<event> events;
		for(int i = 0 ; i < n ; ++i)
		{
			int a,b,c; scanf("%d %d %d",&a,&b,&c);
			events.push_back(event(c,make_pair(a,b)));
		}
		sort(events.begin(),events.end());
		int ans = 1;
		s.insert(events[0].P);
		for(int i = 1 ; i < sz(events) ; ++i)
		{
			pair<int,int> p = events[i].P;

			set<ii>::iterator it = s.lower_bound(p);
			if(it == s.begin() || ((--it)->second) > events[i].Y)
			{
				ans++;
				s.insert(events[i].P);
				set<ii>::iterator curr = s.upper_bound(events[i].P);
				vector<set<ii>::iterator> vecs;
				for(;curr!=s.end();curr++)
				{
					if(curr->first > events[i].X && curr->second > events[i].Y)
					{
						vecs.push_back(curr);
					}
				}
				REP(j,vecs) s.erase(vecs[j]);
			}
		}
		printf("%d\n",ans);
	}
}

