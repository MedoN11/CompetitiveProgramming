#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<numeric>
#include<utility>
#include<memory.h>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
using namespace std;
#define ll long long
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
typedef pair<ll,ll> ii;
vector<ii> tree[100001];
ll dp[100001];
ll dp2[100001];
int n;
int k;
ll best = 0;
void  dfs(int u,int p = -1)
{
	int ch = tree[u].size();
	vector<ii> v;
	dp[u] = dp2[u] = 0;
	for(int i = 0 ; i < ch ; ++i)
	{
		int nxt = tree[u][i].first;
		if(nxt == p)
			continue;
		dfs(nxt,u);
		v.push_back(ii(tree[u][i].second + dp[nxt],nxt));
	}



	set<int> taken;
	sort(v.rbegin(),v.rend());
	for(int j = 0 ; j < min((int)v.size(),k - 1) ; ++j)
		dp[u] += v[j].first,taken.insert(v[j].second);
	ll more = 0;
	if(v.size() >= k)
	{
		more += v[k - 1].first;
	}
	dp2[u] = dp[u];
	for(int i = 0 ; i < ch ; ++i)
	{
		int nxt = tree[u][i].first;
		if(nxt == p)
			continue;
		if(taken.find(nxt) != taken.end())
		{

			dp2[u] = max(dp2[u],1LL*dp[u] - dp[nxt] + dp2[nxt] + more);
		}
		else dp2[u] = max(dp2[u],1LL*dp[u] + dp2[nxt] + tree[u][i].second);
	}

}
int main()
{
	fast
	cin >> n >> k;

	for(int i = 0 ; i < n - 1 ; ++i)
	{
		int u,v,c;
		cin >> u >> v >> c;
		tree[u].push_back(ii(v,c)); tree[v].push_back(ii(u,c));
	}
	dfs(0);
	cout << dp2[0] << "\n";

}
