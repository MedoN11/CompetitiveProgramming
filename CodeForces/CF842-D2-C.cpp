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
const int maxn = 2*100005;
const int maxlog = 18;
int t,n,e;
vector<int> tree[maxn];
typedef pair<pii,int> state;
map<state,bool> mp;
bool seen[maxn][2];
int dp[maxn];
int val[maxn];
int gcd(int a,int b)
{
	if(a == 0 || b == 0)
		return a + b;
	return __gcd(a,b);
}
void solve(int u,int f,int g,int pr = -1)
{
	if(mp.find(make_pair(pii(u,f),g)) != mp.end())
		return;
	mp[make_pair(pii(u,f),g)] = 1;
	dp[u] = max(dp[u],gcd(g,val[u]));
	if(!f) dp[u] = max(g,dp[u]);
	REP(i,tree[u])
	{
		int nxt = tree[u][i];
		if(nxt == pr)
			continue;
		if(!f)
		solve(nxt,1,g,u);
		solve(nxt,f,gcd(g,val[u]),u);
	}

}
int main()
{
	memset(dp,-1,sizeof(dp));

	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&val[i]);
	int u,v;
	for(int i = 0 ; i < n - 1 ; ++i)
	{
		scanf("%d %d",&u,&v);
		--u; --v;
		tree[u].pb(v);
		tree[v].pb(u);
	}
	solve(0,0,0,-1);
	for(int i = 0 ; i < n ; ++i)
		printf("%d ",dp[i]);
}
