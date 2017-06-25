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
#define ll unsigned long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define pb push_back
const int maxn = 5005;
ll dp[maxn][maxn][2];
int ben[maxn],red[maxn],sz[maxn],n,b;

vector<int> tree[maxn];
void dfs(int u,int p = -1)
{
	dp[u][1][0] = ben[u];
	dp[u][1][1] = ben[u] - red[u];
	dp[u][0][0] = 0;
	//dp[u][0][1] = 0;

	sz[u] = 1;
	REP(i,tree[u])
	{
		int v = tree[u][i];
		if(v == p)
			continue;
		dfs(v,u);
		for(int a = sz[u] ; a >= 0 ; --a)
		{
			for(int b = sz[v] ; b >= 0; --b)
			{
				dp[u][a + b][1] = min(dp[u][a + b][1],dp[u][a][1] + dp[v][b][1]);
				dp[u][a + b][0] = min(dp[u][a + b][0],dp[u][a][0] + dp[v][b][0]);
				dp[u][a + b][1] = min(dp[u][a + b][1],dp[u][a][1] + dp[v][b][0]);


			}
		}

		sz[u] += sz[v];

	}
}

const ll inf = 1LL << 52;

int main()
{
	scanf("%d %d",&n,&b);
	scanf("%d %d",&ben[0],&red[0]);
	int v;
	memset(dp,0,sizeof(dp));
	for(int i = 0 ; i < n ; ++i)
		for(int k = 0 ; k <=n ; ++k)
			dp[i][k][0] = dp[i][k][1] = inf;
	for(int i = 1 ; i < n  ; ++i)
	{
		scanf("%d %d %d",&ben[i],&red[i],&v);
		--v;
		tree[i].pb(v); tree[v].pb(i);

	}

	dfs(0);
	int ans = 0;


	for(int k = 1 ; k <= n ; ++k)
		if(dp[0][k][0] <= b || dp[0][k][1] <= b)
			ans = max(ans,k);
	printf("%d\n",ans);

}
