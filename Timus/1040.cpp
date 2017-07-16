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
#define ll  long long
#define pb push_back
typedef pair<int,int> pii;
#define all(x)          (x).begin(),(x).end()
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int n,m;
vector<pii> g[51];
int col[2505];
bool seen[51];
int gl = 0;
void dfs(int u)
{
	if(seen[u])
		return;
	seen[u] = 1;
	REP(i,g[u])
	{
		pii p = g[u][i];
		int v = p.first,id = p.second;
		if(col[id] != -1)
			continue;
		col[id] = gl++;
		if(!seen[v])
		dfs(v);
	}
}
int main()
{

	scanf("%d %d",&n,&m);
	memset(col,-1,sizeof(col));
	for(int i = 0 ; i < m ; ++i)
	{
		int u,v; scanf("%d %d",&u,&v); --u; --v;
		g[u].pb(pii(v,i));
		g[v].pb(pii(u,i));
	}
	dfs(0);
	for(int i= 0 ; i < m ; ++i)
		if(col[i] == -1) col[i] = gl++;
	cout << "YES" << "\n";
	printf("%d",col[0] + 1);
	for(int i = 1 ; i < m ; ++i)
	{
		printf(" %d",col[i] + 1);
	}
}


