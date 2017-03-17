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
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define write(file) freopen (file,"w",stdout)
#define ll  long long
using namespace std;
typedef pair<int,int> ii;
#define MAXN 2000
vector<pair<int,int> > G[MAXN];
vector<int> path;
bool taken[MAXN];
int u,v,z;
int org;
void dfs(int u)
{
	for(int i = 0 ; i < G[u].size() ; ++i)
	{
		if(taken[G[u][i].first])
			continue;
		taken[G[u][i].first] = 1;
		dfs(G[u][i].second);
		path.push_back(G[u][i].first);
	}
}
int main()
{
	while(1)
	{
		for(int i = 0 ; i < MAXN ; ++i)
			G[i].clear();
		bool f = 0;
		vector<int> edges;
		while(scanf("%d %d",&u,&v) == 2 && u && v)
		{
			scanf("%d",&z);
			G[u].push_back(make_pair(z,v));
			G[v].push_back(make_pair(z,u));
			if(!f)
				org = min(u,v);
			edges.push_back(z);
			f = 1;

		}
		if(!f)
			break;
		int euler = 1;
		for(int i = 1; i <= 2000 ; ++i)
		{
			sort(G[i].begin(),G[i].end());
			euler &= !(G[i].size() & 1);
		}
		if(!euler)
		{
			puts("Round trip does not exist.\n");
			continue;
		}

		memset(taken,0,sizeof(taken));
		path.clear();
		dfs(org);
		bool bad = 0;
		for(int i = 0 ; i < edges.size() ; ++i)
			if(!taken[edges[i]])
				bad = 1;
		if(bad)
		{
			puts("Round trip does not exist.\n");
			continue;
		}
		reverse(path.begin(),path.end());
		printf("%d",path[0]);
		for(int i = 1 ; i < path.size() ; ++i)
			printf(" %d",path[i]);
		puts("");
		puts("");
	}
}

