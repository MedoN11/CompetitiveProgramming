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
#include<complex>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
using namespace std;
typedef pair<int,int> pii;
const int maxn = 100005;
vector<pii> tree[maxn];
int P[maxn][30];
int pr[maxn];
int L[maxn];
bool seen[maxn];
int dp[maxn];
int n;
int ans[maxn];
int deg[maxn];

// LCA + DP using a queue on a tree
inline int solve(int i,int j)
{

	if(j == 0) return pr[i];
	int &ret = P[i][j];
	if(ret != -1) return ret;
	return ret = solve(solve(i,j - 1), j - 1);

}

void dfs(int idx,int lvl)
{
	L[idx] = lvl;
	REP(k,tree[idx])
	{
		int next = tree[idx][k].first;
		if(next == pr[idx]) continue;
		deg[idx]++;
		pr[next] = idx;
		dfs(next,lvl + 1);

	}
}

int LCA(int x,int y)
{
	if(L[x] < L[y])
	{
		swap(x,y);
	}
	int log = 18;
	for(int k = log ; k >= 0 ; k--)
	{
		int next = solve(x,k);
		if(L[next] >= L[y]) x = next;
	}

	if(x == y) return x;

	for(int k = log ; k >= 0 ;k--)
	{
		int nextX = solve(x,k);
		int nextY = solve(y,k);
		if(nextX != nextY)
		{
			x = nextX;
			y = nextY;
		}
	}

	return pr[x];


}

int main()
{
	scanf("%d",&n);
	for(int i = 0  ; i < n - 1 ; ++i)
	{
		int u,v; scanf("%d %d",&u,&v); --u; --v;
		tree[u].pb(pii(v,i)); tree[v].pb(pii(u,i));


	}
	memset(pr,-1,sizeof(pr));
	memset(P,-1,sizeof(P));
	pr[0] = 0;
	dfs(0,0);
	int k;
	scanf("%d",&k);
	int x,y;
	while(k--)
	{
		scanf("%d %d",&x,&y); --x; --y;
		int lca = LCA(x,y);
		dp[x]++, dp[y]++;
		dp[lca]--; dp[lca]--;
	}
	queue<int> q;
	for(int i = 0 ; i < n ; ++i)
	{
		if(deg[i] == 0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		REP(i,tree[u])
		{
			int nxt = tree[u][i].first; int id = tree[u][i].second;
			if(deg[nxt] == 0)
				continue;
			ans[id] += dp[u];
			dp[nxt] += dp[u];
			deg[nxt]--;
			if(deg[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}
	for(int i = 0 ; i < n - 1 ; ++i) printf("%d ",ans[i]);


}
