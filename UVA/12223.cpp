#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<set>
#include<map>
#include<list>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<memory.h>
#include<iomanip>
#include<cmath>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#define ll long long
using namespace std;
int tc, n, m, u, v, c;
const int MAXN  = 10e5;
typedef pair<int,int> ii;
int node[MAXN];
ll  DP[MAXN][2];
ll acc[MAXN];
vector<ii> graph[MAXN];


/*

 First solve the standard problem of counting the sum of all pair shortest paths in a tree
 This solution calculcates for every node the sum to all other nodes
 here we modify this idea, and print the nodes with minimum sum



 */



void solve(int u, int p)
{
	// down DP..calculate answer for subtrees
	DP[u][0] = 0, acc[u] = node[u];
	for (int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i].first;
		int x = graph[u][i].second;

		if (v == p)	continue;

		solve(v, u);

		acc[u] += acc[v];

		DP[u][0] += DP[v][0] +  2 *acc[v] * x;
	}
}
void solve2(int u, int p, ll up, ll delta)
{

	// merge with upward
	DP[u][1] = up;
	for (int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i].first;
		int x = graph[u][i].second;
		if (v == p)	continue;
		ll valto = up;
		valto += (delta + acc[u] - acc[v]) * x * 2;
		valto += (DP[u][0] - DP[v][0] - acc[v] * x * 2);
		solve2(v, u, valto, delta + acc[u] - acc[v]);
	}
}
int main()
{


	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			node[i] = 0;
			graph[i].clear();
		}

		for (int i = 1; i < n; i++)
		{
			scanf("%d %d %d", &u, &v, &c);
			--u; --v;
			graph[u].push_back(ii(v, c));
			graph[v].push_back(ii(u, c));
		}
		scanf("%d", &m);

		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);
			u--;
			node[u] = v;
		}

		solve(0, -1);

		solve2(0, -1, 0, 0);

		ll best = 1LL << 59;
		vector<int> ans;

		for (int i = 0; i < n; i++)
		{
			best = min(best, DP[i][0] + DP[i][1]);
		}
		for (int i = 0; i < n; i++)
		{
			if (DP[i][0] + DP[i][1] == best)
				ans.push_back(i);
		}

		printf("%lld\n", best);
		printf("%d",ans[0] + 1);
		for (int i = 1; i < ans.size(); i++)
			printf(" %d",ans[i] + 1);
		puts("");
	}
	return 0;
}
