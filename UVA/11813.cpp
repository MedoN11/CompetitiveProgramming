#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <unordered_map>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define ll  long long
#define EPS (1e-8);
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define neg(x) memset(x,-1,sizeof(x));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define endl "\n"
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;
#define MAXN 100001
ll D[15][15];
ll DP[1 << 11][11];
vector<vector<pair<int,int> > > g(MAXN);
int n,m;
int s;
map<int,int> st;
ll INF = 1LL << 59;
ll DIS[MAXN];
void diji(int src)
{
	for(int i = 0 ; i < n ; ++i)
		DIS[i] = INF;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
	pq.push(make_pair(0,src));
	while(!pq.empty())
	{
		pair<ll,int> o = pq.top(); pq.pop();
		int u = o.second; ll dis = o.first;
		if(DIS[u] < dis) continue;
		if(st.find(u) != st.end())
			D[st[src]][st[u]] = dis;
		DIS[u] = dis;
		REP(j,g[u])
		{
			pair<int,int> e = g[u][j]; int v = e.first; ll c = 1LL*e.second;
			if(1LL*DIS[u] + c  < DIS[v])
			{
				DIS[v] = (long long)(1LL*DIS[u] + c);
				pq.push(make_pair(DIS[v],v));
			}
		}
	}

}
ll solve(int msk,int idx)
{
	if(__builtin_popcount(msk) == s)
		return D[idx][0];
	ll &ret = DP[msk][idx];
	if(ret != -1)
		return ret;
	ret = INF;
	for(int i = 0 ; i < s ; ++i)
	{
		if((msk & (1 << i)) > 0)
			continue;
		ret = min(ret,D[idx][i] + solve(msk | 1 << i,i));
	}
	return ret;
}
int main()
{

	int t;
	scanf("%d",&t);

	int u,v,d;
	while(t--)
	{
		memset(D,0,sizeof(D));
		st.clear();
		scanf("%d %d",&n,&m);
		for(int i = 0 ; i < n ; ++i)
			g[i].clear();
		for(int j = 0 ; j < m ; ++j)
		{
			scanf("%d %d %d",&u,&v,&d);
			g[u].push_back(make_pair(v,d));
			g[v].push_back(make_pair(u,d));
		}
		scanf("%d",&s);
		int id = 0;
		vector<int> v; v.push_back(0); st[0] = id++;
		for(int i = 0 ; i < s ; ++i)
		{
			scanf("%d",&u);
			st[u] = id++;
			v.push_back(u);
		}
		REP(i,v)
		{
			u = v[i];
			diji(u);
		}

		s = v.size();
		memset(DP,-1,sizeof(DP));
		printf("%lld\n",solve(1,0));


	}

}
