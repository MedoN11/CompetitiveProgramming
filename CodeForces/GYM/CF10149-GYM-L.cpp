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
const int maxn = 2001;
int t,n,e;
vector<pii> g[maxn];
ll dp[maxn];
typedef pair<int,pii> edge;
vector<edge> edges;
const ll inf = 1LL << 52;
int main()
{
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d",&n,&e);
		int u,v,w;
		for(int i = 0 ; i < n ; ++i)
			g[i].clear(),dp[i] = 0;
		edges.clear();
		ll ans = inf;
		ll mn = inf;
		for(int i = 0 ; i < e ; ++i)
		{
			scanf("%d %d %d",&u,&v,&w); --u; --v;
			g[u].pb(pii(v,w));
			edges.pb(edge(w,pii(u,v)));
			mn = min(mn,1LL*w);
		}
		bool flag = 0;
		for(int i = 0 ; i < n + 1 ; ++i)
		{
			flag = 0;
			REP(j,edges)
			{
				int f = edges[j].second.first;
				int t = edges[j].second.second;
				int c = edges[j].first;
				if(1LL*dp[f] + 1LL*c < 1LL*dp[t])
					dp[t] = 1LL*dp[f] + 1LL*c,flag = 1;
			}


		}
		if(flag) puts("-inf");
		else
		{
			ll ans = inf;
			for(int i = 0 ; i < n ; ++i)
				ans = min(ans,dp[i]);
			if(ans >= 0)
				printf("%lld\n",mn);
			else printf("%lld\n",ans);
		}

	}
}
