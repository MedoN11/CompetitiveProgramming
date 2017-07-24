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
typedef long long ll;
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
typedef pair<int,pii> edge;
int n;
int t;
// Modifictaion of floyd's algorithm
vector<int> g[105];
int floyd[105][105];
void relax(int s,int t,int d)
{

	floyd[s][t] = floyd[t][s] = d;
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
		// i > s > t > j
		 floyd[i][j] = min(floyd[i][j],floyd[i][s] + floyd[s][t] + floyd[t][j]);
		 // i - t > s > j
		 floyd[i][j] = min(floyd[i][j],floyd[i][t] + floyd[s][t] + floyd[s][j]);

		}
	}
}
const int inf = 1 << 25;
int main()
{
	scanf("%d",&t);
	int tc = 1;
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= n ; ++j)
				floyd[i][j] = (i == j)? 0 : inf;

		vector<edge> edges;
		for(int i = 1 ; i <= n - 1; ++i)
		{
			for(int k = 1 ; k <= i ; ++k)
			{
				int j;
				scanf("%d",&j);
				int s = i + 1, t = k;
				if(s > t) swap(s,t);
				edges.push_back(edge(j,pii(s,t)));
			}
		}
		sort(all(edges));
		vector<edge> ans;
		bool bad = 0;
		REP(i,edges)
		{
			int s = edges[i].second.first, t = edges[i].second.second,d = edges[i].first;

			if(floyd[s][t] < d)
			{

				bad = 1;
				break;
			}
			if(floyd[s][t] > d)
				ans.pb(edge(d,pii(s,t))),relax(s,t,d);
		}
		printf("Case #%d:\n",tc++);
		if(bad)
			printf("Need better measurements.\n\n");
		else
		{
			vector<pair<pii,int> > sol;
			REP(i,ans)
			{
			sol.pb(make_pair(pii(ans[i].second.first,ans[i].second.second),ans[i].first));
			}
			sort(all(sol));
			printf("%d\n",sz(sol));
			REP(i,sol)
			{
				printf("%d %d %d\n",sol[i].first.first,sol[i].first.second,sol[i].second);
			}
			printf("\n");

		}
	}
}
