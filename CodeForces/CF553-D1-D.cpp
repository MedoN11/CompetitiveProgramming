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
#include <unordered_map>
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
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define pb push_back
const int maxn = 100*1005;
bool bad[maxn];
vector<int> blocked;
vector<int> g[maxn];
bool seen[maxn];
int deg[maxn];
vector<int> good;
int n,m,k;
bool can(double mid)
{
	memset(bad,0,sizeof(bad));
	memset(deg,0,sizeof(deg));
	memset(seen,0,sizeof(seen));
	queue<int> q;
	for(int i = 0 ; i < n ; ++i) deg[i] = sz(g[i]);
	REP(i,blocked) q.push(blocked[i]);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(seen[u])
			continue;
		seen[u] = 1;
		REP(i,g[u])
		{
			int v = g[u][i];
			if(bad[v])
				continue;
			deg[v]--;
			if(double(deg[v] / (1.0*sz(g[v]))) < mid)
				q.push(v);
		}
	}
	good.clear();
	for(int i = 0 ; i < n ; ++i) if(!seen[i]) good.push_back(i);
	return sz(good) > 0;
}

int main()
{

	int u,v;
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0 ;i  < k ; ++i) scanf("%d",&u), --u,blocked.pb(u);
	for(int i = 0 ; i < m ; ++i)
		scanf("%d %d",&u,&v),--u,--v,g[u].pb(v),g[v].pb(u);


	double l = 0, r = 1.0;
	double ans = 0.0;




	for(int i = 0 ; i < 35 ; ++i)
	{

		double mid = (l + r) / 2.0;
		if(can(mid))
			l = mid,ans = mid;
		else r = mid;

	}
	can(ans);
	assert(sz(good) <= n - k);
	assert(sz(good) != 0);
	printf("%d\n",sz(good));
	REP(i,good) printf("%d ",good[i] + 1);


	return 0;



}
