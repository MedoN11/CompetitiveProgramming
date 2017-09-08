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
#include <complex>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef  pair<int,int> pii;
const int maxn = 100005,maxlog = 18;
int n;
// Trees + LCA
vector<int> tree[maxn];
int dp_anc[maxn][maxlog + 1];
int pr[maxn];
int lvl[maxn];
int solve(int u,int p)
{
	if(p == 0)
		return pr[u];
	int &ret = dp_anc[u][p];
	if(ret != -1)
		return ret;
	return ret = solve(solve(u,p - 1),p - 1);
}

void dfs(int u,int dep)
{
	lvl[u] = dep;
	REP(i,tree[u])
	{
		int v = tree[u][i];
		if(v == pr[u])
			continue;
		pr[v] = u;
		dfs(v,dep + 1);
	}
}
int lca(int u,int v)
{
	if(lvl[u] > lvl[v])
		swap(u,v);
	int nxt_v = v;
	for(int k = maxlog; k >= 0 ;--k)
	{
		nxt_v = solve(v,k);
		if(lvl[nxt_v] >= lvl[u])
			v = nxt_v;
	}
	if(u == v)
		return u;
	int nxt_u = u;
	for(int k = maxlog; k >= 0; --k)
	{
		nxt_u = solve(u,k),nxt_v = solve(v,k);
		if(nxt_u != nxt_v)
			u = nxt_u, v = nxt_v;
	}
	return pr[u];
}
int dis(int u,int v)
{
	return lvl[u] + lvl[v] - 2 * lvl[lca(u,v)];
}
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0 ; i < n ; ++i)
		{
			tree[i].clear();
			pr[i] = -1,lvl[i] = 0;
			for(int k = 0 ; k <= maxlog ; ++k)
				dp_anc[i][k] = -1;
		}
		int u;
		vector<pii> order;
		for(int i = 1 ; i <= n - 1 ; ++i)
		{
			scanf("%d",&u); --u;
			tree[u].pb(i);
			tree[i].pb(u);
			order.pb(pii(i,u));
		}
		pr[0] = 0;

		dfs(0,0);
		int end_point_1 = 0, end_point_2 = -1;
		int d = 0;
		REP(i,order)
		{
			if(end_point_2 == -1)
			{
				end_point_2 = order[i].first;
				d = 1;

			}
			else
			{
				int curr = order[i].first;
				int cand1 = dis(curr,end_point_1);
				int cand2 = dis(curr,end_point_2);
				if(cand1 > d)
				{
					d = cand1;
					end_point_2 = curr;
				}
				else
				{
					if(cand2 > d)
					{
						d = cand2;
						end_point_1 = curr;
					}
				}

			}
			printf("%d\n",d);
		}
	}

}

