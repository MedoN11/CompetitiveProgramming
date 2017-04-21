#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
using namespace std;
#define ll long long
typedef long double ld;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define clr(x) memset(x,0,sizeof(x));
typedef vector<int> vi;
#include <iostream>
#include <cmath>
#include <complex>
#include <cassert>
using namespace std;
vector<int> tree[105];
int need[105];
int die[105];
int stay[105];
int n;
int inf = 1 << 29;
bool seen[105];
typedef pair<int,int> ii;
ii dfs(int u,int p)
{

	vector<pair<ii,int> > dec;
	int mx = need[u];
	int sum = stay[u] + die[u];
	REP(i,tree[u])
	{
		int v = tree[u][i];
		if(v == p)
			continue;
		pair<int,int> x = dfs(v,u);
		x.first *= -1;
		dec.push_back(make_pair(x,u));
	}
	sort(dec.begin(),dec.end());
	REP(i,dec)
	{
		mx = max(mx,sum + -dec[i].first.first);
		sum += dec[i].first.second;
	}

	return make_pair(max(mx,sum),sum);
}
int main()
{

	int tc = 1;
	while(scanf("%d",&n))
	{
		if(!n)
			break;

		for(int i = 0 ; i < n ; ++i)
		{
			tree[i].clear();
			scanf("%d %d %d",&need[i],&die[i],&stay[i]);
		}
		int u,v;
		for(int i = 0 ; i < n - 1 ; ++i)
		{
			scanf("%d %d",&u,&v);
			--u; --v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		pair<int,int> ans = make_pair(inf,inf);
		for(int i = 0 ; i < n ; ++i)
			ans = min(ans,dfs(i,-1));

		printf("Case %d: %d\n",tc++,ans.first);
	}

}

