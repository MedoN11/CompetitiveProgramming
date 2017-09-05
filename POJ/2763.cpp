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
const int maxn = 100005;
const int maxlog = 18;
int n,q,s;
vector<int> tree[maxn];
int bit[4*maxn];
int in[maxn],out[maxn];
int pr[maxn],dp[maxn][maxlog + 1],lvl[maxn];
int tim = 1;
int cost[maxn*2];
void dfs(int u,int dep)
{
	lvl[u] = dep;
	in[u] = tim++;
	REP(i,tree[u])
	{
		int v = tree[u][i];
		if(v == pr[u])
			continue;
		pr[v] = u;
		dfs(v,dep + 1);
	}
	out[u] = tim++;
}

int solve(int u,int p)
{
	if(p == 0)
		return pr[u];
	int &ret = dp[u][p];
	if(ret != -1)
		return ret;
	return ret = solve(solve(u,p - 1),p - 1);
}

void add(int ind,int delta)
{
	while(ind < 4 * maxn)
	{
		bit[ind] += delta;
		ind += ind & -ind;
	}
}
int query(int ind)
{
	int s = 0;
	while(ind > 0)
	{
		s += bit[ind];
		ind -= ind & - ind;
	}
	return s;
}
int query(int l,int r)
{
	return query(r) - query(l);
}
vector<pii> edges;

int lca(int u,int v)
{
	if(lvl[u] > lvl[v])
		swap(u,v);
	for(int k = maxlog ; k >= 0; --k)
	{
		int nxt = solve(v,k);
		if(lvl[nxt] >= lvl[u])
			v = nxt;
	}
	if(u == v)
		return u;
	int nxt_u = u,nxt_v = v;
	for(int k = maxlog; k >=0 ; --k)
	{
		nxt_u = solve(u,k),nxt_v = solve(v,k);
		if(nxt_u != nxt_v)
			u = nxt_u,v = nxt_v;
	}
	return pr[u];
}
int answer(int u,int v)
{
	int lca_ = lca(u,v);
	//return query(in[u]) + query(in[v]) - 2 * query(lca_);
  return query(in[lca_],in[u]) + query(in[lca_],in[v]);
}
void update(int u,int v,int delta)
{
	if(in[u] > in[v]) swap(u,v);
	add(in[v],delta);
	add(out[v],-delta);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d %d %d",&n,&q,&s);
	int pos = s - 1;
	for(int i = 0 ; i < n - 1 ; ++i)
	{
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		--a; --b;
		if(a > b) swap(a,b);
		tree[a].pb(b);
		tree[b].pb(a);
		edges.pb(pii(a,b));
		cost[i] = w;
	}
	pr[0] = 0;
	dfs(0,0);
	REP(i,edges)
	{
		update(edges[i].first,edges[i].second,cost[i]);
	}
	int tp;
	while(q--)
	{
		scanf("%d",&tp);
		if(tp == 0)
		{
			int to;
			scanf("%d",&to);
			--to;
			printf("%d\n",answer(pos,to));
			pos = to;
		}
		else
		{
			int i,c;
			scanf("%d %d",&i,&c);
			--i;
			int delta = c - cost[i];
			cost[i] = c;
			update(edges[i].first,edges[i].second,delta);
		}
	}


}

