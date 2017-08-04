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
int floyd[51][51];
const int inf = 1 << 30;
int t,n,m,q;
typedef pair<pii,int> edge;
vector<edge> g[55];
int dp[100005][52];
int sink;
bool onPath[2501];
int solve(int u,int rem)
{
	//cerr << u << " " << rem << "\n";
	if(rem < 0)
		return inf;
	if(u == sink)
	{
		if(rem == 0)
			return 0;
		else return inf;
	}
	if(dp[rem][u] != -1)
		return dp[rem][u];
	int &ret = dp[rem][u];
	ret = inf;
	REP(i,g[u])
	{
		if(onPath[g[u][i].second])
		ret = min(ret,1 + solve(g[u][i].first.first,rem - g[u][i].first.second));
	}
	return ret;
}
int main()
{

	scanf("%d",&t);
	int u,v,c;
	while(t--)
	{
		for(int i = 0 ; i < 51 ; ++i)
		{
			g[i].clear();
			for(int j = 0 ; j < 51 ; ++j)
			{
				if(i != j)
					floyd[i][j] = inf;
				else floyd[i][i] = 0;
			}
		}
		vector<edge> edges;
		scanf("%d %d",&n,&m);
		for(int i = 0 ; i < m ; ++i)
		{
			scanf("%d %d %d",&u,&v,&c); --u; --v;
			g[u].pb(make_pair(pii(v,c),i)); g[v].pb(edge(make_pair(pii(u,c),i))); floyd[u][v] = floyd[v][u] = c;
			edges.pb(edge(pii(u,v),c));

		}
		for(int k = 0 ; k < n ; ++k)
		{
			for(int i = 0 ; i < n ; ++i)
			{
				for(int j = 0 ; j < n ; ++j)
				{
					if(floyd[i][k] == inf || floyd[k][j] == inf)
						continue;
					floyd[i][j] = min(floyd[i][j] ,floyd[i][k] + floyd[k][j]);
				}
			}
		}
		int q;
		scanf("%d",&q);
		int w;
		while(q--)
		{
			scanf("%d %d %d",&u,&v,&w);
			--u; --v;
			sink = v;


			if(floyd[u][v] > w)
			{
				puts("No");

			}
			else
			{
				//cerr << "here" << "\n";
				memset(onPath,0,sizeof(onPath));
				memset(dp,-1,sizeof(dp));
				REP(i,edges)
				{
					int a = edges[i].first.first , b = edges[i].first.second, c = edges[i].second;
					if( (floyd[u][a] + c + floyd[b][v]  == floyd[u][v]) || (floyd[u][b] + c + floyd[a][v] == floyd[u][v]))
					{
						onPath[i] = 1;
					}
				}

				int ans = 0;
				if((ans = solve(u,w)) == inf)
					puts("No");
				else
					printf("Yes %d\n",ans);
			}
		}
		if(t) puts("");


	}

}

