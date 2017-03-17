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
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include <set>
#include <iostream>
#include <cstdio>
#include<map>
#define ll  long long
#define sz(v) (int)(v.size())
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
using namespace std;
#define MAXN 10001
int n,m;
int t;
vector<int> g[MAXN];
vector<int> rev[MAXN];
int col[MAXN];
int low[MAXN];
stack<int> topo;
int tim = 0;
void dfsRev(int u)
{
	if(col[u])
		return;
	col[u] = 1;
	REP(j,rev[u])
	{
		dfsRev(rev[u][j]);
	}
	topo.push(u);
}
bool OK = 1;
void dfs(int u)
{
	if(col[u])
		return;
	col[u] = 1;
	REP(j,g[u])
	dfs(g[u][j]);
}
int oo = 1 << 30;

void dfs3(int u,int e)
{
	if(!OK)
		return;
	if(col[u])
		return;
	col[u] = 1;

	bool back = 0;

	REP(j,g[u])
	{
		int nxt = g[u][j];
		if(col[nxt] == 1)
		{
			// back edge
			if(e < low[nxt])
			{
				OK = 0;
			}
			back = 1;
		}
	}
	if(back)
		e = low[u];
	col[u] = 2;
	REP(j,g[u])
	{
		dfs3(g[u][j],e);
	}

}
bool cf = 0;
void dfs2(int u)
{


	if(col[u] == 2)
	{
		OK = 0;
		return;
	}
	if(col[u] == 1)
	{
		return;
	}
	col[u] = 1;
	low[u] = tim++;
	REP(k,g[u])
	{
		dfs2(g[u][k]);
	}
	col[u] = 2;
}


int main()
{
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&m);
		int u,v;
		for(int i = 0 ; i < n ; ++i)
		{
			g[i].clear();
			rev[i].clear();
		}
		for(int j = 0 ; j < m ; ++j)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			rev[v].push_back(u);
		}
		memset(col,0,sizeof(col));
		for(int i = 0 ; i < n ; ++i)
			dfsRev(i);
		memset(col,0,sizeof(col));
		int scc = 0;
		while(!topo.empty())
		{
			int u = topo.top(); topo.pop();
			if(!col[u])
			{
				++scc;
				dfs(u);
			}
		}
		if(scc > 1)
		{
			puts("NO");
			continue;
		}
		memset(col,0,sizeof(col));
		OK = 1;
		memset(low,0,sizeof(low));
		dfs2(0);

		tim = 0;
		memset(col,0,sizeof(col));
		if(!OK)
		{
			puts("NO");
			continue;
		}
		memset(col,0,sizeof(col));
		dfs3(0,1 << 29);
		if(!OK)
		{
			puts("NO");
			continue;
		}
		puts("YES");



	}

}
