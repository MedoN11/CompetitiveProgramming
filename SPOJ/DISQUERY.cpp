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
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
using namespace std;

// LCA + DP
// modification of binary lifting using powers of 2 since max/min operations can be grouped when doing the jumps.
//
const int maxn = 100005;
int dp_anc[maxn][18];
int lvl[maxn];
vector<pii> tree[maxn];
int dp_min[maxn][18],dp_max[maxn][18];
int pr[maxn],pr_cost[maxn];
void dfs(int u,int dep)
{
	lvl[u] = dep;
	REP(i,tree[u])
	{
		int v = tree[u][i].first;
		if(pr[u] == v)
			continue;
		pr[v] = u;
		pr_cost[v] = tree[u][i].second;
		dfs(v,dep + 1);
	}
}

int solve(int u,int k)
{
	if(!k)
		return pr[u];
	int &ret = dp_anc[u][k];
	if(ret != -1)
		return ret;
	return ret = solve(solve(u,k - 1),k - 1);
}
int solve_min(int u,int k)
{
	if(!k)
	{
		if(u == 0) return 1 << 30;
		return pr_cost[u];
	}
	int &ret = dp_min[u][k];
	if(ret != -1)
		return ret;
	return ret = min(solve_min(u,k - 1),solve_min(solve(u,k - 1),k - 1));
}

int solve_max(int u,int k)
{
	if(!k)
	{
		if(u == 0) return 0;
		return pr_cost[u];
	}
	int &ret = dp_max[u][k];
	if(ret != -1)
		return ret;
	return ret = max(solve_max(u,k - 1),solve_max(solve(u,k - 1),k - 1));
}

int walk_max(int u,int v)
{
	if(lvl[u] > lvl[v])
		swap(u,v);
	int log = 17;
	int bottle = 0;
	for(int k = log ; k >= 0 ; --k)
	{
		int nxt = solve(v,k);
		if(lvl[nxt] >= lvl[u])
		{
			bottle = max(bottle,solve_max(v,k));
			v = nxt;
		}
	}
	if(u == v)
		return bottle;
	for(int k = log ; k >= 0 ; --k)
	{
		int nxt_u = solve(u,k), nxt_v = solve(v,k);
		if(nxt_u != nxt_v)
		{
			bottle = max(bottle,solve_max(u,k));
			bottle = max(bottle,solve_max(v,k));
			u = nxt_u; v = nxt_v;
		}
	}
	int l = 0, r = 0;
	if(u != 0) l = pr_cost[u];
	if(v != 0) r = pr_cost[v];

	return max(bottle,max(l,r));
}
int walk_min(int u,int v)
{
	if(lvl[u] > lvl[v])
		swap(u,v);
	int log = 17;
	int bottle = 1 << 30;
	for(int k = log ; k >= 0 ; --k)
	{
		int nxt = solve(v,k);
		if(lvl[nxt] >= lvl[u])
		{
			bottle = min(bottle,solve_min(v,k));
			v = nxt;
		}
	}
	if(u == v)
		return bottle;
	for(int k = log ; k >= 0 ; --k)
	{
		int nxt_u = solve(u,k), nxt_v = solve(v,k);
		if(nxt_u != nxt_v)
		{
			bottle = min(bottle,solve_min(u,k));
			bottle = min(bottle,solve_min(v,k));
			u = nxt_u; v = nxt_v;
		}
	}
	int l = 1 << 30, r = 1 << 30;
	if(u != 0) l = pr_cost[u];
	if(v != 0) r = pr_cost[v];

	return min(bottle,min(l,r));
}
int n;
int main()
{
	scanf("%d",&n);
	memset(dp_anc,-1,sizeof(dp_anc));
	memset(dp_min,-1,sizeof(dp_min));
	memset(dp_max,-1,sizeof(dp_max));
	for(int i = 0 ; i < n - 1 ; ++i)
	{
		int u,v,c; scanf("%d %d %d",&u,&v,&c); --u; --v;
		tree[u].pb(pii(v,c));
		tree[v].pb(pii(u,c));
	}
	pr[0] = 0;
	dfs(0,0);
	int q;
	scanf("%d",&q);
	int x,y;
	while(q--)
	{
		scanf("%d %d",&x,&y); --x; --y;
		printf("%d %d\n",walk_min(x,y),walk_max(x,y));
	}

}
